#ifndef DADOS_H
#define DADOS_H
#include "hokuyo_class/hokuyo.h"
#include <math.h>
#include <vector>
#include "ponto/ponto.h"
#include <QMessageBox>

using namespace std;

class dados
{
public:
    dados();
    ~dados();
    vector<ponto<long int>> get_pontos();


private:
    hokuyo *Lidar;
    //vector<long> m_vecDistancias;
    vector<double> m_vecAngulos;



};

#endif // DADOS_H
