#include <QApplication>
#include <QPushButton>
#include "src/MainWindow.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto maniWindow = new MainWindow();
    maniWindow->show();
    return QApplication::exec();
}