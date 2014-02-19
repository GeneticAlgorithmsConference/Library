#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <time.h>

#include <QWidget>
#include <QMessageBox>
#include <QTimer>
#include <QTableWidgetItem>

#include "../../Sources/genetic.h"
#include "../../Sources/geneticsettings.h"
#include "../../Sources/generation.h"
#include "../../Sources/minsearchindividual.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QTimer timer;

    Genetic::GeneticSettings geneticSettings;
    Genetic::Generation < Genetic::MinSearchIndividual >* generation;

public slots:

    void apllySets();
    void btnStart();
    void btnPause();
    void btnStop();
    void btnContinue();
    void applySpeed();
    void timerEvent();
};

#endif // MAINWINDOW_H
