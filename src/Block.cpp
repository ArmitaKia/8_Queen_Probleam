#include "Block.h"
Block::Block(int width,int height,bool darkOrLight): QGraphicsPixmapItem(),width(width),height(height) {
    if(darkOrLight == true)
    {
        QPixmap pixmap(":/images/brown-light");
        pixmap = pixmap.scaled(width,height);
        setPixmap(pixmap);
    }
    else{
        QPixmap pixmap(":/images/brown-dark");
        pixmap = pixmap.scaled(width,height);
        setPixmap(pixmap);

    }
}