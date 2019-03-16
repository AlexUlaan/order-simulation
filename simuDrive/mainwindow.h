#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QSound>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void testShow();
    void testDim();

private:
    Ui::MainWindow *ui;
    QPushButton *accept, *refuse;
    QLabel *map;
    int transp;
    int timerID;
    bool isDim;
    QPixmap mappix, mapshow;
    void timerEvent(QTimerEvent *event);
    QTimer *dimTimer, *showTimer;
    QSound *player;
};


#endif // MAINWINDOW_H
