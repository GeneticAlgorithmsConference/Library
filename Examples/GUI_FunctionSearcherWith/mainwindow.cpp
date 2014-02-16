#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui -> btApllySets, SIGNAL(clicked()), this, SLOT(apllySets()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::apllySets()
{
    bool errFound = false;
/*
    Genetic::RecombinationType rt;
    Genetic::ParentsSelectionType pt;
    Genetic::NewGenerationSelectionType st;
*/
    if(ui -> cbRecombination -> currentIndex() == -1)
        errFound = true;
 /*   else
        rt = (Genetic::RecombinationType)(0x100 + (ui -> cbRecombination -> currentIndex()));

    switch (cbParentsSelection) {
    case Genetic::

        break;
    default:
        errFound = true;
        break;
    }

    switch (cbRecombination) {
    case Genetic::

        break;
    default:
        errFound = true;
        break;
    }


    if(!errFound)
    {
        geneticSettings.setGenerationSelectionParameter();
        geneticSettings.setMutationAttempts();
        geneticSettings.setMutationParameter();
        geneticSettings.setMutationProbability();
        geneticSettings.setNewGenerationSelectionType();
        geneticSettings.setParentsSelectionType();
        geneticSettings.setRecombinationParameter();
        geneticSettings.setRecombinationType();
    }
    else*/
    {        
        QMessageBox mb;
        mb.setIcon(QMessageBox::Critical);
        mb.setText("Genetic settings are incorrect and can`t be applied!");
        mb.show();
    }
}

