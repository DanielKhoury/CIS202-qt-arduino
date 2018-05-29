#include "ballanimation.h"
#include <QPaintEvent>
#include <QPainter>
#include <QRandomGenerator>
#include <QDebug>

BallAnimation::BallAnimation(QWidget *parent) :
    QWidget(parent),
    m_origin(QPoint(0,0))

{
    setFixedSize(200,200);
    quint32 value = QRandomGenerator::global()->generate();
    qDebug() << value;
}

void BallAnimation::setOrigin(const QPoint &origin)
{
    m_origin = origin;
}

void BallAnimation::addToOrigin(const QPoint &point)
{
    m_origin += point;
}

void BallAnimation::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(QRect(0,0,width()-1,height()-1));
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::red);
    painter.drawEllipse(m_origin,10,10);
}

void BallAnimation::m_move(int move_x, int move_y)
{
    collision();
    addToOrigin(QPoint(move_x * m_x, move_y * m_y));
}

void BallAnimation::collision()
{

    this->m_x %= 7;
    int prev_x = this->m_x;
    this->m_y %= 7;
    int prev_y = this->m_y;
    if(this->m_x >= 0 && prev_x < 0)
       this->m_x += -1;
    else if(this->m_x <= 0 && prev_x >= 0)
       this->m_x += 1;
    else if(this->m_y >= 0 && prev_y < 0)
       this->m_y += -1;
    else if(this->m_y <= 0 && prev_y >= 0)
       this->m_y += 1;

    if (this->m_x > 0 && m_origin.x() >= this->width() - 14)
        this->m_x = this->m_x * -1;
    else if(this->m_x < 0 && m_origin.x() <= 14)
        this->m_x *= -1;
    else if (this->m_y < 0 && m_origin.y() <= 14)
        this->m_y *= -1;
    else if(this->m_y > 0 && m_origin.y() >= this->height() - 14)
        this->m_y *= -1;
}
