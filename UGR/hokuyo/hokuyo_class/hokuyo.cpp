#include "hokuyo.h"



hokuyo::hokuyo()
{
    if(!urg.connect("/dev/ttyACM0"))
   {
        QMessageBox msg;
        msg.setText("UrgCTRL::Connect"+(QString)urg.what()+"\nLidar não encontrado!");
        msg.exec();
        exit(1);
   }
    Angles_config();
}

hokuyo::hokuyo(char *str)
{
    if(!urg.connect(str))
   {   QMessageBox msg;
       msg.setText("UrgCTRL::Connect"+(QString)urg.what()+"\nLidar não encontrado!");
       msg.exec();
       exit(1);
   }
   hokuyo_scan();
   Angles_config();
}

void hokuyo::Angles_config()
{
    angles_from_0();
}

void hokuyo::angles_from_0()
{
    //anglos 0 a partie do eixo (Configura angle_vector para valores dos angulos );
    for (int i=1;i<=ANGLES;i++)
  {
     if(i<=83)angle_vector.push_back(329.12+i*LAYSER_DISTANCE);
     else angle_vector.push_back(i*LAYSER_DISTANCE-30);
     //cout<<angle_vector[i]<<endl;
  }

}

void hokuyo::angles_from_begin()
{
    //anglos 0 a partir do anglo morto;


     for(int i=1;i<=distance_vector.size();i++)
    {
        angle_vector[i-1]=i*LAYSER_DISTANCE;
        //cout<<angle_vector[i-1]<<endl;
    }

}

void hokuyo::angles_from_front()
{
    for (int i=1;i<=ANGLES;i++)
  {
     if(i<=341)angle_vector.push_back(-120+i*LAYSER_DISTANCE);
     else angle_vector.push_back((i-342)*LAYSER_DISTANCE);
     //cout<<angle_vector[i]<<endl;
  }
}

void hokuyo::hokuyo_scan()
{
    timestamp = 0;
    numb_data = urg.capture(distance_vector,&timestamp);

    if(numb_data<0) // Nao executou a leitura sai do programa
    {
        QMessageBox msg;
        msg.setText("UrgCTRL::Connect"+(QString)urg.what()+"\nLidar foi desconectado!");
        msg.exec();
        exit(1);
    }

    for(int i=0;i<=ERASE;i++)
    {
        distance_vector.erase(distance_vector.begin());
    }

    //centimeros
    /*
     for(int i=0;i<=distance_vector.size();i++)
      distance_vector[i]=(distance_vector[i]/10);
    */

}

vector<long int> hokuyo::new_scan()
{
    hokuyo_scan();
    return distance_vector;
}

vector<long int> hokuyo::get_distance_vector()const
{
    return distance_vector;
}

vector<double> hokuyo::get_angle_vector()const
{
    return angle_vector;
}


/*
 vector<int,int> hokuyo::get_position(int x,int y)
{
   for(int i=0;i<=ANGLES;i++)
   {
       position.push_back(pair(),(y+distance_vector[i]*sin(angle_vector[i])));
   }
   return position;
}
*/

