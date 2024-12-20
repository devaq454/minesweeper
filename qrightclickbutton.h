#ifndef QRIGHTCLICKBUTTON_H
#define QRIGHTCLICKBUTTON_H

#include <QtWidgets/QPushButton>
#include <QMouseEvent>

// class for implementsing click on RMB
class QRightClickButton : public QPushButton {
    Q_OBJECT

public:
    explicit QRightClickButton(QWidget *parent = 0);

private slots:
    void mousePressEvent(QMouseEvent *e);

signals:
    void rightClicked();

};


#endif // QRIGHTCLICKBUTTON_H
