#ifndef WIN_H
#define WIN_H

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

class Win : public QWidget
{
    Q_OBJECT
public:
    explicit Win(QWidget *parent = nullptr);
private:
    QLabel *Label;//通关文字
     QPixmap win;//通关图像

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
};

#endif // WIN_H
