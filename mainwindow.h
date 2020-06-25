#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSound>
#include <QDateTime>
#include <QLabel>
#include <QFile>
#include <QPointer>
#if WIN32
#include <Windows.h>
#endif
#include <QDebug>
#include <QTimer>

#include "buildsyntheticchart.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private: /*private functions:*/
    void WINAPI_getTaskBarHeight();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void actionsDistrubutor(int);

private:
    Ui::MainWindow *ui;

    QSound *sound, *soundError;

    QLabel * status;

    QPixmap * pixmap;
    QPalette * pallete;

    QAction * actList[30]; // Список экшенов.
    QAction * separatorsList[6]; // Список разделителей.

    buildSyntheticChart * __buildSyntheticChart;
    QTimer * timer;

public slots:
    void mainToolBar_Slot(QAction * action);
    void timer_Slot();
    void status_Slot(QString);
};

#endif // MAINWINDOW_H
