//
// Created by RayaneGostar on 11/12/2022.
//

#ifndef MIDDATAPRO_QUEENSWINDOW_H
#define MIDDATAPRO_QUEENSWINDOW_H

#include <QGraphicsView>
#include "Block.h"
#include "Queen.h"
#include "Button.h"


class QueensWindow : public QGraphicsView{
private:
    int blockWidth;
    int blockHeight;
    int addXPosition;
    int addYPosition;
    int stepCounter{-1};
    int functionCounter{0};
    Block* blocks [8][8];
    Queen* queens [8];
    int saveArray [92][8];
    Button* nextPosition;
    Button* previousPosition;
public:
    QueensWindow();
    ~QueensWindow();
    void solveQueenProblem(int loc[], int num);
    void show(int stepCounter, int posX, int posY);
public slots:
    void onNext();
    void onPre();


};


#endif //MIDDATAPRO_QUEENSWINDOW_H
