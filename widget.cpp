#include "widget.h"
#include "ui_widget.h"
#include "QStyle"
#include "QFileDialog"
#include "QDir"
#include "QTime"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButtonPrev ->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    ui->pushButtonPlay -> setIcon(style()-> standardIcon(QStyle::SP_MediaPlay));
    ui->pushButtonPause -> setIcon(style()-> standardIcon(QStyle::SP_MediaPause));
    ui->pushButtonStop -> setIcon(style() -> standardIcon(QStyle::SP_MediaStop));
    ui->pushButtonNext -> setIcon(style()-> standardIcon(QStyle::SP_MediaSkipForward));
    ui->pushButtonAdd -> setIcon(style()-> standardIcon(QStyle::SP_DriveDVDIcon));
    ui->pushButtonMute-> setIcon(style()-> standardIcon(QStyle::SP_MediaVolume));
    this->muted= false;
    ui->horizontalSliderProgress->setTickPosition(QSlider::TicksBelow);

    m_player = new QMediaPlayer(this);
    m_player -> setVolume(70);
    ui-> labelVolume -> setText(QString("Volume").append(QString::number(m_player->volume())));
    ui->HorSliderVolume -> setValue(m_player->volume());
    //on_HorSliderVolume_valueChanged(70);

    connect(m_player, &QMediaPlayer::durationChanged, this, &Widget::on_duration_changed);
    connect(m_player, &QMediaPlayer::positionChanged, this, &Widget::on_position_changed);

    ///////////////////////play list///////////////////
    m_playlist_model = new QStandardItemModel(this);
    ui->tablePlayList -> setModel(m_playlist_model);
    m_playlist_model -> setHorizontalHeaderLabels(QStringList() <<tr("Audio track") << tr("File paht"));
    m_playlist = new QMediaPlaylist(m_player);
    m_player-> setPlaylist(m_playlist);
    ui-> tablePlayList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->tablePlayList, &QTableView::doubleClicked,
            [this](const QModelIndex& index) {m_playlist-> setCurrentIndex(index.row());});
    connect(m_playlist, &QMediaPlaylist::currentIndexChanged,
            [this](int index)
        {
            ui-> labelComposition->setText(m_playlist_model->data(m_playlist_model->index(index, 0)).toString());

        }
    );
}


Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonAdd_clicked()
{
//    QString file = QFileDialog::getOpenFileName
//            (this, tr("Open file"),
//            QString("D:\\музыка"),
//             tr("Audio files (*.mp3 *.flac);; mp-3 (*.mp3);; flac(*.flac)"));
//    ui->labelComposition->setText(file);
//    m_player->setMedia(QUrl::fromLocalFile(file));
//    m_player->play();

//    //QString composition = *file.split('/').rbegin();
//    //this->setWindowTitle("Media player - " + composition);
//    this->setWindowTitle("Media player - " + file.split('/').back());
    QStringList files = QFileDialog::getOpenFileNames(
                this,
                tr("Open files"),
                QString ("D:\\музыка"),
                tr("Audio files (*.mp3 *.flac);; mp-3(*.mp3);; Flac(*.flac)")
            );
    for (QString filesPaht: files)
    {
        //1) создаем строку: каждая строка таблицы labelPlayList
        //  - это список страндарных вхождений
        QList<QStandardItem*>items;
        items.append(new QStandardItem(QDir(filesPaht).dirName()));
        items.append(new QStandardItem(filesPaht));
        m_playlist_model->appendRow(items);
        m_playlist->addMedia(QUrl(filesPaht));
    }
}

void Widget::on_HorSliderVolume_valueChanged(int value)
{
    ui -> labelVolume -> setText(QString("Volume: ").append(QString::number(value)));
    m_player-> setVolume(value);
}

void Widget::on_pushButtonPlay_clicked()
{
    m_player-> play();
}

void Widget::on_pushButtonPause_clicked()
{
    m_player->pause();
}

void Widget::on_pushButtonStop_clicked()
{
    m_player->stop();
}

void Widget::on_position_changed(qint64 position)
{
    ui->horizontalSliderProgress->setValue(position);
    QTime qt_position = QTime::fromMSecsSinceStartOfDay(position);
    ui->labelPlayer->setText(QString ("Player: ").append(qt_position.toString("mm:ss")));
}

void Widget::on_duration_changed(qint64 duration)
{
    ui->horizontalSliderProgress->setMaximum(duration);
    QTime qt_duration = QTime::fromMSecsSinceStartOfDay(duration);
    ui->labelDuration->setText(QString("Duration: ").append(qt_duration.toString("mm:ss")));
}

void Widget::on_horizontalSliderProgress_valueChanged(qint64 position)
{
    m_player->setPosition(position);
}


void Widget::on_pushButtonMute_clicked()
{
    muted = !muted;
    m_player->setMuted(muted);
    ui->pushButtonMute-> setIcon(style() ->standardIcon(muted ? QStyle::SP_MediaVolumeMuted : QStyle::SP_MediaVolume));
}

