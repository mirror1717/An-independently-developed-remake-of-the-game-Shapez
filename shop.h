#ifndef SHOP_H
#define SHOP_H

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
class Shop : public QWidget
{
    Q_OBJECT
public:
    explicit Shop(QWidget *parent = nullptr);
    //设立四个按钮
    QPushButton *money_button;
    QPushButton *hub_button;
    QPushButton *stone_button;
     QPushButton *return_button;
    void buy1()//买了第一个商品时，标记已购买
     {
        isbuy1=1;
         update();
     };
     void buy2()
     {
         isbuy2=1;
          update();
     };
     void buy3()
     {
         isbuy3=1;
          update();
     };


private:
     //文字
     QLabel *shop_w;
    QLabel *money_w;
     QLabel *hub_w;
     QLabel *mine_w;
     QLabel *return_w;
     QLabel *hub_m;
     QLabel *mine_m;
     QLabel *money_m;
     QPixmap have;
     //标记是否已购买
     int isbuy1;
     int isbuy2;
     int isbuy3;

protected:
void paintEvent(QPaintEvent *event) override;
signals:
};

#endif // SHOP_H
