#include "dados.h"
#include <QDebug>
#include <iostream>
#include <fstream>
#include <QMutex>
#include <fstream>

dados::dados()
{
    Lidar=new hokuyo();
    m_vecAngulos=Lidar->get_angle_vector();
    system("mkdir logs");
    f_write=new QFile ("logs/"+QDateTime::currentDateTime().toString("yyyy_MM_dd_hh-mm-ss")+".csv");
    if(!f_write->open(QIODevice::WriteOnly))
    {
        QMessageBox msg;
        msg.setText("Log File not created!");
        msg.exec();
    }
    stream_out=new QTextStream(f_write);
}


dados::~dados()
{
    f_write->close();
    delete f_write;
    delete Lidar;
}


vector<ponto<long int>> dados::get_pontos(char filtro)
{
    m_vecDistancias=Lidar->new_scan();
    vector<ponto<long int>> pontos;
    ofstream xls;
    xls.open("tabela.xls");

    long int Distancia;
    for(int i=0;i<m_vecAngulos.size()-1;i++)
    {
        Distancia=m_vecDistancias[i];
        if(filtro)
            if(Distancia>4300)
                Distancia=0;
        long int x=(long int)Distancia*cos(m_vecAngulos[i]* PI/180),y=(long int)Distancia*sin(m_vecAngulos[i]* PI/180);
        pontos.push_back(ponto<long int>(x,y));
        xls<<Distancia<<"\t"<<m_vecAngulos[i]<<"\t"<<x<<"\t"<<y<<endl;
        *stream_out<<Distancia<<"\t";
    }
    *stream_out<<endl;
    xls.close();
    return pontos;
}

vector<ponto<long int>> dados::get_pontos_log(char filtro)
{

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

