#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hokuyo_class/hokuyo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->save->hide();
    ui->save_image->hide();
    dados_f=new dados;
    s_viewer =new QGraphicsScene(this);
    s_viewer->setSceneRect(0,0,501,501);
    ui->graphicsView->centerOn(250,250);
    ui->graphicsView->setScene(s_viewer);
    _timer= new QTimer(this);
    connect(_timer,SIGNAL(timeout()),this,SLOT(timer_slot()));
    _timer->start(75);
    s_viewer->setBackgroundBrush(QBrush(Qt::black));
    backgroung_B=new QBrush (Qt::black);
    lines_P=new QPen (Qt::white);
    greenP=new QPen (Qt::green);
    blueP=new QPen (Qt::blue);
    redP=new QPen (Qt::red);
    greenP->setWidth(2);
    redP->setWidth(4);
    //lines_P->setStyle(Qt::DashDotDotLine);
    multi=10;



}

MainWindow::~MainWindow()
{
    delete dados_f;
    delete s_viewer;
    delete _timer;
    delete ui;
}

void MainWindow::draw_frame(void)
{
    multi=ui->v_multi->value();
    vector<ponto<long int>> pontos =dados_f->get_pontos();


    s_viewer->addLine(zero,zero,zero+(pontos[0].get_X()/multi),zero+(pontos[0].get_Y()/(-1*multi)),*greenP);
    for(int i=0;i<(pontos.size()-2);i++)
    {
        //cout<<"Angulos:"<<dados_f->m_vecAngulos[i]<<"X:"<<pontos[i].get_X()<<" Y:"<<pontos[i].get_Y()<<endl;
        if(ui->Layser->isChecked())
        s_viewer->addLine(zero,zero,zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),*blueP);
        s_viewer->addLine(zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),zero+(pontos[i+1].get_X()/multi),zero+(pontos[i+1].get_Y()/(-1*multi)),*greenP);

    }
    s_viewer->addLine(zero,zero,zero+(pontos[pontos.size()-2].get_X()/multi),zero+(pontos[pontos.size()-2].get_Y())/(-1*multi),*greenP);
    s_viewer->addLine(zero,zero,zero,zero,*redP);

}



void MainWindow::on_Background_clicked()
{
    if(backgroung_B->color()==(Qt::black))
    {
        backgroung_B->setColor(Qt::white);
        lines_P->setColor(Qt::black);
        s_viewer->setBackgroundBrush(*backgroung_B);
    }
    else
    {
        backgroung_B->setColor(Qt::black);
        lines_P->setColor(Qt::white);
        s_viewer->setBackgroundBrush(*backgroung_B);
    }

}

void MainWindow::timer_slot()
{

    if(!ui->Pause->isChecked())
    {
        s_viewer->clear();

        if(ui->Guide->isChecked())
        draw_Glines();

        if(ui->Disable_0->isChecked())
            draw_frame_w_0();
        else
            draw_frame();
    }
}

void MainWindow::draw_Glines()
{
    for(int i=1;i<=10000;i+=500)
    {
    s_viewer->addEllipse(zero-i/multi/2,zero-(i/multi)/2,i/multi,i/multi,*lines_P);
    }
}


void MainWindow::on_save_clicked()
{
    QMessageBox msg;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"/home/carlos/Desktop/untitled.csv",tr("Calc cells (*.csv *.xls)"));
    if(dados_f->save_frame(fileName))
        msg.setText("Save Complete!");
    else
        msg.setText("Save Aborted! Try Again!");
        msg.show();
        msg.exec();
}


void MainWindow::on_Pause_clicked()
{
    if(ui->Pause->isChecked())
    {
        ui->save->show();
        ui->save_image->show();
    }
    else
    {
        ui->save->hide();
        ui->save_image->hide();
    }
}

void MainWindow::draw_frame_w_0()
{
    int flag=0;
    long int x_old=0,y_old=0,x_next=0,y_next=0,x=0,y=0;
    multi=ui->v_multi->value();
    vector<ponto<long int>> pontos =dados_f->get_pontos();

    s_viewer->addLine(zero,zero,zero+(pontos[0].get_X()/multi),zero+(pontos[0].get_Y()/(-1*multi)),*greenP);
    for(int i=0;i<(pontos.size()-2);i++)
    {
        x=pontos[i].get_X();
        y=pontos[i].get_Y();
        x_next=pontos[i+1].get_X();
        y_next=pontos[i+1].get_Y();
        if(!flag && (x && y) && (x_next && y_next) )
                {
                    s_viewer->addLine(zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),zero+(pontos[i+1].get_X()/multi),zero+(pontos[i+1].get_Y()/(-1*multi)),*greenP);
                    if(ui->Layser->isChecked())
                    s_viewer->addLine(zero,zero,zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),*blueP);
                }
        else if(!flag && (x && y) && (!x_next || !y_next))
                {
                 flag=1;
                 x_old=x;
                 y_old=y;
                }
        else if (flag && (x && y) && (x_next && y_next))
                {
                 flag=0;
                 s_viewer->addLine(zero+(x_old/multi),zero+(y_old/(-1*multi)),zero+(x/multi),zero+(y/(-1*multi)),*greenP);
                 s_viewer->addLine(zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),zero+(pontos[i+1].get_X()/multi),zero+(pontos[i+1].get_Y()/(-1*multi)),*greenP);
                 if(ui->Layser->isChecked())
                 s_viewer->addLine(zero,zero,zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),*blueP);
                }
        else if (flag && (x && y))
                {
                 s_viewer->addLine(zero+(x_old/multi),zero+(y_old/(-1*multi)),zero+(x/multi),zero+(y/(-1*multi)),*greenP);
                 if(ui->Layser->isChecked())
                 s_viewer->addLine(zero,zero,zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),*blueP);
                 x_old=x;
                 y_old=y;
                }

        //cout<<"Angulos:"<<dados_f->m_vecAngulos[i]<<"X:"<<pontos[i].get_X()<<" Y:"<<pontos[i].get_Y()<<endl;

    }
    s_viewer->addLine(zero,zero,zero+(pontos[pontos.size()-2].get_X()/multi),zero+(pontos[pontos.size()-2].get_Y())/(-1*multi),*greenP);
    s_viewer->addLine(zero,zero,zero,zero,*redP);
}

void MainWindow::on_actionSave_to_file_triggered()
{
    on_save_clicked();
}

void MainWindow::on_save_image_clicked()
{
    /*
    QGraphicsPixmapItem *pixmapitem=new QGraphicsPixmapItem;
    QImage image=s_viewer->render();
    image.save(&fileName);

    QImage image;
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    s_viewer->render(&painter);
    image.save("/home/carlos/image.png");
    */
    QMessageBox msg;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"),"/home/carlos/Desktop/untitled.png",tr("Image Files (*.jpg *.jpeg *png)"));
    s_viewer->clearSelection();
    s_viewer->setSceneRect(s_viewer->itemsBoundingRect());
    QImage image(s_viewer->sceneRect().size().toSize(),QImage::Format_ARGB32);
    image.fill(Qt::transparent);

    QPainter painter(&image);
    s_viewer->render(&painter);
    image.save(fileName);
    msg.setText("Save Complete!");
    msg.exec();
}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->centerOn(250,250);
}

void MainWindow::on_scale_1_clicked()
{
    ui->graphicsView->scale(0.5,0.5);
}

void MainWindow::on_scale_2_clicked()
{
    ui->graphicsView->scale(2,2);
}

void MainWindow::on_actionSave_to_File_triggered()
{
    on_save_clicked();
}

void MainWindow::on_actionSave_Image_triggered()
{
    on_save_image_clicked();
}


/*
void MainWindow::draw_frame_w_0()
{
    int flag=0;
    long int x_old=0,y_old=0,x_next=0,y_next=0,x=0,y=0;
    multi=ui->v_multi->value();
    vector<ponto<long int>> pontos =dados_f->get_pontos();
    s_viewer->clear();
    draw_Glines();
    s_viewer->addLine(zero,zero,zero+(pontos[0].get_X()/multi),zero+(pontos[0].get_Y()/(-1*multi)),*greenP);
    for(int i=0;i<(pontos.size()-2);i++)
    {
        x=pontos[i].get_X();
        y=pontos[i].get_Y();
        x_next=pontos[i+1].get_X();
        y_next=pontos[i+1].get_Y();
        if(!flag && (x||y) && (x_next||y_next) )
                {
                    s_viewer->addLine(zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),zero+(pontos[i+1].get_X()/multi),zero+(pontos[i+1].get_Y()/(-1*multi)),*greenP);
                    if(ui->Layser->isChecked())
                    s_viewer->addLine(zero,zero,zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),*blueP);
                }
        else if(!flag && (x || y) && !x_next && !y_next)
                {
                 flag=1;
                 x_old=x;
                 y_old=y;
                }
        else if (flag && (x||y) && (x_next||y_next))
                {
                 flag=0;
                 s_viewer->addLine(zero+(x_old/multi),zero+(y_old/(-1*multi)),zero+(x/multi),zero+(y/(-1*multi)),*greenP);
                 s_viewer->addLine(zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),zero+(pontos[i+1].get_X()/multi),zero+(pontos[i+1].get_Y()/(-1*multi)),*greenP);
                 if(ui->Layser->isChecked())
                 s_viewer->addLine(zero,zero,zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),*blueP);
                }
        else if (flag && (x||y) && !x_next && !y_next)
                {
                 s_viewer->addLine(zero+(x_old/multi),zero+(y_old/(-1*multi)),zero+(x/multi),zero+(y/(-1*multi)),*greenP);
                 x_old=x;
                 y_old=y;
                }
        //cout<<"Angulos:"<<dados_f->m_vecAngulos[i]<<"X:"<<pontos[i].get_X()<<" Y:"<<pontos[i].get_Y()<<endl;

    }
    s_viewer->addLine(zero,zero,zero+(pontos[pontos.size()-2].get_X()/multi),zero+(pontos[pontos.size()-2].get_Y())/(-1*multi),*greenP);
    s_viewer->addLine(zero,zero,zero,zero,*redP);
}

 */
