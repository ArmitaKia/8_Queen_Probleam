#include "QueensWindow.h"
#include <iostream>
#include "Block.h"

QueensWindow::QueensWindow() {

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    //add scene
    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QColor("#EED5CD"));
    setScene(scene);

    //calculate sizes
     blockWidth = scene->width()/16;
     blockHeight = scene->width()/16;

     addXPosition = scene->width()/2 - 4*blockWidth;
     addYPosition = scene->height()/2 - 4*blockHeight;

    int queenWidth = scene->width()/16;
    int queenHeight = scene->width()/16;

    //add blocks for making chess board
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(i%2==1 && j%2==1)
            {
                blocks[i][j] = new Block(blockWidth,blockHeight,true);
                scene->addItem(blocks[i][j]);
                blocks[i][j]->setPos(i*blockWidth + addXPosition,j*blockHeight + addYPosition);
            }
            else if(i%2==1 && j%2==0)
            {
                blocks[i][j] = new Block(blockWidth,blockHeight,false);
                scene->addItem(blocks[i][j]);
                blocks[i][j]->setPos(i*blockWidth + addXPosition,j*blockHeight + addYPosition);

            }
            else if(i%2==0 && j%2==1)
            {
                blocks[i][j]= new Block(blockWidth,blockHeight, false);
                scene->addItem(blocks[i][j]);
                blocks[i][j]->setPos(i*blockWidth + addXPosition,j*blockHeight + addYPosition);

            }
            else if(i%2==0 && j%2==0)
            {
                blocks[i][j]= new Block(blockWidth,blockHeight,true);
                scene->addItem(blocks[i][j]);
                blocks[i][j]->setPos(i*blockWidth + addXPosition,j*blockHeight + addYPosition);

            }

    //create two buttons for go to next and previous level
    nextPosition = new Button(170,65);
    nextPosition->setPlainText("    next");
    nextPosition->setPos(scene->width() - addXPosition + (addXPosition/2-nextPosition->getWidth()/2) ,scene->height()/2-nextPosition->getHeight()/2);
    scene->addItem(nextPosition);

    previousPosition = new Button(170,65);
    previousPosition->setPlainText(" previous");
    previousPosition->setPos(addXPosition/2-previousPosition->getWidth()/2,scene->height()/2-previousPosition->getHeight()/2);
    scene->addItem(previousPosition);

    //create 8 queens
    queens[0] = new Queen(queenWidth,queenHeight);
    scene->addItem(queens[0]);
    queens[0]->hide();

    queens[1] = new Queen(queenWidth,queenHeight);
    scene->addItem(queens[1]);
    queens[1]->hide();

    queens[2] = new Queen(queenWidth,queenHeight);
    scene->addItem(queens[2]);
    queens[2]->hide();

    queens[3] = new Queen(queenWidth,queenHeight);
    scene->addItem(queens[3]);
    queens[3]->hide();

    queens[4] = new Queen(queenWidth,queenHeight);
    scene->addItem(queens[4]);
    queens[4]->hide();

    queens[5] = new Queen(queenWidth,queenHeight);
    scene->addItem(queens[5]);
    queens[5]->hide();

    queens[6] = new Queen(queenWidth,queenHeight);
    scene->addItem(queens[6]);
    queens[6]->hide();

    queens[7] = new Queen(queenWidth,queenHeight);
    scene->addItem(queens[7]);
    queens[7]->hide();

    //signal and slot connecting for buttons
    connect(nextPosition,&Button::onPress,this,&QueensWindow::onNext);
    connect(previousPosition,&Button::onPress,this,&QueensWindow::onPre);

    //solve the main probleam
    int array[8] = {0,0,0,0,0,0,0,0};
    solveQueenProblem(array,0);
}

void QueensWindow::onNext() {
    if(stepCounter>=92)
        return;
    stepCounter++;
    if(stepCounter<92)
        show(stepCounter,blockWidth,blockHeight);
}

void QueensWindow::onPre() {
    if(stepCounter<0)
        return;
    stepCounter--;
    if(stepCounter>=0)
        show(stepCounter,blockWidth,blockHeight);
}

void QueensWindow::show(int stepCounter, int posX, int posY) {
    for(int i=0;i<8;i++){
        queens[i]->setPos(i * posX + addXPosition,saveArray[stepCounter][i] * posY + addYPosition);
        queens[i]->show();
    }
}

void QueensWindow::solveQueenProblem(int loc[],int num){
    if(functionCounter>=92)
        return;
    if(num==8 && functionCounter<92)
    {
        //save the location of 8 queens in the rows of the saveArray
        for(int i=0;i<8;i++)
            saveArray[functionCounter][i] = loc[i];
        functionCounter++;
    }
    else{
        for(int i=0;i<8;i++){
            bool isFound= true;
            int j=0;
            for(;j<num;j++)
                if(i==loc[j] || i==loc[j]-(num-j) || i== loc[j]+(num-j))
                    isFound = false;
            if(isFound){
                loc[num] = i;
                solveQueenProblem(loc,num+1);
            }
        }
    }
}

QueensWindow::~QueensWindow(){
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            delete blocks[i][j];
    for(int i=0;i<8;i++)
        delete queens[i];
    delete nextPosition;
    delete previousPosition;
}