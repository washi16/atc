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
    s_viewer->setSceneRect(0,0,RectSize,RectSize);
    //ui->graphicsView->centerOn(250,250);
    _timer= new QTimer(this);
    connect(_timer,SIGNAL(timeout()),this,SLOT(timer_slot()));
    _timer->start(75);
    s_viewer->setBackgroundBrush(QBrush(Qt::black));
    backbgrond_color1=new QColor(Qt::black);
    backbgrond_color2=new QColor(Qt::white);
    backgroung_B=new QBrush (*backbgrond_color1);
    Glines_P=new QPen (Qt::white);
    formsP=new QPen (Qt::green);
    linesP=new QPen (Qt::blue);
    redP=new QPen (Qt::red);
    formsP->setWidth(2);
    redP->setWidth(4);
    //Glines_P->setStyle(Qt::DashDotDotLine);
    multi=Multi;
    s_flag=0;
    ui->Stop->hide();
    zoom=0;


}

MainWindow::~MainWindow()
{
    delete backbgrond_color1;
    delete backbgrond_color2;
    delete backgroung_B;
    delete Glines_P;
    delete formsP;
    delete linesP;
    delete redP;
    delete dados_f;
    delete s_viewer;
    delete _timer;
    delete ui;
}

void MainWindow::draw_frame( vector<ponto<long int>> pontos)
{
    multi=ui->v_multi->value();

    s_viewer->addLine(zero,zero,zero+(pontos[0].get_X()/multi),zero+(pontos[0].get_Y()/(-1*multi)),*formsP);

    for(unsigned int i=0;i<(pontos.size()-2);i++)
    {
        //cout<<"Angulos:"<<dados_f->m_vecAngulos[i]<<"X:"<<pontos[i].get_X()<<" Y:"<<pontos[i].get_Y()<<endl;
        if(ui->laser->isChecked())
        s_viewer->addLine(zero,zero,zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),*linesP);
        s_viewer->addLine(zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),zero+(pontos[i+1].get_X()/multi),zero+(pontos[i+1].get_Y()/(-1*multi)),*formsP);

    }
    s_viewer->addLine(zero,zero,zero+(pontos[pontos.size()-2].get_X()/multi),zero+(pontos[pontos.size()-2].get_Y())/(-1*multi),*formsP);
    s_viewer->addLine(zero,zero,zero,zero,*redP);


}



void MainWindow::on_Background_clicked()
{
    if(!ui->Pause->isChecked())
    {
    if(backgroung_B->color()==*backbgrond_color1)
    {
        backgroung_B->setColor(*backbgrond_color2);
        Glines_P->setColor(*backbgrond_color1);
        s_viewer->setBackgroundBrush(*backgroung_B);
    }
    else
    {
        backgroung_B->setColor(*backbgrond_color1);
        Glines_P->setColor(*backbgrond_color2);
        s_viewer->setBackgroundBrush(*backgroung_B);
    }
    }

}

void MainWindow::timer_slot()
{

    if(!ui->Pause->isChecked())
    {
        s_viewer->clear();
        if(this->s_flag)
        {
            read_log_file();
        }
        else
        {
        if(ui->Guide->isChecked())
        draw_Glines();

        if(ui->Disable_0->isChecked())
            draw_frame_w_0(dados_f->get_pontos((char)ui->Filter->isChecked()));
        else
            draw_frame(dados_f->get_pontos((char)ui->Filter->isChecked()));
        }
    }
}

void MainWindow::draw_Glines()
{
    for(int i=0,j=0;i<=10000;i+=500,j++)
    {
    if(j%4==0)
    {
        Glines_P->setWidth(4);
        //Glines_P->setStyle(Qt::DashDotDotLine);
        s_viewer->addEllipse(zero-i/multi/2,zero-(i/multi)/2,i/multi,i/multi,*Glines_P);
        //Glines_P->setStyle(Qt::SolidLine);
        Glines_P->setWidth(1);
    }
    else
    s_viewer->addEllipse(zero-i/multi/2,zero-(i/multi)/2,i/multi,i/multi,*Glines_P);
    }
}


void MainWindow::draw_frame_w_0(vector<ponto<long int>> pontos)
{
    int flag=0;
    long int x_old=0,y_old=0,x_next=0,y_next=0,x=0,y=0;
    multi=ui->v_multi->value();

    s_viewer->addLine(zero,zero,zero+(pontos[0].get_X()/multi),zero+(pontos[0].get_Y()/(-1*multi)),*formsP);
    for(unsigned int i=0;i<(pontos.size()-2);i++)
    {
        x=pontos[i].get_X();
        y=pontos[i].get_Y();
        x_next=pontos[i+1].get_X();
        y_next=pontos[i+1].get_Y();
        //if(x>-5 && x<5)x=0;
        //if(y>-5 && y<5)x=0;
        if(!flag && (x && y) && (x_next && y_next) )
                {
                    s_viewer->addLine(zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),zero+(pontos[i+1].get_X()/multi),zero+(pontos[i+1].get_Y()/(-1*multi)),*formsP);
                    if(ui->laser->isChecked())
                    s_viewer->addLine(zero,zero,zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),*linesP);
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
                 s_viewer->addLine(zero+(x_old/multi),zero+(y_old/(-1*multi)),zero+(x/multi),zero+(y/(-1*multi)),*formsP);
                 s_viewer->addLine(zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),zero+(pontos[i+1].get_X()/multi),zero+(pontos[i+1].get_Y()/(-1*multi)),*formsP);
                 if(ui->laser->isChecked())
                 s_viewer->addLine(zero,zero,zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),*linesP);
                }
        else if (flag && (x && y))
                {
                 s_viewer->addLine(zero+(x_old/multi),zero+(y_old/(-1*multi)),zero+(x/multi),zero+(y/(-1*multi)),*formsP);
                 if(ui->laser->isChecked())
                 s_viewer->addLine(zero,zero,zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),*linesP);
                 x_old=x;
                 y_old=y;
                }

        //cout<<"Angulos:"<<dados_f->m_vecAngulos[i]<<"X:"<<pontos[i].get_X()<<" Y:"<<pontos[i].get_Y()<<endl;

    }
    s_viewer->addLine(zero,zero,zero+(pontos[pontos.size()-2].get_X()/multi),zero+(pontos[pontos.size()-2].get_Y())/(-1*multi),*formsP);
    s_viewer->addLine(zero,zero,zero,zero,*redP);
}

void MainWindow::on_scale_1_clicked()
{
    if(zoom<1)
    {
    ui->graphicsView->scale(2,2);
    ui->graphicsView->setSceneRect(0,0,RectSize,RectSize);
    ui->graphicsView->centerOn(zero,zero);
    zoom++;
    }
}

void MainWindow::on_scale_2_clicked()
{
    if(zoom>-5)
    {
    ui->graphicsView->scale(0.5,0.5);
    ui->graphicsView->setSceneRect(0,0,RectSize,RectSize);
    ui->graphicsView->centerOn(zero,zero);
    zoom--;
    }
}

void MainWindow::on_actionSave_to_File_triggered()
{
        ui->Pause->setCheckState(Qt::Checked);
        QMessageBox msg;
        QString fileName = QFileDialog::getSaveFileName(this,"Select File","/home/carlos/Desktop/untitled.csv","Calc Cels ( *csv *xls)");
        if(dados_f->save_frame(fileName))
            msg.setText("Save Complete!");
        else
            msg.setText("Save Aborted! Try Again!");
            msg.show();
            msg.exec();
        ui->Pause->setCheckState(Qt::Unchecked);
}

void MainWindow::on_actionSave_Image_triggered()
{
        ui->Pause->setCheckState(Qt::Checked);
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
        ui->graphicsView->setSceneRect(0,0,RectSize,RectSize);
        QPainter painter(&image);
        s_viewer->render(&painter);
       if(image.save(fileName))
       {
        msg.setText("Save Complete!");
        msg.exec();
       }
       else
       {
           msg.setText("Save Aborted!");
           msg.exec();
       }
         ui->Pause->setCheckState(Qt::Unchecked);

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
    s_viewer->addLine(zero,zero,zero+(pontos[0].get_X()/multi),zero+(pontos[0].get_Y()/(-1*multi)),*formsP);
    for(int i=0;i<(pontos.size()-2);i++)
    {
        x=pontos[i].get_X();
        y=pontos[i].get_Y();
        x_next=pontos[i+1].get_X();
        y_next=pontos[i+1].get_Y();
        if(!flag && (x||y) && (x_next||y_next) )
                {
                    s_viewer->addLine(zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),zero+(pontos[i+1].get_X()/multi),zero+(pontos[i+1].get_Y()/(-1*multi)),*formsP);
                    if(ui->laser->isChecked())
                    s_viewer->addLine(zero,zero,zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),*linesP);
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
                 s_viewer->addLine(zero+(x_old/multi),zero+(y_old/(-1*multi)),zero+(x/multi),zero+(y/(-1*multi)),*formsP);
                 s_viewer->addLine(zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),zero+(pontos[i+1].get_X()/multi),zero+(pontos[i+1].get_Y()/(-1*multi)),*formsP);
                 if(ui->laser->isChecked())
                 s_viewer->addLine(zero,zero,zero+(pontos[i].get_X()/multi),zero+(pontos[i].get_Y()/(-1*multi)),*linesP);
                }
        else if (flag && (x||y) && !x_next && !y_next)
                {
                 s_viewer->addLine(zero+(x_old/multi),zero+(y_old/(-1*multi)),zero+(x/multi),zero+(y/(-1*multi)),*formsP);
                 x_old=x;
                 y_old=y;
                }
        //cout<<"Angulos:"<<dados_f->m_vecAngulos[i]<<"X:"<<pontos[i].get_X()<<" Y:"<<pontos[i].get_Y()<<endl;

    }
    s_viewer->addLine(zero,zero,zero+(pontos[pontos.size()-2].get_X()/multi),zero+(pontos[pontos.size()-2].get_Y())/(-1*multi),*formsP);
    s_viewer->addLine(zero,zero,zero,zero,*redP);
}

 */


void MainWindow::on_actionBackground_Color_1_triggered()
{   if(!ui->Pause->isChecked())
    {
    ui->Pause->setCheckState(Qt::Checked);
    *backbgrond_color1=QColorDialog::getColor(*backbgrond_color1,this);
    this->Glines_P->setColor(*backbgrond_color2);
    backgroung_B->setColor(*backbgrond_color1);
    s_viewer->setBackgroundBrush(*backgroung_B);
    ui->Pause->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_actionBackground_Color_2_triggered()
{
    if(!ui->Pause->isChecked())
    {
    ui->Pause->setCheckState(Qt::Checked);
    *backbgrond_color2=QColorDialog::getColor(*backbgrond_color2,this);
    ui->Pause->setCheckState(Qt::Unchecked);
    if(Glines_P->color()!=*backbgrond_color1)
        Glines_P->setColor(*backbgrond_color2);
    }
}

void MainWindow::on_actionLaser_Color_triggered()
{
    if(!ui->Pause->isChecked())
    {
    ui->Pause->setCheckState(Qt::Checked);
    linesP->setColor(QColorDialog::getColor(linesP->color(),this));
    ui->Pause->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_actionForms_Color_triggered()
{
    if(!ui->Pause->isChecked())
    {
    ui->Pause->setCheckState(Qt::Checked);
    formsP->setColor(QColor (QColorDialog::getColor(formsP->color(),this)));
    ui->Pause->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionDefault_Colors_triggered()
{
    *backbgrond_color1=Qt::black;
    *backbgrond_color2=Qt::white;
    Glines_P->setColor(*backbgrond_color2);
    linesP->setColor(Qt::blue);
    formsP->setColor(Qt::green);
    backgroung_B->setColor(*backbgrond_color1);
    s_viewer->setBackgroundBrush(QBrush (*backgroung_B));
}

void MainWindow::on_actionOpen_Log_triggered()
{

    if(s_flag==1)
    {
        ui->Pause->setCheckState(Qt::Checked);
        QMessageBox::StandardButton select;
        QMessageBox msg;
        select=QMessageBox::question(this,"Warning","A File is already Open \n Do you want to close it?",QMessageBox::Yes|QMessageBox::No);
        if(select==QMessageBox::No)
        {
            ui->Pause->setCheckState(Qt::Unchecked);
            return;
        }
         on_Background_clicked();
    }
    on_Background_clicked();
    ui->Pause->setCheckState(Qt::Checked);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Save File"),"logs/",tr("Calc cells (*.csv)"));
    log_file=new QFile(fileName);
    if(!log_file->open(QIODevice::ReadOnly))
    {
        QMessageBox msg;
        msg.setText("Log file reading error!");
        msg.exec();
        on_Background_clicked();
        return;
    }
    stream_in =new QTextStream(log_file);
    ui->Stop->show();
    s_flag=1;
    _timer->setInterval(100);

}

void MainWindow::read_log_file()
{


    s_viewer->clear();
    QString str;
    QStringList strlist;


    if(!log_file->atEnd() && s_flag)
    {
        s_viewer->clear();
        if(ui->Guide->isChecked())
            draw_Glines();;
        str=stream_in->readLine();
        strlist=str.split("\t");
        dados_f->get_pontos_log((char)ui->Filter->isChecked(),strlist);
        draw_frame(dados_f->get_pontos_log((char)ui->Filter->isChecked(),strlist));
        return;
    }
    log_file->close();
    s_flag=0;
    _timer->setInterval(75);
    ui->Stop->hide();
    on_Background_clicked();

}


void MainWindow::on_actionDelete_Logs_triggered()
{
    ui->Pause->setCheckState(Qt::Checked);
    QMessageBox::StandardButton select;
    QMessageBox msg;
    select=QMessageBox::question(this,"Warning","Are you sure?",QMessageBox::Yes|QMessageBox::No);
    if(select==QMessageBox::Yes)
    {
    system("rm logs/*");
    msg.setText("Files Deleted!");
    msg.exec();
    ui->Pause->setCheckState(Qt::Unchecked);
    return;
    }
    msg.setText("Operation Aborted!");
    msg.exec();
    ui->Pause->setCheckState(Qt::Unchecked);
    return;
}

void MainWindow::on_actionOpen_Logs_Folder_triggered()
{
    system("xdg-open ./logs/");
}

void MainWindow::on_actionBackup_Logs_triggered()
{
    ui->menuEdit->show();
    ui->Pause->setCheckState(Qt::Checked);
    QString fileName = QFileDialog::getExistingDirectory(this, tr("Select Folder"),"/home/carlos/",QFileDialog::ShowDirsOnly);
    string str="cp ./logs/* "+fileName.toStdString();
    system(str.c_str());
    ui->Pause->setCheckState(Qt::Unchecked);
}

void MainWindow::on_Stop_clicked()
{
    log_file->close();
    s_flag=0;
     _timer->setInterval(75);
    ui->Stop->hide();
    on_Background_clicked();

}




