#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QMessageBox>
#include "dados/dados.h"
#include "ponto/ponto.h"
#include "QColorDialog"



#define zero 250
#define Multi 10
#define RectSize 501

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_Background_clicked();

    void timer_slot(void);

    void on_scale_1_clicked();

    void on_scale_2_clicked();

    void on_actionSave_to_File_triggered();

    void on_actionSave_Image_triggered();

    void on_actionBackground_Color_1_triggered();

    void on_actionBackground_Color_2_triggered();

    void on_actionLaser_Color_triggered();

    void on_actionForms_Color_triggered();

    void on_actionExit_triggered();

    void on_actionDefault_Colors_triggered();

    void on_actionOpen_Log_triggered();

    void on_actionDelete_Logs_triggered();

    void on_actionOpen_Logs_Folder_triggered();

    void on_actionBackup_Logs_triggered();

    void on_Stop_clicked();


private:
    char s_flag;
    int zoom;
    int multi;
    QFile *log_file;
    Ui::MainWindow *ui;
    QTimer *_timer;
    dados *dados_f;
    QGraphicsScene *s_viewer;
    QGraphicsLineItem *line;
    QBrush *backgroung_B;
    QPen *Glines_P;
    QPen *formsP;
    QPen *redP;
    QPen *linesP;
    QColor *backbgrond_color1;
    QColor *backbgrond_color2;
    QTextStream *stream_in;


    void draw_frame(vector<ponto<long int>> pontos);
    void draw_frame_w_0(vector<ponto<long int>> pontos);
    void draw_Glines(void);
    void read_log_file();

};

#endif // MAINWINDOW_H
