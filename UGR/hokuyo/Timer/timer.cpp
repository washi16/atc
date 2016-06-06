#include "timer.h"
#include "QDebug"


timer::timer()
{
    _timer= new QTimer(this);
    connect(_timer,SIGNAL(timeout()),this,SLOT(slot()));
    _timer->start(250);

}



void timer::slot()
{
    qDebug()<<"Timer";

}
