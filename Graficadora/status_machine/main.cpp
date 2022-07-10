#include "Widget.h"
#include <QApplication>
#include <qfile.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget w;
    QFile style("style.qss");
    style.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(style.readAll());
    w.setStyleSheet(styleSheet);
    w.show();

    return a.exec();
}
