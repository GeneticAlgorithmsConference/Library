#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QTimer>

#include "../../Sources/genetic.h"
#include "../../Sources/geneticSettings.h"
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

    void apllySets();
    void btnStart();
    void btnPause();
    void btnStop();
    void btnContinue();
};

#endif // MAINWINDOW_H
