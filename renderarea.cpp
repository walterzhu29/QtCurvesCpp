#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
#include <QColor>


RenderArea::RenderArea(QWidget *parent) : QWidget(parent),
     mBackbroundColor(0, 0, 255),
     mShapeColor(255, 255, 255),
     mShape(Astroid)
{
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::minimumSize() const
{
    return QSize(400, 200);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);    // No Warning
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);


    switch (mShape) {
    case Astroid:
        mBackbroundColor = Qt::red;
        break;
    case Cycloid:
        mBackbroundColor = Qt::green;
        break;
    case HuygensCicioid:
        mBackbroundColor = Qt::blue;
        break;
    case HypoCicloid:
        mBackbroundColor = Qt::yellow;
        break;
    default:
        break;
    }
    painter.setBrush(mBackbroundColor);
    painter.setPen(mShapeColor);
    // drawing area
    painter.drawRect(this->rect());
    painter.drawLine(this->rect().topLeft(), this->rect().bottomRight());
    painter.drawLine(this->rect().topRight(), this->rect().bottomLeft());
}
