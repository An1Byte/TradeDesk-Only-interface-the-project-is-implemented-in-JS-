#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>

// Функция задержки для временной заставки:
void loadModules(QSplashScreen * psplash){
    QTime time;
    time.start();

    for(int i(0); i < 100;){
        if(time.elapsed() > 40){
            time.start();
            ++i;
        }
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QSplashScreen splash(QPixmap(":/startImage/startImage/protaas1.png"));
    MainWindow w;
    //splash.show();
    //loadModules(&splash);
    //splash.finish(&w);
    w.show();

    return a.exec();
}
