#ifndef HOKUYO_H
#define HOKUYO_H
#include <iostream>
#include <vector>
#include "urg/UrgCtrl.h"
#include <cstdlib>
#include <cstdio>
#include <QMessageBox>

#define _ANGLES_ 683
#define SUB_0 83
#define ERASE 43
#define LAYSER_DISTANCE 0.352


using namespace qrk;
using namespace std;

class hokuyo
{
public:
    hokuyo();
    hokuyo(char *str);
    vector<long int> get_distance_vector()const;
    vector<double> get_angle_vector()const;
    vector<long int> new_scan();
    //vector<pair<int,int>> get_position(int x,int y);
    int ANGLES = _ANGLES_;
private:
    UrgCtrl urg;
    vector<long int> distance_vector;
    vector<double> angle_vector;
    //vector<pair<int,int>> position;
    long timestamp;
    int numb_data;
    void hokuyo_scan();
    void Angles_config();
    void angles_from_0();
    void angles_from_begin();
    void angles_from_front();

};

#endif // HOKUYO_H
