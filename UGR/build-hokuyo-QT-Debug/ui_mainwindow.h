/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionSave_to_File;
    QAction *actionSave_Image;
    QAction *actionBackground_Color_1;
    QAction *actionBackground_Color_2;
    QAction *actionLayser_Color;
    QAction *actionForms_Color;
    QAction *actionDefault_Colors;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *Background;
    QCheckBox *Pause;
    QSlider *v_multi;
    QCheckBox *Layser;
    QCheckBox *Disable_0;
    QCheckBox *Guide;
    QPushButton *pushButton;
    QPushButton *scale_1;
    QPushButton *scale_2;
    QCheckBox *Filter;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuColor;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(682, 614);
        MainWindow->setMinimumSize(QSize(682, 614));
        MainWindow->setMaximumSize(QSize(682, 614));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSave_to_File = new QAction(MainWindow);
        actionSave_to_File->setObjectName(QStringLiteral("actionSave_to_File"));
        actionSave_Image = new QAction(MainWindow);
        actionSave_Image->setObjectName(QStringLiteral("actionSave_Image"));
        actionBackground_Color_1 = new QAction(MainWindow);
        actionBackground_Color_1->setObjectName(QStringLiteral("actionBackground_Color_1"));
        actionBackground_Color_2 = new QAction(MainWindow);
        actionBackground_Color_2->setObjectName(QStringLiteral("actionBackground_Color_2"));
        actionLayser_Color = new QAction(MainWindow);
        actionLayser_Color->setObjectName(QStringLiteral("actionLayser_Color"));
        actionForms_Color = new QAction(MainWindow);
        actionForms_Color->setObjectName(QStringLiteral("actionForms_Color"));
        actionDefault_Colors = new QAction(MainWindow);
        actionDefault_Colors->setObjectName(QStringLiteral("actionDefault_Colors"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(110, 0, 550, 550));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setFrameShape(QFrame::StyledPanel);
        graphicsView->setLineWidth(3);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setInteractive(true);
        graphicsView->setRenderHints(QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);
        Background = new QPushButton(centralWidget);
        Background->setObjectName(QStringLiteral("Background"));
        Background->setGeometry(QRect(10, 0, 99, 27));
        Pause = new QCheckBox(centralWidget);
        Pause->setObjectName(QStringLiteral("Pause"));
        Pause->setGeometry(QRect(10, 60, 97, 22));
        Pause->setChecked(false);
        v_multi = new QSlider(centralWidget);
        v_multi->setObjectName(QStringLiteral("v_multi"));
        v_multi->setGeometry(QRect(70, 380, 29, 160));
        v_multi->setMinimum(1);
        v_multi->setMaximum(20);
        v_multi->setSingleStep(5);
        v_multi->setOrientation(Qt::Vertical);
        v_multi->setTickPosition(QSlider::TicksBelow);
        v_multi->setTickInterval(5);
        Layser = new QCheckBox(centralWidget);
        Layser->setObjectName(QStringLiteral("Layser"));
        Layser->setGeometry(QRect(10, 90, 97, 22));
        Disable_0 = new QCheckBox(centralWidget);
        Disable_0->setObjectName(QStringLiteral("Disable_0"));
        Disable_0->setGeometry(QRect(10, 120, 97, 22));
        Guide = new QCheckBox(centralWidget);
        Guide->setObjectName(QStringLiteral("Guide"));
        Guide->setGeometry(QRect(10, 150, 97, 22));
        QFont font;
        font.setPointSize(10);
        Guide->setFont(font);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 30, 99, 27));
        scale_1 = new QPushButton(centralWidget);
        scale_1->setObjectName(QStringLiteral("scale_1"));
        scale_1->setGeometry(QRect(70, 276, 31, 31));
        scale_2 = new QPushButton(centralWidget);
        scale_2->setObjectName(QStringLiteral("scale_2"));
        scale_2->setGeometry(QRect(70, 310, 31, 31));
        Filter = new QCheckBox(centralWidget);
        Filter->setObjectName(QStringLiteral("Filter"));
        Filter->setGeometry(QRect(10, 180, 97, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 280, 61, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 306, 61, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 682, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuColor = new QMenu(menuEdit);
        menuColor->setObjectName(QStringLiteral("menuColor"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(v_multi, Background);
        QWidget::setTabOrder(Background, Pause);
        QWidget::setTabOrder(Pause, Layser);
        QWidget::setTabOrder(Layser, Disable_0);
        QWidget::setTabOrder(Disable_0, graphicsView);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionSave_to_File);
        menuFile->addAction(actionSave_Image);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(menuColor->menuAction());
        menuColor->addAction(actionBackground_Color_1);
        menuColor->addAction(actionBackground_Color_2);
        menuColor->addAction(actionLayser_Color);
        menuColor->addAction(actionForms_Color);
        menuColor->addSeparator();
        menuColor->addAction(actionDefault_Colors);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lidar", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionSave_to_File->setText(QApplication::translate("MainWindow", "Save to File", 0));
        actionSave_to_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionSave_Image->setText(QApplication::translate("MainWindow", "Save Image", 0));
        actionSave_Image->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionBackground_Color_1->setText(QApplication::translate("MainWindow", "Background Color 1", 0));
        actionBackground_Color_2->setText(QApplication::translate("MainWindow", "Background Color 2", 0));
        actionLayser_Color->setText(QApplication::translate("MainWindow", "Layser Color", 0));
        actionForms_Color->setText(QApplication::translate("MainWindow", "Forms Color", 0));
        actionDefault_Colors->setText(QApplication::translate("MainWindow", "Default Colors", 0));
        Background->setText(QApplication::translate("MainWindow", "Background", 0));
        Pause->setText(QApplication::translate("MainWindow", "Pause", 0));
        Layser->setText(QApplication::translate("MainWindow", "Layser", 0));
        Disable_0->setText(QApplication::translate("MainWindow", "Disable '0'", 0));
        Guide->setText(QApplication::translate("MainWindow", "Guide Lines", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Center Image", 0));
        scale_1->setText(QApplication::translate("MainWindow", "+", 0));
        scale_1->setShortcut(QApplication::translate("MainWindow", "+, +", 0));
        scale_2->setText(QApplication::translate("MainWindow", "-", 0));
        scale_2->setShortcut(QApplication::translate("MainWindow", "-, -", 0));
        Filter->setText(QApplication::translate("MainWindow", "Filter", 0));
        label->setText(QApplication::translate("MainWindow", "zoom :", 0));
        label_2->setText(QApplication::translate("MainWindow", "zoom :", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuColor->setTitle(QApplication::translate("MainWindow", "Color", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
