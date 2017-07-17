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

    enum ShapesType {Astroid, Cycloid, HuygensCicioid, HypoCicloid};

    void setBackgroudColor (QColor color) { mBackbroundColor = color; } // setter
    QColor backgroundColor () const { return mBackbroundColor; } // getter

    void setShape (ShapesType shape) { mShape = shape; }
    ShapesType shape () const { return mShape; }

protected:
    void paintEvent(QPaintEvent *event);

private:
    QColor mBackbroundColor;
    QColor mShapeColor;
    ShapesType mShape;

signals:

public slots:
};

#endif // RENDERAREA_H
