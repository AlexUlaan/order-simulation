#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"
#include <QBitmap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPixmap bgpix("assets:/background.png");
    QPixmap pix("assets:/accept.png");
    mappix.load("assets:/map.png");
    player = new QSound(NULL, this);
    map = new QLabel(this);
    accept = new QPushButton(this);
    dimTimer = new QTimer(this);
    showTimer = new QTimer(this);

    ui->setupUi(this);

    bgpix = bgpix.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette bgPalette;
    bgPalette.setBrush(QPalette::Background, bgpix);
    this->setPalette(bgPalette);


    accept->setGeometry(152, 625, 127, 127);
    pix = pix.scaled(accept->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    accept->setMask(pix.mask());
    accept->setIcon(pix);
    accept->setIconSize(QSize(127, 127));
    accept->setStyleSheet("QPushButton{border:none;}");
    connect(accept, &QPushButton::pressed, this, &MainWindow::testShow);

    isDim = true;    transp = 255;
    mappix = mappix.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    map->setGeometry(0, 0, 432, 768);
    mapshow = setTransp(mappix, 255);
    map->setPixmap(mapshow);

    dimTimer->singleShot(3000, this, &MainWindow::testDim);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testShow()
{
    isDim = false;
    map->setVisible(true);
    timerID = this->startTimer(1);
    showTimer->stop();
}

void MainWindow::testDim()
{
    showTimer->singleShot(15000, this, &MainWindow::testShow);
    isDim = true;
    timerID = this->startTimer(1);
    dimTimer->singleShot(18000, this, &MainWindow::testDim);
    player->play("assets:/order.wav");
}

void MainWindow::timerEvent(QTimerEvent *event)
{
        if(isDim == true)
        {
            if(transp == 0){
                this->killTimer(timerID);
                map->setVisible(false);
            }
            else{
                transp-=5;
                mapshow = setTransp(mappix, transp);
                map->setPixmap(mapshow);
            }
        }
        else{
            if(transp == 255){
                this->killTimer(timerID);
            }
            else{
                transp+=5;
                mapshow = setTransp(mappix, transp);
                map->setPixmap(mapshow);
            }
        }
}
