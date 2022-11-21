#ifndef MIDDATAPRO_QUEEN_H
#define MIDDATAPRO_QUEEN_H

#include <QGraphicsPixmapItem>


class Queen : public QGraphicsPixmapItem{
private:
    int width;
    int height;
public:
    Queen(int width,int height);

};


#endif //MIDDATAPRO_QUEEN_H
