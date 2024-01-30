#ifndef TEXT_H
#define TEXT_H

#include <QWidget>
#include "menu.h"

namespace Ui {
class Text;
}

class Text : public QWidget
{
    Q_OBJECT

public:
    explicit Text(Menu* MENU = nullptr,QWidget *parent = 0);
    ~Text();

private slots:

    void on_SaveButton_clicked();

private:
    Ui::Text *ui;
    Menu* MENU;
};

#endif // TEXT_H
