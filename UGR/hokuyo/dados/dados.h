#ifndef DADOS_H
#define DADOS_H
#include "hokuyo_class/hokuyo.h"
#include <math.h>
#include <vector>
#include "ponto/ponto.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

#define PI 3.14159265

using namespace std;

class dados
{
public:
    dados();
    ~dados();
    vector<ponto<long int>> get_pontos();
    bool save_frame(QString fileName);
private:
    hokuyo *Lidar;
    vector<double> m_vecAngulos;
    vector<long int> m_vecDistancias;




};

#endif // DADOS_H
