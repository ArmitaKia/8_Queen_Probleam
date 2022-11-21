#ifndef MIDDATAPRO_BUTTON_H
#define MIDDATAPRO_BUTTON_H


#include <QGraphicsTextItem>

class Button : public QGraphicsTextItem{
Q_OBJECT

private:
    double width;
    double height;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
public:
    Button(double width,double height);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    double getWidth() const;
    double getHeight() const;

signals:
    void onPress();
};


#endif //MIDDATAPRO_BUTTON_H
