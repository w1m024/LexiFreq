#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "menu.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_LLButton_clicked();

    void on_BTButton_clicked();

    void on_HTButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::Widget *ui;
     Menu* MENU;
};

#endif // WIDGET_H
