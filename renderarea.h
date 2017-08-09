#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const;
    QSize minimumSize() const;

    enum ShapesType {Astroid, Cycloid, HuygensCycloid, HypoCycloid, FutureCurve};

    void setBackgroudColor (QColor color) { mBackbroundColor = color; } // setter
    QColor backgroundColor () const { return mBackbroundColor; } // getter


    void setShape (ShapesType shape) { mShape = shape; on_shape_changed (); }
    ShapesType shape () const { return mShape; }

protected:
    void paintEvent(QPaintEvent *event);
private:
    void on_shape_changed();
    QPointF compute(float t); //dispatch function based on mShape's type
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens(float t);
    QPointF compute_hypo(float t);
    QPointF compute_future_curve(float t);


private:
    QColor mBackbroundColor;
    QColor mShapeColor;
    ShapesType mShape;

    float mIntervalLenth;
    float mScale;
    int mStepCount;


signals:

public slots:
};

#endif // RENDERAREA_H
