#ifndef START_H
#define START_H

#include <QWidget>
#include <QPushButton> // 添加 QPushButton 头文件
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "gameinterface.h" // 包含新的游戏界面头文件


QT_BEGIN_NAMESPACE
namespace Ui {
class Start;
}
QT_END_NAMESPACE

class Start : public QWidget
{
    Q_OBJECT

public:
    Start(QWidget *parent = nullptr);
    ~Start();
    //三个按钮
    QPushButton *starting;
    QPushButton *conti;
    QPushButton *end;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *button;
    GameInterface *gameInterface;



private:

};
#endif // START_H
