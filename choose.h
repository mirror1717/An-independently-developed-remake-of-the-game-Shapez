#ifndef CHOOSE_H
#define CHOOSE_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QRect>
#include <QDebug>
#include <QMouseEvent>
#include<QTimer>
#include <QKeyEvent>
class Choose : public QWidget
{
    Q_OBJECT
public:
    explicit Choose(QWidget *parent = nullptr);
    QPushButton *belt_button;//选择加速传送带的按钮
    QPushButton *cutter_button;//选择加速分割机的按钮
    QPushButton *miner_button;//选择加速采矿机的按钮

private:
   QLabel *Label;//文字

};

#endif // CHOOSE_H
