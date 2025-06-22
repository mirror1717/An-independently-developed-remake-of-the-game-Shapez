#include "win.h"

Win::Win(QWidget *parent)
    : QWidget{parent}
{ setFixedSize(800,500);

    win=QPixmap(":/picture/win.png");


    QSize labelSize(800, 50);
    Label = new QLabel(this);
    Label->setText(QString("恭喜通关！"));
    Label->move(300, 100);
    Label->setFixedSize(labelSize);
    QFont font;
    font.setPointSize(40); // 设置字体大小为20像素
    Label->setFont(font);


}
void Win::paintEvent(QPaintEvent *event)//绘图
{
    Q_UNUSED(event);
    QPainter painter(this);
     painter.drawPixmap(350,300,100,100,win);
}
