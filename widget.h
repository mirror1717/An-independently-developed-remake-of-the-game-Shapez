#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton> // 添加 QPushButton 头文件
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include "gameinterface.h" // 包含新的游戏界面头文件


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots: // 添加一个私有槽函数
    void fstart(); // 声明按钮点击事件的槽函数
     void fconti();
      void fend();

private:
    Ui::Widget *ui;
    QPushButton *start;
    QPushButton *conti;
    QPushButton *end; // 添加一个 QPushButton 成员变量
   QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *button;
     GameInterface *gameInterface;
};
#endif // WIDGET_H
