#include "buildsyntheticchart.h"
#include <QDebug>

buildSyntheticChart::buildSyntheticChart(QWidget * pwgt, int ii) : QWidget(pwgt), listWidth(ii){
    gridLayout = new QGridLayout(this);
    buildSintheticChart = new QPushButton("Построение синтетического инструмента по двум инструментам...");
    buildMultiCharts = new QPushButton("Построение мультиграфика...");
    __Find = new QPushButton("Поиск инструментов, удовлетворяющие фильтру...");

    buildSintheticChart->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    buildMultiCharts->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    __Find->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    gridLayout->addWidget(buildSintheticChart, 0, 0);
    gridLayout->addWidget(buildMultiCharts, 1, 0);
    gridLayout->addWidget(__Find, 0, 1, 2, 1);
    gridLayout->setContentsMargins(0,0,0,0);

    buildMultiCharts->setMinimumSize(QSize(400, 300));
    buildSintheticChart->setMinimumSize(QSize(400, 300));
    __Find->setMinimumSize(QSize(400, 600));
    buildMultiCharts->setMaximumSize(QSize(400, 300));
    buildSintheticChart->setMaximumSize(QSize(400, 300));
    __Find->setMaximumSize(QSize(400, 600));

    buildSintheticChart->setStyleSheet("QPushButton{border: none; background-image: url(:/buttons/buttons/synteticButton.png); color: argb(100, 0, 0, 0); text-align: bottom;}"
                                       "QPushButton::hover{border: none; background-image: url(:/buttons/buttons/synteticButton2.png); color: green; text-align: bottom; font: bold;}"
                                       );
    buildMultiCharts->setStyleSheet("QPushButton{border: none; background-image: url(:/buttons/buttons/multichartButton.png); color: argb(100, 0, 0, 0); text-align: bottom;}"
                                    "QPushButton::hover{border: none; background-image: url(:/buttons/buttons/multichartButton2.png); color: green; text-align: bottom; font: bold;}"
                                    );
    __Find->setStyleSheet("QPushButton{border: none; background-image: url(:/buttons/buttons/searchButton.png); color: argb(100, 0, 0, 0); text-align: bottom;}"
                          "QPushButton::hover{border: none; background-image: url(:/buttons/buttons/searchButton2.png); color: green; text-align: bottom; font: bold;}"
                          );

    connect(buildSintheticChart, SIGNAL(clicked()), SLOT(buildSintheticChart_Slot()));
    connect(buildMultiCharts, SIGNAL(clicked()), SLOT(buildMultiCharts_Slot()));
    connect(__Find, SIGNAL(clicked()), SLOT(__Find_Slot()));
}

void buildSyntheticChart::buildSintheticChart_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
    addButton1 = new QPushButton("O\n\nF\n\nF\n\nL\n\nI\n\nN\n\nE");
    addButton2 = new QPushButton("O\n\nN\n\nL\n\nI\n\nN\n\nE");
    describtionChange = new QLabel("<i style=\"color:white;\"><center>Потом тут будет текст - описание нижеописанного функционала......</center></i>");
    addButton1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    addButton2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    gridLayout->removeWidget(buildSintheticChart);
    gridLayout->removeWidget(buildMultiCharts);
    gridLayout->removeWidget(__Find);
    buildMultiCharts->hide();
    buildSintheticChart->hide();
    __Find->hide();


    addButton1->setStyleSheet("QPushButton{border:none; color: blue; background-color: argb(100, 0, 0, 0); font: bold 36px; text-align: center;}"
                              "QPushButton:hover{border:none; color: yellow; background-color: argb(100, 0, 0, 0); font: bold 36px; text-align: center;}"
                              );
    addButton2->setStyleSheet("QPushButton{border:none; color: blue; background-color: argb(100, 0, 0, 0); font: bold 36px; text-align: center;}"
                              "QPushButton:hover{border:none; color: yellow; background-color: argb(100, 0, 0, 0); font: bold 36px; text-align: center;}"
                              );


    gridLayout->addWidget(describtionChange, 0, 0, 1, 2);
    gridLayout->addWidget(addButton1, 1, 0, 1, 1);
    gridLayout->addWidget(addButton2, 1, 1, 1, 1);
    connect(addButton1, SIGNAL(clicked()), SLOT(addButton1_Slot()));
    connect(addButton2, SIGNAL(clicked()), SLOT(addButton2_Slot()));
}

void buildSyntheticChart::buildMultiCharts_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
    ask1 = new QPushButton("?");
    ask2 = new QPushButton("?");
    QStandardItemModel * model1 = new QStandardItemModel;
    QStandardItemModel * model2 = new QStandardItemModel;
    QHeaderView * hView1 = new QHeaderView(Qt::Horizontal);
    QHeaderView * hView2 = new QHeaderView(Qt::Horizontal);
    instrumentsList1 = new QTreeWidget;
    instrumentsList2 = new QTreeWidget;
    lbl1 = new QLabel("<b>List istrument:</b>");
    lbl2 = new QLabel("<b>Added list instrument:</b>");
    mt4 = new QPushButton("mt4");
    mt5 = new QPushButton("mt5");
    quik = new QPushButton("quik");
    ninja = new QPushButton("nj");
    select = new QPushButton("SELECT");
    describtion = new QLabel("<i style=\"color:white;\"><center>Потом тут будет текст - описание нижеописанного функционала......</center></i>");

    model1->setHorizontalHeaderLabels(QStringList()<<"Symbol"<<"Bid"<<"Ask");
    model2->setHorizontalHeaderLabels(QStringList()<<"Symbol");

    hView1->setModel(model1);
    hView2->setModel(model2);

    instrumentsList1->setHeader(hView1);
    instrumentsList2->setHeader(hView2);

    mt4->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    mt5->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    quik->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    ninja->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    select->setStyleSheet("QPushButton{background-color: red; color: white; font: bold;} QPushButton:hover{background-color: darkred; color: white; font: bold;}");
    instrumentsList1->setStyleSheet("QTreeWidget{background-color: argb(100, 0, 0, 0); color: white; }");
    instrumentsList2->setStyleSheet("QTreeWidget{background-color: argb(100, 0, 0, 0); color: white;}");
    hView1->setStyleSheet("QHeaderView {background-color: argb(100, 0, 0, 0); color: white;}"
                          "QHeaderView::section {background-color: argb(100, 0, 0, 0); color: white;}"
                          );
    hView2->setStyleSheet("QHeaderView {background-color: argb(100, 0, 0, 0); color: white;}"
                          "QHeaderView::section {background-color: argb(100, 0, 0, 0); color: white;}"
                          );

    select->setMaximumHeight(25);
    ask1->setMaximumSize(QSize(30, 30));
    ask2->setMaximumSize(QSize(30, 30));
    mt4->setMaximumSize(QSize(30, 30));
    mt5->setMaximumSize(QSize(30, 30));
    quik->setMaximumSize(QSize(30, 30));
    ninja->setMaximumSize(QSize(30, 30));

    ask1->setToolTip("What this ?");
    ask2->setToolTip("What this ?");
    mt4->setToolTip("Download datas from mt4");
    mt5->setToolTip("Download datas from mt5");
    quik->setToolTip("Download datas from quik");
    ninja->setToolTip("Download datas from ninja");
    ask1->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    ask2->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");

    describtion->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    lbl1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ask1->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    instrumentsList1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    lbl2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ask2->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    instrumentsList2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    gridLayout->removeWidget(buildSintheticChart);
    gridLayout->removeWidget(buildMultiCharts);
    gridLayout->removeWidget(__Find);
    buildSintheticChart->hide();
    buildMultiCharts->hide();
    __Find->hide();

    gridLayout->addWidget(describtion, 0, 0, 1, 12);
    gridLayout->addWidget(ask1, 1, 0, 1, 1);
    gridLayout->addWidget(mt4, 1, 1, 1, 1);
    gridLayout->addWidget(mt5, 1, 2, 1, 1);
    gridLayout->addWidget(quik, 1, 3, 1, 1);
    gridLayout->addWidget(ninja, 1, 4, 1, 1);
    gridLayout->addWidget(lbl1, 1, 5, 1, 1);
    gridLayout->addWidget(ask2, 1, 6, 1, 1);
    gridLayout->addWidget(lbl2, 1, 7, 1, 5);
    gridLayout->addWidget(instrumentsList1, 2, 0, 2, 6); // connect
    gridLayout->addWidget(instrumentsList2, 2, 6, 1, 6); // connect
    gridLayout->addWidget(select, 3, 6, 1, 6);

    gridLayout->setColumnMinimumWidth(0, 35);
    gridLayout->setColumnMinimumWidth(1, 35);
    gridLayout->setColumnMinimumWidth(2, 35);
    gridLayout->setColumnMinimumWidth(3, 35);
    gridLayout->setColumnMinimumWidth(4, 35);
    gridLayout->setColumnMinimumWidth(6, 35);
    gridLayout->setRowMinimumHeight(1, 35);


    connect(ask1, SIGNAL(clicked()), SLOT(ask1_Slot()));
    connect(ask2, SIGNAL(clicked()), SLOT(ask2_Slot()));
    connect(mt4, SIGNAL(clicked()), SLOT(mt4_Slot()));
    connect(mt5, SIGNAL(clicked()), SLOT(mt5_Slot()));
    connect(quik, SIGNAL(clicked()), SLOT(quik_Slot()));
    connect(ninja, SIGNAL(clicked()), SLOT(ninja_Slot()));
    connect(select, SIGNAL(clicked()), SLOT(select_Slot()));
}

void buildSyntheticChart::__Find_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
    gridLayout->removeWidget(buildSintheticChart);
    gridLayout->removeWidget(buildMultiCharts);
    gridLayout->removeWidget(__Find);
    buildSintheticChart->hide();
    buildMultiCharts->hide();
    __Find->hide();

    ask3 = new QPushButton("?");
    QStandardItemModel * model1 = new QStandardItemModel;
    QHeaderView * hView1 = new QHeaderView(Qt::Horizontal);
    instrumentsList1 = new QTreeWidget;
    lbl1 = new QLabel("<b>List istrument:</b>");
    mt4 = new QPushButton("mt4");
    mt5 = new QPushButton("mt5");
    quik = new QPushButton("quik");
    ninja = new QPushButton("nj");
    describtion = new QLabel("<i style=\"color:white;\"><center>Потом тут будет текст - описание нижеописанного функционала......</center></i>");
    gip = new QPushButton;
    trend = new QPushButton;
    correlList = new QPushButton;
    lpAny = new QPushButton;
    lpNone = new QPushButton;
    lp3 = new QPushButton;
    absorptionCandle = new QPushButton;
    molotCandle = new QPushButton;
    starCandle = new QPushButton;
    changeTrend = new QPushButton;
    flet = new QPushButton;
    flags = new QPushButton;
    filtr = new QLabel("<i style=\"font: 20px; color: red;\"><center>SELECT THE FILTER:</center></i>");
    reset = new QPushButton("Reset filter");

    ask3->setMaximumSize(QSize(30, 30));
    mt4->setMaximumSize(QSize(30, 30));
    mt5->setMaximumSize(QSize(30, 30));
    quik->setMaximumSize(QSize(30, 30));
    ninja->setMaximumSize(QSize(30, 30));

    ask3->setToolTip("What this ?");
    mt4->setToolTip("Download datas from mt4");
    mt5->setToolTip("Download datas from mt5");
    quik->setToolTip("Download datas from quik");
    ninja->setToolTip("Download datas from ninja");
    gip->setToolTip("Поиск инструментов сформировавшие паттерн ГиП");
    trend->setToolTip("Поиск трендовых инструментов");
    correlList->setToolTip("Поиск коррелируемых инструментов");
    lpAny->setToolTip("Поиск любого ложного пробоя");
    lpNone->setToolTip("Поиск качественного ложного пробоя");
    lp3->setToolTip("ЛП - косание");
    absorptionCandle->setToolTip("Поиск свечного паттерна поглащения");
    molotCandle->setToolTip("Поиск свечного паттерна молот");
    starCandle->setToolTip("Поиск свечного паттерна звезда");
    changeTrend->setToolTip("Поиск инструментов склонных к смене тренда");
    flet->setToolTip("Поиск инструментов пребывающих во флете");
    flags->setToolTip("Поиск инструментов пребывающих в консолидации");

    model1->setHorizontalHeaderLabels(QStringList()<<"Symbol"<<"Bid"<<"Ask");

    hView1->setModel(model1);

    instrumentsList1->setHeader(hView1);

    gip->setStyleSheet("QPushButton{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/gip.png);}"
                       "QPushButton:hover{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/gip2.png);}");
    trend->setStyleSheet("QPushButton{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/trend.png);}"
                         "QPushButton:hover{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/trend2.png);}");
    correlList->setStyleSheet("QPushButton{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/correl.png);}"
                              "QPushButton:hover{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/correl2.png);}");
    lpAny->setStyleSheet("QPushButton{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/lpAny.png);}"
                         "QPushButton:hover{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/lpAny2.png);}");
    lpNone->setStyleSheet("QPushButton{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/lpNone.png);}"
                          "QPushButton:hover{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/lpNone2.png);}");
    lp3->setStyleSheet("QPushButton{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/lp3.png);}"
                       "QPushButton:hover{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/lp32.png);}");
    absorptionCandle->setStyleSheet("QPushButton{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/absorCandle.png);}"
                                    "QPushButton:hover{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/absorCandle2.png);}");
    molotCandle->setStyleSheet("QPushButton{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/molotCandle.png);}"
                               "QPushButton:hover{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/molotCandle2.png);}");
    starCandle->setStyleSheet("QPushButton{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/starCandle.png);}"
                              "QPushButton:hover{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/starCandle2.png);}");
    changeTrend->setStyleSheet("QPushButton{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/changeTrend.png);}"
                              "QPushButton:hover{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/changeTrend2.png);}");
    flet->setStyleSheet("QPushButton{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/flet.png);}"
                        "QPushButton:hover{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/flet2.png);}");
    flags->setStyleSheet("QPushButton{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/flags.png);}"
                         "QPushButton:hover{border: none; max-width: 100px; max-height: 100px; background-image: url(:/images/ImageForButtons/flags2.png);}");

    ask3->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    mt4->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    mt5->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    quik->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    ninja->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    reset->setStyleSheet("QPushButton{background-color: red; color: white; font: bold;} QPushButton:hover{background-color: darkred; color: white; font: bold;}");

    instrumentsList1->setStyleSheet("QTreeWidget{background-color: argb(100, 0, 0, 0); color: white; }");
    hView1->setStyleSheet("QHeaderView {background-color: argb(100, 0, 0, 0); color: white;}"
                          "QHeaderView::section {background-color: argb(100, 0, 0, 0); color: white;}"
                          );

    describtion->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    lbl1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ask3->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    mt4->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    mt5->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    quik->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    ninja->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    instrumentsList1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    gip->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    trend->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    correlList->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    lpAny->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    lpNone->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    lp3->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    absorptionCandle->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    molotCandle->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    starCandle->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    changeTrend->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    flet->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    flags->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    gridLayout->addWidget(describtion, 0, 0, 1, 9);
    gridLayout->addWidget(ask3, 1, 0, 1, 1);
    gridLayout->addWidget(mt4, 1, 1, 1, 1);
    gridLayout->addWidget(mt5, 1, 2, 1, 1);
    gridLayout->addWidget(quik, 1, 3, 1, 1);
    gridLayout->addWidget(ninja, 1, 4, 1, 1);
    gridLayout->addWidget(lbl1, 1, 5, 1, 1);
    gridLayout->addWidget(instrumentsList1, 2, 0, 6, 6); // connect
    gridLayout->addWidget(filtr, 2, 6, 1, 3);
    gridLayout->addWidget(gip, 3, 6, 1, 1);
    gridLayout->addWidget(trend, 3, 7, 1, 1);
    gridLayout->addWidget(correlList, 3, 8, 1, 1);
    gridLayout->addWidget(lpAny, 4, 6, 1, 1);
    gridLayout->addWidget(lpNone, 4, 7, 1, 1);
    gridLayout->addWidget(lp3, 4, 8, 1, 1);
    gridLayout->addWidget(absorptionCandle, 5, 6, 1, 1);
    gridLayout->addWidget(molotCandle, 5, 7, 1, 1);
    gridLayout->addWidget(starCandle, 5, 8, 1, 1);
    gridLayout->addWidget(changeTrend, 6, 6, 1, 1);
    gridLayout->addWidget(flet, 6, 7, 1, 1);
    gridLayout->addWidget(flags, 6, 8, 1, 1);
    gridLayout->addWidget(reset, 7, 6, 1, 3);


    gridLayout->setColumnMinimumWidth(0, 35);
    gridLayout->setColumnMinimumWidth(1, 35);
    gridLayout->setColumnMinimumWidth(2, 35);
    gridLayout->setColumnMinimumWidth(3, 35);
    gridLayout->setColumnMinimumWidth(4, 35);
    gridLayout->setColumnMinimumWidth(6, 100);
    gridLayout->setColumnMinimumWidth(7, 100);
    gridLayout->setColumnMinimumWidth(8, 100);
    gridLayout->setRowMinimumHeight(1, 35);
    gridLayout->setRowMinimumHeight(2, 100);
    gridLayout->setRowMinimumHeight(3, 100);
    gridLayout->setRowMinimumHeight(4, 100);
    gridLayout->setRowMinimumHeight(5, 100);

    connect(ask3, SIGNAL(clicked()), SLOT(ask3_Slot()));
    connect(mt4, SIGNAL(clicked()), SLOT(mt4_Slot()));
    connect(mt5, SIGNAL(clicked()), SLOT(mt5_Slot()));
    connect(quik, SIGNAL(clicked()), SLOT(quik_Slot()));
    connect(ninja, SIGNAL(clicked()), SLOT(ninja_Slot()));

    connect(gip, SIGNAL(clicked()), SLOT(gip_Slot()));
    connect(trend, SIGNAL(clicked()), SLOT(trend_Slot()));
    connect(correlList, SIGNAL(clicked()), SLOT(correlList_Slot()));
    connect(lpAny, SIGNAL(clicked()), SLOT(lpAny_Slot()));
    connect(lpNone, SIGNAL(clicked()), SLOT(lpNone_Slot()));
    connect(lp3, SIGNAL(clicked()), SLOT(lp3_Slot()));
    connect(absorptionCandle, SIGNAL(clicked()), SLOT(absorptionCandle_Slot()));
    connect(molotCandle, SIGNAL(clicked()), SLOT(molotCandle_Slot()));
    connect(starCandle, SIGNAL(clicked()), SLOT(starCandle_Slot()));    
    connect(changeTrend, SIGNAL(clicked()), SLOT(changeTrend_Slot()));
    connect(flet, SIGNAL(clicked()), SLOT(flet_Slot()));
    connect(flags, SIGNAL(clicked()), SLOT(flags_Slot()));
    connect(reset, SIGNAL(clicked()), SLOT(reset_Slot()));
}

void buildSyntheticChart::addButton1_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
    ask1 = new QPushButton("?");
    ask2 = new QPushButton("?");
    QStandardItemModel * model1 = new QStandardItemModel;
    QStandardItemModel * model2 = new QStandardItemModel;
    QHeaderView * hView1 = new QHeaderView(Qt::Horizontal);
    QHeaderView * hView2 = new QHeaderView(Qt::Horizontal);
    instrumentsList1 = new QTreeWidget;
    instrumentsList2 = new QTreeWidget;
    lbl1 = new QLabel("<b>List istrument:</b>");
    lbl2 = new QLabel("<b>Added list instrument:</b>");
    mt4 = new QPushButton("mt4");
    mt5 = new QPushButton("mt5");
    quik = new QPushButton("quik");
    ninja = new QPushButton("nj");
    select = new QPushButton("SELECT");
    describtion = new QLabel("<i style=\"color:white;\"><center>Потом тут будет текст - описание нижеописанного функционала......</center></i>");

    mt4->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    mt5->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    quik->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    ninja->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    select->setStyleSheet("QPushButton{background-color: red; color: white; font: bold;} QPushButton:hover{background-color: darkred; color: white; font: bold;}");
    instrumentsList1->setStyleSheet("QTreeWidget{background-color: argb(100, 0, 0, 0); color: white; }");
    instrumentsList2->setStyleSheet("QTreeWidget{background-color: argb(100, 0, 0, 0); color: white;}");
    hView1->setStyleSheet("QHeaderView {background-color: argb(100, 0, 0, 0); color: white;}"
                          "QHeaderView::section {background-color: argb(100, 0, 0, 0); color: white;}"
                          );
    hView2->setStyleSheet("QHeaderView {background-color: argb(100, 0, 0, 0); color: white;}"
                          "QHeaderView::section {background-color: argb(100, 0, 0, 0); color: white;}"
                          );

    model1->setHorizontalHeaderLabels(QStringList()<<"Symbol"<<"Bid"<<"Ask");
    model2->setHorizontalHeaderLabels(QStringList()<<"Symbol");

    hView1->setModel(model1);
    hView2->setModel(model2);

    instrumentsList1->setHeader(hView1);
    instrumentsList2->setHeader(hView2);

    select->setMaximumHeight(25);
    ask1->setMaximumSize(QSize(30, 30));
    ask2->setMaximumSize(QSize(30, 30));
    mt4->setMaximumSize(QSize(30, 30));
    mt5->setMaximumSize(QSize(30, 30));
    quik->setMaximumSize(QSize(30, 30));
    ninja->setMaximumSize(QSize(30, 30));

    ask1->setToolTip("What this ?");
    ask2->setToolTip("What this ?");
    mt4->setToolTip("Download datas from mt4");
    mt5->setToolTip("Download datas from mt5");
    quik->setToolTip("Download datas from quik");
    ninja->setToolTip("Download datas from ninja");
    ask1->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    ask2->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");

    describtion->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    lbl1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ask1->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    instrumentsList1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    lbl2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ask2->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    instrumentsList2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    gridLayout->removeWidget(describtionChange);
    gridLayout->removeWidget(addButton1);
    gridLayout->removeWidget(addButton2);
    describtionChange->hide();
    addButton1->hide();
    addButton2->hide();

    gridLayout->addWidget(describtion, 0, 0, 1, 12);
    gridLayout->addWidget(ask1, 1, 0, 1, 1);
    gridLayout->addWidget(mt4, 1, 1, 1, 1);
    gridLayout->addWidget(mt5, 1, 2, 1, 1);
    gridLayout->addWidget(quik, 1, 3, 1, 1);
    gridLayout->addWidget(ninja, 1, 4, 1, 1);
    gridLayout->addWidget(lbl1, 1, 5, 1, 1);
    gridLayout->addWidget(ask2, 1, 6, 1, 1);
    gridLayout->addWidget(lbl2, 1, 7, 1, 5);
    gridLayout->addWidget(instrumentsList1, 2, 0, 2, 6); // connect
    gridLayout->addWidget(instrumentsList2, 2, 6, 1, 6); // connect
    gridLayout->addWidget(select, 3, 6, 1, 6);

    gridLayout->setColumnMinimumWidth(0, 35);
    gridLayout->setColumnMinimumWidth(1, 35);
    gridLayout->setColumnMinimumWidth(2, 35);
    gridLayout->setColumnMinimumWidth(3, 35);
    gridLayout->setColumnMinimumWidth(4, 35);
    gridLayout->setColumnMinimumWidth(6, 35);
    gridLayout->setRowMinimumHeight(1, 35);


    connect(ask1, SIGNAL(clicked()), SLOT(ask1_Slot()));
    connect(ask2, SIGNAL(clicked()), SLOT(ask2_Slot()));
    connect(mt4, SIGNAL(clicked()), SLOT(mt4_Slot()));
    connect(mt5, SIGNAL(clicked()), SLOT(mt5_Slot()));
    connect(quik, SIGNAL(clicked()), SLOT(quik_Slot()));
    connect(ninja, SIGNAL(clicked()), SLOT(ninja_Slot()));
    connect(select, SIGNAL(clicked()), SLOT(select_Slot()));
}

void buildSyntheticChart::addButton2_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
    ask1 = new QPushButton("?");
    ask2 = new QPushButton("?");
    QStandardItemModel * model1 = new QStandardItemModel;
    QStandardItemModel * model2 = new QStandardItemModel;
    QHeaderView * hView1 = new QHeaderView(Qt::Horizontal);
    QHeaderView * hView2 = new QHeaderView(Qt::Horizontal);
    instrumentsList1 = new QTreeWidget;
    instrumentsList2 = new QTreeWidget;
    lbl1 = new QLabel("<b>List istrument:</b>");
    lbl2 = new QLabel("<b>Added list instrument:</b>");
    mt4 = new QPushButton("mt4");
    mt5 = new QPushButton("mt5");
    quik = new QPushButton("quik");
    ninja = new QPushButton("nj");
    select = new QPushButton("SELECT");
    describtion = new QLabel("<i style=\"color:white;\"><center>Потом тут будет текст - описание нижеописанного функционала......</center></i>");

    model1->setHorizontalHeaderLabels(QStringList()<<"Symbol"<<"Bid"<<"Ask");
    model2->setHorizontalHeaderLabels(QStringList()<<"Symbol");

    hView1->setModel(model1);
    hView2->setModel(model2);

    instrumentsList1->setHeader(hView1);
    instrumentsList2->setHeader(hView2);

    mt4->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    mt5->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    quik->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    ninja->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    select->setStyleSheet("QPushButton{background-color: red; color: white; font: bold;} QPushButton:hover{background-color: darkred; color: white; font: bold;}");
    instrumentsList1->setStyleSheet("QTreeWidget{background-color: argb(100, 0, 0, 0); color: white; }");
    instrumentsList2->setStyleSheet("QTreeWidget{background-color: argb(100, 0, 0, 0); color: white;}");
    hView1->setStyleSheet("QHeaderView {background-color: argb(100, 0, 0, 0); color: white;}"
                          "QHeaderView::section {background-color: argb(100, 0, 0, 0); color: white;}"
                          );
    hView2->setStyleSheet("QHeaderView {background-color: argb(100, 0, 0, 0); color: white;}"
                          "QHeaderView::section {background-color: argb(100, 0, 0, 0); color: white;}"
                          );

    select->setMaximumHeight(25);
    ask1->setMaximumSize(QSize(30, 30));
    ask2->setMaximumSize(QSize(30, 30));
    mt4->setMaximumSize(QSize(30, 30));
    mt5->setMaximumSize(QSize(30, 30));
    quik->setMaximumSize(QSize(30, 30));
    ninja->setMaximumSize(QSize(30, 30));

    ask1->setToolTip("What this ?");
    ask2->setToolTip("What this ?");
    mt4->setToolTip("Download datas from mt4");
    mt5->setToolTip("Download datas from mt5");
    quik->setToolTip("Download datas from quik");
    ninja->setToolTip("Download datas from ninja");
    ask1->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");
    ask2->setStyleSheet("QPushButton{border-radius: 15px; background-color: yellow; color: black; font: bold;} QPushButton:hover{border-radius: 15px; background-color: red; color: white; font: bold;}");

    describtion->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    lbl1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ask1->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    instrumentsList1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    lbl2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ask2->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    instrumentsList2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    gridLayout->removeWidget(describtionChange);
    gridLayout->removeWidget(addButton1);
    gridLayout->removeWidget(addButton2);
    describtionChange->hide();
    addButton1->hide();
    addButton2->hide();

    gridLayout->addWidget(describtion, 0, 0, 1, 12);
    gridLayout->addWidget(ask1, 1, 0, 1, 1);
    gridLayout->addWidget(mt4, 1, 1, 1, 1);
    gridLayout->addWidget(mt5, 1, 2, 1, 1);
    gridLayout->addWidget(quik, 1, 3, 1, 1);
    gridLayout->addWidget(ninja, 1, 4, 1, 1);
    gridLayout->addWidget(lbl1, 1, 5, 1, 1);
    gridLayout->addWidget(ask2, 1, 6, 1, 1);
    gridLayout->addWidget(lbl2, 1, 7, 1, 5);
    gridLayout->addWidget(instrumentsList1, 2, 0, 2, 6); // connect
    gridLayout->addWidget(instrumentsList2, 2, 6, 1, 6); // connect
    gridLayout->addWidget(select, 3, 6, 1, 6);

    gridLayout->setColumnMinimumWidth(0, 35);
    gridLayout->setColumnMinimumWidth(1, 35);
    gridLayout->setColumnMinimumWidth(2, 35);
    gridLayout->setColumnMinimumWidth(3, 35);
    gridLayout->setColumnMinimumWidth(4, 35);
    gridLayout->setColumnMinimumWidth(6, 35);
    gridLayout->setRowMinimumHeight(1, 35);


    connect(ask1, SIGNAL(clicked()), SLOT(ask1_Slot()));
    connect(ask2, SIGNAL(clicked()), SLOT(ask2_Slot()));
    connect(mt4, SIGNAL(clicked()), SLOT(mt4_Slot()));
    connect(mt5, SIGNAL(clicked()), SLOT(mt5_Slot()));
    connect(quik, SIGNAL(clicked()), SLOT(quik_Slot()));
    connect(ninja, SIGNAL(clicked()), SLOT(ninja_Slot()));
    connect(select, SIGNAL(clicked()), SLOT(select_Slot()));
}

void buildSyntheticChart::ask1_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::ask2_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::mt4_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::mt5_Slot()
{
    QSound::play(":/mysounds/sounds/error.wav");
    emit statusEvent("This action is in development status and will be available in future releases of the program...");
}

void buildSyntheticChart::quik_Slot()
{
    QSound::play(":/mysounds/sounds/error.wav");
    emit statusEvent("This action is in development status and will be available in future releases of the program...");
}

void buildSyntheticChart::ninja_Slot()
{
    QSound::play(":/mysounds/sounds/error.wav");
    emit statusEvent("This action is in development status and will be available in future releases of the program...");
}

void buildSyntheticChart::select_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::ask3_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::gip_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::trend_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::correlList_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::lpAny_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::lpNone_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::lp3_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::absorptionCandle_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::molotCandle_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::starCandle_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::changeTrend_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::flet_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::flags_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}

void buildSyntheticChart::reset_Slot()
{
    QSound::play(":/mysounds/sounds/sound.wav");
}
