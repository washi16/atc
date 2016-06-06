#include "dados.h"
#include <QDebug>
#include <iostream>

dados::dados()
{
    Lidar=new hokuyo();
    m_vecAngulos=Lidar->get_angle_vector();
}


dados::~dados()
{
    delete Lidar;
}


vector<ponto<long int>> dados::get_pontos()
{
    vector <long int> distancias=Lidar->new_scan();
    vector<ponto<long int>> pontos;

    for(int i=0;i<m_vecAngulos.size();i++)
    {
        long int x=(long int)distancias[i]*cos(m_vecAngulos[i]),y=(long int)distancias[i]*sin(m_vecAngulos[i]);
        pontos.push_back(ponto<long int>(x,y));
    }

    return pontos;
}


