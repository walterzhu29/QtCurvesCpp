#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
#include <QColor>


RenderArea::RenderArea(QWidget *parent) : QWidget(parent),
     mBackbroundColor(0, 0, 255),
     mShapeColor(255, 255, 255),
     mShape(Astroid)
{
    on_shape_changed();
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::minimumSize() const
{
    return QSize(400, 200);
}

void RenderArea::on_shape_changed()
{
    switch (mShape) {
    case Astroid:
        mScale = 40;
        mIntervalLenth = 2 * M_PI;
        mStepCount = 256;
        break;
    case Cycloid:
        break;
    case HuygensCycloid:
        break;
    case HypoCycloid:
        break;
    case FutureCurve:
        break;
    default:
        break;
    }
}

QPointF RenderArea::compute (float t)
{
    switch (mShape) {
    case Astroid:
        return compute_astroid(t);
        break;
    case Cycloid:
        return compute_cycloid(t);
        break;
    case HuygensCycloid:
        return compute_huygens(t);
        break;
    case HypoCycloid:
        return compute_hypo(t);
        break;
    case FutureCurve:
        break;
    default:
        break;
    }
    return QPointF(0, 0);
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

QPointF RenderArea::compute_cycloid(float t)
{

}
QPointF RenderArea::compute_huygens(float t)
{

}
QPointF RenderArea::compute_hypo(float t)
{

}

QPointF RenderArea::compute_future_curve(float t)
{

}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);    // No Warning
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);



    painter.setBrush(mBackbroundColor);
    painter.setPen(mShapeColor);
    // drawing area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    float step = mIntervalLenth / mStepCount;
    for(float t = 0; t < mIntervalLenth; t += step)
    {
        //point take the value from compute()
        QPointF point = compute(t);
        //take pixel from QPointF to QPoint, then the point can be put on render coordinate
        QPoint pixel;
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());
        painter.drawPoint(pixel);
    }
}
