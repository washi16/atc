#ifndef TIMER_H
#define TIMER_H

#include <QtCore>


class timer : public QObject
{
    Q_OBJECT //Torna a class num objecto do QT
public:
    timer();
    QTimer *_timer;
public slots:
    void slot();
};

#endif // TIMER_H
