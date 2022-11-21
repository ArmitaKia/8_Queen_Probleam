#include "MainWindow.h"
#include "QueensWindow.h"


MainWindow::MainWindow(){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    QPixmap background(":/images/background");
    background = background.scaled(width(),height());

    //add scene
    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QBrush(background));
    setScene(scene);

    //add button
    button = new Button(350,200);
    button->setPlainText("        START GAME");
    button->setPos(width()/2 - button->getWidth()/2,height()/2 + 350);
    scene->addItem(button);

    connect(button,&Button::onPress,this,&MainWindow::onGameStart);

}
void MainWindow::onGameStart() {
    new QueensWindow();
    close();

}

MainWindow::~MainWindow() {
    delete button;
}