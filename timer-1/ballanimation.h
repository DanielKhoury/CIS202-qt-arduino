#ifndef BALLANIMATION_H
#define BALLANIMATION_H

#include <QWidget>

class BallAnimation : public QWidget
{
    Q_OBJECT
public:
    explicit BallAnimation(QWidget *parent = nullptr);
    void setOrigin(const QPoint &origin);
    void addToOrigin(const QPoint &origin);
    void m_move(int x, int y);
    void collision();

signals:

public slots:
    void paintEvent(QPaintEvent* event);
private:
    QPoint m_origin;
    int m_x;
    int m_y;
    int m_width = 10;
    int m_height = 10;
};

#endif // BALLANIMATION_H
