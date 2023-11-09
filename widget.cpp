#include "widget.h"
#include "ui_widget.h"
#include "QStyle"
#include "QFileDialog"
#include "QDir"
#include "QTime"
#include "QMediaContent"


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
    ui->tablePlayList -> setModel(m_playlist_model);    // связываем таблицу с моделью
    m_playlist_model -> setHorizontalHeaderLabels(QStringList() <<tr("Audio track") << tr("File paht"));//подписываем заголовки таблицы

    ui->tablePlayList->hideColumn(1);   // скрываем  2 столбец с адресом файла(начиниется с 0)
    ui->tablePlayList->horizontalHeader()->setStretchLastSection(true);//растягиваем отображаемый столбец на всю ширину окна
    m_playlist = new QMediaPlaylist(m_player);
    m_player-> setPlaylist(m_playlist);
    ui-> tablePlayList->setEditTriggers(QAbstractItemView::NoEditTriggers); //запрещаем редактирование ячеек таблицы
    ui-> tablePlayList -> setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablePlayList->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);


    connect(ui->tablePlayList, &QTableView::doubleClicked,
            [this](const QModelIndex& index) {m_playlist-> setCurrentIndex(index.row());m_player->play();});
    connect(m_playlist, &QMediaPlaylist::currentIndexChanged,
            [this](int index)
        {
           ui-> labelComposition->setText(m_playlist_model->data(m_playlist_model->index(index, 0)).toString());
           this->setWindowTitle("Media Player - " + ui->labelComposition->text());
           ui->tablePlayList->selectRow(index);
        }
    );

    ///////////////////////  Load plqylist ////////////////////////
    /*m_playlist -> load(QUrl::fromLocalFile("D:\\resors\\Qt\\playlist.m3u"),"m3u");
    for (int i = 0; i < m_playlist->mediaCount(); i++ )
    {
        QMediaContent content = m_playlist->media(i);
        QString url = content.canonicalUrl().url();
        QList<QStandardItem*> items;
        items.append(new QStandardItem(QDir(url).dirName()));
        items.append(new QStandardItem(url));
        m_playlist_model->appendRow(items);
    }*/
    load_playlist(DEFAULT_PLAYLIST);
}

Widget::~Widget()
{
    //m_playlist->save(QUrl::fromLocalFile(DEFAULT_PLAYLIST), QString(DEFAULT_PLAYLIST).split('.').back().toStdString().c_str());
    delete this -> m_playlist_model;
    delete this -> m_playlist;
    delete this -> m_player;
    delete ui;

}

 void Widget::load_playlist (QString filename)
 {
     QString format = filename.split('.').back();
     m_playlist -> load(QUrl::fromLocalFile(filename),format.toStdString().c_str());
     for (int i = 0; i < m_playlist->mediaCount(); i++ )
     {
         QMediaContent content = m_playlist->media(i);
         QString url = content.canonicalUrl().url();
         QList<QStandardItem*> items;
         items.append(new QStandardItem(QDir(url).dirName()));
         items.append(new QStandardItem(url));
         m_playlist_model->appendRow(items);
     }
 }

 void Widget::save_playlist(QString filename)
 {
     QString format = filename.split('.').back();
     m_playlist->save(QUrl::fromLocalFile(filename),format.toStdString().c_str());
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
                QString ("D:\\Musik"),
                tr("Audio files (*.mp3 *.flac);; mp-3(*.mp3);; Flac(*.flac);;Playlist(*.m3u)")
            );
    QString format = files.back().split('.').back();
    if (format == "m3u")
    {
        load_playlist(files.back());
        return;
    }
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

void Widget::on_pushButtonPrev_clicked()
{
    m_playlist->previous();
}

void Widget::on_pushButtonNext_clicked()
{
    m_playlist->next();
}

void Widget::on_pushButtonClear_clicked()
{
    m_playlist->clear();
    m_playlist_model->clear();
    ui->labelComposition->setText("Erased");
}


void Widget::on_pushButtonRem_clicked()
{
//    QModelIndexList list = ui->tablePlayList->;
//    for (QModelIndex i: list)
//    {
//        m_playlist -> removeMedia(i.row());
//    }
    QItemSelectionModel* selection = ui->tablePlayList->selectionModel();
    QModelIndexList rows = selection->selectedRows();
    for (QModelIndexList::iterator it = rows.begin(); it!= rows.end(); ++it)
    {
        if(m_playlist -> removeMedia(it->row()))
        m_playlist_model ->removeRows(it -> row(),1);
    }

}


