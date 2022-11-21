#include "Queen.h"
Queen::Queen(int width, int height): QGraphicsPixmapItem() ,width(width), height(height){
    QPixmap pixmap(":/images/queen");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
}
