#include "mainwindow.h"
#include "ui_mainwindow.h"

//################### WINAPI FUNCTIONS #######################
void MainWindow::WINAPI_getTaskBarHeight(){
    RECT rect;
    HWND taskBar = FindWindow(L"Shell_traywnd", Q_NULLPTR);
    int hTaskbar = (taskBar && GetWindowRect(taskBar, &rect)) ? (rect.bottom - rect.top) : 0; // Получаем высоту панели задач (меню Пуск).

    BOOL fResult;
    RECT rectAvalableArea; // Переменная в которой будет храниться значения площади доступной области экрана.
    fResult = SystemParametersInfoA(SPI_GETWORKAREA, 0, &rectAvalableArea, 0);
    setGeometry(0, 0, (rectAvalableArea.right-rectAvalableArea.left)*0.75, rectAvalableArea.bottom - rectAvalableArea.top - hTaskbar);
}
//############################################################

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCursor(QCursor(QPixmap(":/icons/IconsForProgramm/arr.png")));

#if WIN32
    WINAPI_getTaskBarHeight(); // WINAPI Открываем программу во весь экран без учета пусковой области.
#else
    setGeometry(0, 0, 600, 400);
#endif

    setWindowTitle("PROTAAS - Professional trading and analytical space");

    // Инициализация фона:
    pixmap = new QPixmap(":/background/bcground/bg.jpg");
    pixmap->scaled(this->size(), Qt::IgnoreAspectRatio);
    pallete = new QPalette;
    pallete->setBrush(QPalette::Background, *pixmap);
    setPalette(*pallete);
    timer = new QTimer(this);

    //Инициализация стилей(Загрузка и применение css файла):
    QFile file("F:/MyProjects/QtCreator/TradeDesk/css/cssStyles.css");
    file.open(QIODevice::ReadOnly);
    QString _sstyleSheet;
    _sstyleSheet = file.readAll();
    file.close();
    setStyleSheet(_sstyleSheet);

    ui->mainToolBar->setContextMenuPolicy(Qt::PreventContextMenu);

    // Инициализация actions:
    actList[0] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/Connect.png").scaled(40,40)), QString("Connect"), this);
    actList[1] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/download.png").scaled(40,40)), QString("Download bins"), this);
    // Separator #0
    actList[2] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/news.png").scaled(40,40)), QString("News"), this);
    actList[3] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/chat.png").scaled(40,40)), QString("Chat"), this);
    actList[4] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/alarm.png").scaled(40,40)), QString("Alarms"), this);
    actList[5] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/parser.png").scaled(40,40)), QString("Parser"), this);
    actList[6] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/volume.png").scaled(40,40)), QString("Volume"), this);
    actList[7] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/opt.png").scaled(40,40)), QString("Options"), this);
    actList[8] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/sintetic.png").scaled(40,40)), QString("Build a synthetic chart"), this);
    actList[9] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/other.png").scaled(40,40)), QString("Other"), this);
    // Separator #1
    actList[10] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/candle.png").scaled(40,40)), QString("candleView"), this);
    actList[11] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/bar.png").scaled(40,40)), QString("barView"));
    actList[12] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/volumeCandle.png").scaled(40,40)), QString("candleVolumeView"), this);
    actList[13] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/volumeBar.png").scaled(40,40)), QString("barVolumeView"), this);
    actList[14] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/barnew.png").scaled(40,40)), QString("VolumeView"), this);
    // Separator #2
    actList[15] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/arrow.png").scaled(40,40)), QString("Arrow"), this);
    actList[16] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/Perecrestie.png").scaled(40,40)), QString("Grab"), this);
    actList[17] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/vline.png").scaled(40,40)), QString("Verticale line"), this);
    actList[18] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/line.png").scaled(40,40)), QString("Line"), this);
    actList[19] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/hline.png").scaled(40,40)), QString("Horizontale line"), this);
    actList[20] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/text.png").scaled(40,40)), QString("Text"), this);
    // Separator #3
    actList[21] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/m1.png").scaled(40,40)), QString("m1"), this);
    actList[22] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/m5.png").scaled(40,40)), QString("m5"), this);
    actList[23] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/m15.png").scaled(40,40)), QString("m15"), this);
    actList[24] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/h1.png").scaled(40,40)), QString("h1"), this);
    actList[25] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/h4.png").scaled(40,40)), QString("h4"), this);
    actList[26] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/d1.png").scaled(40,40)), QString("d1"), this);
    // Separator #4
    actList[27] = new QAction(QIcon(QPixmap(":/icons/IconsForProgramm/online.png").scaled(40,40)), QString("Online"), this);
    // Separator #5

    for(int i(0), j(0); i < 28; ++i){
        ui->mainToolBar->addAction(actList[i]);
        if(i == 1 || i == 9 || i == 14 || i == 20 || i == 26 || i == 27){
            separatorsList[j] = ui->mainToolBar->addSeparator();
            j++;
        }
    }
    for(int i(10); i < 28; ++i){ actList[i]->setVisible(false); } // Делаем недоступный экшены невидимыми.
    for(int i(1); i < 6; ++i){ separatorsList[i]->setVisible(false); } // Убираем лишние разделители.



    // Инициализция звуков:
    sound = new QSound(":/mysounds/sounds/sound.wav", this);
    soundError = new QSound(":/mysounds/sounds/error.wav", this);


    // Первородные настройки для qtoolBar:
    status = new QLabel("Status: ", this);
    status->setText("<span style=\"color: white; border-color:black;\">Connection status:    </span><span style=\"color: red; border-color:black;\">Disconnected     </span>");

    ui->mainToolBar->setMovable(false); // Запрещаем перемещение toolBar.

    ui->statusBar->addPermanentWidget(status); // Выравнивание lable по правому краю.
    ui->statusBar->showMessage("The application is running. For further work, you need to connect to the server by clicking on the yellow key in the upper left corner of the terminal ...");



    // Коннекты:
    connect(ui->mainToolBar, &QToolBar::actionTriggered, this, &MainWindow::mainToolBar_Slot);
}

void MainWindow::mainToolBar_Slot(QAction * action)
{
    if(action->text() == "Build a synthetic chart"){
        __buildSyntheticChart = new buildSyntheticChart(this, this->width());
        setCentralWidget(__buildSyntheticChart);

        // Добавить разделители и экшены.
        sound->play();
        connect(__buildSyntheticChart, SIGNAL(statusEvent(QString)), this, SLOT(status_Slot(QString)));
    }
    else{
        soundError->play();
        ui->statusBar->showMessage("This action is in development status and will be available in future releases of the program...");
        if(timer->isActive()){
            timer->stop();
            timer->start(5000);
        }
        else{
            timer->start(5000);
        }
        connect(timer, SIGNAL(timeout()), SLOT(timer_Slot()));
    }
    //...

}

void MainWindow::timer_Slot(){
    timer->stop();
    ui->statusBar->showMessage("The application is running. For further work, you need to connect to the server by clicking on the yellow key in the upper left corner of the terminal ...");
    if(timer->isActive()){
        timer->stop();
        timer->start(5000);
    }
    else{
        timer->start(5000);
    }
    connect(timer, SIGNAL(timeout()), SLOT(timer_Slot()));
}

void MainWindow::status_Slot(QString str)
{
    ui->statusBar->showMessage(str);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actionsDistrubutor(int indexAction){

}
