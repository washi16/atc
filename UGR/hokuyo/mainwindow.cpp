#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hokuyo_class/hokuyo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dados_f=new dados;

    s_viewer =new QGraphicsScene(this);
    ui->graphicsView->setScene(s_viewer);
    _timer=new timer;
    s_viewer->setBackgroundBrush(QBrush(Qt::black));
    QBrush redB(Qt::red);
    QBrush blueB(Qt::blue);
    QBrush greenB(Qt::green);
    QPen blackB(Qt::black);
    QPen whiteB(Qt::white);
    blackB.setWidth(6);

    vector<ponto<long int>> pontos =dados_f->get_pontos();

    //s_viewer->addLine(250,250,250+(pontos[0].get_X()/10),250+(pontos[0].get_X()/10),whiteB);
    for(int i=0;i<pontos.size();i++)
    {
        s_viewer->addLine(250+(pontos[i].get_X()/20),250+(pontos[i].get_Y()/20),250+(pontos[i+1].get_X()/20),250+(pontos[i+1].get_Y()/20),whiteB);
    }
    //s_viewer->addLine(250+(pontos[pontos.size()].get_X()/10),250+(pontos[pontos.size()].get_Y())/10,250,250,whiteB);

}

MainWindow::~MainWindow()
{
    delete dados_f;
    delete s_viewer;
    delete _timer;
    delete ui;
}

bool MainWindow::draw_frame(void)
{
   //QGraphicsScene *imagem=new QGraphicsScene;

    return true;
}
