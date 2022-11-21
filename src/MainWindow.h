//
// Created by RayaneGostar on 11/12/2022.
//

#ifndef MIDDATAPRO_MAINWINDOW_H
#define MIDDATAPRO_MAINWINDOW_H

#include <QGraphicsView>
#include "Button.h"


class MainWindow : public QGraphicsView {
Q_OBJECT
private:
    Button* button;
public:
    MainWindow();
    ~MainWindow();
public slots:
    void onGameStart();

};


#endif //MIDDATAPRO_MAINWINDOW_H
