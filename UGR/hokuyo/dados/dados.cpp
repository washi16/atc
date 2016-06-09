#include "dados.h"
#include <QDebug>
#include <iostream>
#include <fstream>

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
    m_vecDistancias=Lidar->new_scan();
    vector<ponto<long int>> pontos;
    ofstream xls;
    xls.open("tabela.xls");


    for(int i=0;i<m_vecAngulos.size();i++)
    {
        long int x=(long int)m_vecDistancias[i]*cos(m_vecAngulos[i]* PI/180),y=(long int)m_vecDistancias[i]*sin(m_vecAngulos[i]* PI/180);
        pontos.push_back(ponto<long int>(x,y));
        xls<<m_vecDistancias[i]<<"\t"<<m_vecAngulos[i]<<"\t"<<x<<"\t"<<y<<endl;
    }
    xls.close();
    return pontos;
}

bool dados::save_frame(QString fileName)
{
    QFile csv(fileName);

    if(!csv.open(QIODevice::WriteOnly))
    return false;

    QTextStream file_out(&csv);

    file_out<<"Distancias"<<"\t"<<"Angulos"<<"\t"<<endl;
    for(int i=0;i<m_vecDistancias.size();i++)
    {
        file_out<<m_vecDistancias[i]<<"\t"<<m_vecAngulos[i]<<endl;
    }
    csv.close();
    return true;

}

