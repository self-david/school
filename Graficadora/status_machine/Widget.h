#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "calculator.h"

using namespace std;

namespace Ui {
class Widget;
}

class QVBoxLayout;
class DuPlot;

class Widget : public QWidget {
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:

    void on_pushButton_clicked();


private:
    Ui::Widget *ui;
    QVBoxLayout *mLayout;
    DuPlot *valor_graphic;
    vector<string> curva;
    calculator calc;
    size_t exist;


    void calculaValor(vector<string>);
};

#endif // WIDGET_H
