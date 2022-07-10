#include "Widget.h"
#include "ui_Widget.h"
#include "qcustomplot.h"
#include "DuPlot.h"
#include <QVBoxLayout>
#include <QtMath>

#define XMIN -250
#define XMAX 250
#define YMIN -250
#define YMAX 250

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);

    ui->lineEdit->setPlaceholderText("Escribe una funcion");

    ui->graphic->setBackground(QBrush(QColor("#121212")));

    ui->graphic->xAxis->setRange(XMIN, XMAX);
    ui->graphic->yAxis->setRange(YMIN, YMAX);
    ui->graphic->xAxis->setTickLabelColor(Qt::white);
    ui->graphic->yAxis->setTickLabelColor(Qt::white);
    ui->graphic->xAxis->setBasePen(QPen(Qt::white));
    ui->graphic->yAxis->setBasePen(QPen(Qt::white));

    valor_graphic = new DuPlot(ui->graphic, this);

}

Widget::~Widget() {
    delete ui;
}

void Widget::calculaValor(vector<string> recta) {
    QVector<double> x;
    QVector<double> y;

    if(calc.grafica_final.size() == 1) {
        for (int iX = XMIN; iX < XMAX; iX++) {
            x << iX;
            //y << iX;
            y << atoi(recta[0].c_str());
        }
        calc.grafica_final.pop_back();
    } else {
        for (int iX = XMIN; iX < XMAX; iX++) {
            x << iX;
            //y << iX;
            y << atoi(recta[iX+XMAX].c_str());
        }
        for (int iX = XMIN; iX < XMAX; iX++) {
            calc.grafica_final.pop_back();
        }
    }

    valor_graphic->setX(x);
    valor_graphic->setY(y);
    valor_graphic->removeGraph();
    valor_graphic->drawGraph();
    ui->graphic->graph(0)->setPen(QPen(Qt::white));
    ui->graphic->replot();
}


void Widget::on_pushButton_clicked() {
    string str = ui->lineEdit->text().toStdString();
    //recogo el dato del lineEdit

    exist = str.find("=");
    //busco si hay asignacion de variables

    str = exist != string::npos ? calc.asignacion(str): calc.asignacion2(str);

    ui->resultado->setText(QString::fromStdString(str));

    if(!calc.grafica_final.empty() and ui->lineEdit->text().toStdString() != "cls")
        calculaValor(calc.grafica_final);

    if(ui->lineEdit->text().toStdString() == "cls") {
        valor_graphic->removeGraph();
        ui->graphic->replot();
        ui->resultado->setText("");
    }
}
