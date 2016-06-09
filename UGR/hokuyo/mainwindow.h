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



#define zero 250

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

    void on_save_clicked();

    void on_Pause_clicked();

    void on_actionSave_to_file_triggered();

    void on_save_image_clicked();

    void on_pushButton_clicked();

    void on_scale_1_clicked();

    void on_scale_2_clicked();

    void on_actionSave_to_File_triggered();

    void on_actionSave_Image_triggered();

private:
    int multi;
    Ui::MainWindow *ui;
    QTimer *_timer;
    dados *dados_f;
    QGraphicsScene *s_viewer;
    QGraphicsLineItem *line;
    QBrush *backgroung_B;
    QPen *lines_P;
    QPen *greenP;
    QPen *redP;
    QPen *blueP;

    void draw_frame(void);
    void draw_frame_w_0(void);
    void draw_Glines(void);

};

#endif // MAINWINDOW_H
