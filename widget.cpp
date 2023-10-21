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
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonAdd_clicked()
{
    QString file = QFileDialog::getOpenFileName
            (this, tr("Open file"),
             QString("D:\\музыка"),
             tr("Audio files (*.mp3 *.flac);; mp-3 (*.mp3);; flac(*.flac)"));
    ui->labelComposition->setText(file);
    m_player->setMedia(QUrl::fromLocalFile(file));
    m_player->play();

    //QString composition = *file.split('/').rbegin();
    //this->setWindowTitle("Media player - " + composition);
    this->setWindowTitle("Media player - " + file.split('/').back());
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

