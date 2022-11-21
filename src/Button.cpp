#include "Button.h"
#include <QFont>
#include <QTextDocument>
#include <QPainter>

Button::Button(double width,double height) : QGraphicsTextItem(),width(width),height(height){
    QFont font;
    font.setPixelSize(30);
    font.setBold(true);

    setFont(font);
    setDefaultTextColor(QColor(0,0,0));

    document()->setDocumentMargin(10);
    setTextWidth(width);

}

void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap pixmap(":/images/black");
    pixmap = pixmap.scaled(width,height);

    painter->setBrush(QBrush(pixmap));
    painter->drawRect(boundingRect());
    QGraphicsTextItem::paint(painter, option, widget);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsTextItem::mousePressEvent(event);
    emit onPress();
}

double Button::getWidth() const {
    return width;
}

double Button::getHeight() const {
    return height;
}
