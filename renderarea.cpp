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

QPointF RenderArea::compute_astroid(float t)
{
    //compute astroid function
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * pow(cos_t, 3);
    float y = 2 * pow(sin_t, 3);
    return QPointF(x, y);
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

    QPoint center = this->rect().center();
    int stepCount = 256;
    float scale = 40;
    float intervalLenth = 2 * M_PI;
    float step = intervalLenth / stepCount;
    for(float t = 0; t < intervalLenth; t += step)
    {
        //point take the value from compute_astroid()
        QPointF point = compute_astroid(t);
        //take pixel from QPointF to QPoint, then the point can be put on render coordinate
        QPoint pixel;
        pixel.setX(point.x() * scale + center.x());
        pixel.setY(point.y() * scale + center.y());
        painter.drawPoint(pixel);
    }
}
