#ifndef MIDDATAPRO_BLOCK_H
#define MIDDATAPRO_BLOCK_H

#include <QGraphicsPixmapItem>

class Block : public QGraphicsPixmapItem{
private:
    int width;
    int height;
    bool darkOrLight;
public:
    Block(int width,int height,bool darkOrLight);
};


#endif //MIDDATAPRO_BLOCK_H
