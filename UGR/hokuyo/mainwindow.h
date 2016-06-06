#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QMessageBox>
#include "dados/dados.h"
#include "Timer/timer.h"
#include "ponto/ponto.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    timer *_timer;
    dados *dados_f;

    bool draw_frame(void);
    Ui::MainWindow *ui;
    QGraphicsScene *s_viewer;
    QGraphicsLineItem *line;
};

#endif // MAINWINDOW_H
