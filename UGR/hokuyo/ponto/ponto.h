#ifndef PONTO_H
#define PONTO_H

#include <iostream>
template <class T>
class ponto
{
    T m_iX,m_iY;
public:
    ponto( T x,T y){m_iX=x; m_iY=y;}
    T get_X()const{return m_iX;}
    T get_Y()const{return m_iY;}
    void imprime();
};

#endif // PONTO_H
