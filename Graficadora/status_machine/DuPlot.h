#ifndef DUPLOT_H
#define DUPLOT_H

#include <QVector>
#include <QObject>

class QCPGraph;
class QCustomPlot;

class DuPlot : public QObject {
public:
    DuPlot(QCustomPlot *customPlot, QObject *parent = nullptr);

    void drawGraph();

    void removeGraph();

    void setX(const QVector<double> &x) {
        mX = x;
    }

    void setY(const QVector<double> &y) {
        mY = y;
    }
private:
    QCPGraph *mGraph;
    QVector<double> mX;
    QVector<double> mY;
    QCustomPlot *mCustomPlot;
};

#endif // DUPLOT_H
