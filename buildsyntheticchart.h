#ifndef BUILDSYNTHETICCHART_H
#define BUILDSYNTHETICCHART_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QSound>
#include <QTreeWidget>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QTimer>
#include <QApplication>
#include <QEvent>

class buildSyntheticChart : public QWidget{
    Q_OBJECT
private:
    int listWidth;
    QPushButton *buildSintheticChart, *buildMultiCharts, *__Find,
                *addButton1, *addButton2,
                *ask1, *ask2, *ask3, *ask4,
                *mt4, *mt5, *quik, *ninja,
                *select,
                *gip, *trend, *correlList, *lpAny, *lpNone, *lp3, *absorptionCandle, *molotCandle, *starCandle, *changeTrend, *flet, *flags, *reset;
    QTreeWidget *instrumentsList1, *instrumentsList2;
    QGridLayout * gridLayout;
    QLabel *lbl1, *lbl2,
           *describtion, *describtionChange,
           *filtr;

public:
    buildSyntheticChart(QWidget * pwgt = nullptr, int ii = 100);
public slots:
    void buildSintheticChart_Slot();
    void buildMultiCharts_Slot();
    void __Find_Slot();
    void addButton1_Slot();
    void addButton2_Slot();
    void ask1_Slot();
    void ask2_Slot();
    void mt4_Slot();
    void mt5_Slot();
    void quik_Slot();
    void ninja_Slot();
    void select_Slot();
    void ask3_Slot();    
    void gip_Slot();
    void trend_Slot();
    void correlList_Slot();
    void lpAny_Slot();
    void lpNone_Slot();
    void lp3_Slot();
    void absorptionCandle_Slot();
    void molotCandle_Slot();
    void starCandle_Slot();
    void changeTrend_Slot();
    void flet_Slot();
    void flags_Slot();
    void reset_Slot();

signals:
    void statusEvent(QString);

};

#endif // BUILDSYNTHETICCHART_H
