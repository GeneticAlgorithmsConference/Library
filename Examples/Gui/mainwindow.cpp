#include "mainwindow.h"
#include "../../Sources/treeexpressionindividual.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui -> btStart, SIGNAL(clicked()), this, SLOT(btnStart()));
    connect(ui -> btStop, SIGNAL(clicked()), this, SLOT(btnStop()));
    connect(ui -> btPause, SIGNAL(clicked()), this, SLOT(btnPause()));
    connect(ui -> btContinue, SIGNAL(clicked()), this, SLOT(btnContinue()));
    connect(ui -> btApllySets, SIGNAL(clicked()), this, SLOT(apllySets()));
    connect(ui -> sbInterval, SIGNAL(editingFinished()), this, SLOT(applySpeed()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerEvent()));


    int rowsNum = ui -> samplesNumEdit -> value();
    ui -> samplesTable -> setRowCount(rowsNum);
    for(int i = 0; i < rowsNum; ++i)
    {
        ui -> samplesTable -> setItem(i, 0, new QTableWidgetItem(QString::number(0.0)));
        ui -> samplesTable -> setItem(i, 1, new QTableWidgetItem(QString::number(0.0)));
    }

    timer.setInterval(200);
    timer.stop();

    ui -> lStatus -> setText("<font color=\"red\">Stopped</font>");
    apllySets();
}

MainWindow::~MainWindow()
{
    delete ui;

    if(generation != NULL)
        delete generation;
}


void MainWindow::applySpeed()
{
    timer.setInterval(ui -> sbInterval -> value());
}

void MainWindow::timerEvent()
{
    ui -> lcdGeneration -> display(ui -> lcdGeneration -> value() + 1);
    generation -> genNext();

    TreeExpressionIndividual* bestres = generation -> getIndividualBest();
    ui -> lcdBestScore -> display(bestres -> getScore());
    int r = ui -> tableWidget -> rowCount();
    ui -> tableWidget -> setRowCount(r + 1);
    ui -> tableWidget-> setCurrentCell(r, 1);
    ui -> tableWidget -> setItem(r, 0, new QTableWidgetItem(QString::fromStdString(bestres -> getDna().print())));
    ui -> tableWidget -> setItem(r, 1, new QTableWidgetItem(QString::number(bestres -> getScore())));
}

void MainWindow::btnStart()
{
    std::string fnc = ui -> tbFunction -> text().toStdString();
    if(!minSearchParser.parse(fnc))
    {
        QMessageBox mb;
        mb.setIcon(QMessageBox::Critical);
        mb.setText("Irregular expression!");
        mb.exec();
        return;
    }

    std::vector < std::pair <double, double> > tests;
    for(int i = 0; i < ui -> samplesTable -> rowCount(); ++i)
    {
        tests.push_back(std::make_pair(ui -> samplesTable -> item(i, 0) -> text().toInt(),
                                       ui -> samplesTable -> item(i, 1) -> text().toInt()));
    }
    TreeExpressionIndividual::setTests(tests);

    if(generation != NULL)
        delete generation;

    generation = new Genetic::Generation< TreeExpressionIndividual >
            (ui -> sbSize -> value(), &geneticSettings);
    generation -> init(time(NULL), 1);

    ui -> lcdGeneration -> display(0);

    ui -> btPause -> setEnabled(true);
    ui -> btContinue -> setEnabled(false);
    ui -> btStop -> setEnabled(true);
    ui -> btStart -> setEnabled(false);

    ui -> gbSize -> setEnabled(false);
    ui -> gbFunction -> setEnabled(false);

    timer.start();
    ui -> lStatus -> setText("<font color=\"green\">Running</font>");
    ui -> tableWidget -> clear();
    ui -> tableWidget -> setRowCount(0);
    ui -> tableWidget -> setHorizontalHeaderItem(0, new QTableWidgetItem(QString::fromUtf8("Function")));
    ui -> tableWidget -> setHorizontalHeaderItem(1, new QTableWidgetItem(QString::fromUtf8("Result")));
}

void MainWindow::btnStop()
{
    ui -> btPause -> setEnabled(false);
    ui -> btContinue -> setEnabled(false);
    ui -> btStop -> setEnabled(false);
    ui -> btStart -> setEnabled(true);

    ui -> gbSize -> setEnabled(true);
    ui -> gbFunction -> setEnabled(true);

    timer.stop();
    ui -> lStatus -> setText("<font color=\"red\">Stopped</font>");
}

void MainWindow::btnPause()
{
    ui -> btPause -> setEnabled(false);
    ui -> btContinue -> setEnabled(true);
    ui -> btStop -> setEnabled(true);
    ui -> btStart -> setEnabled(false);

    timer.stop();
    ui -> lStatus -> setText("<font color=\"blue\">Paused</font>");
}


void MainWindow::btnContinue()
{
    ui -> btPause -> setEnabled(true);
    ui -> btContinue -> setEnabled(false);
    ui -> btStop -> setEnabled(true);
    ui -> btStart -> setEnabled(false);

    timer.start();
    ui -> lStatus -> setText("<font color=\"green\">Running</font>");
}

void MainWindow::apllySets()
{
    bool errFound = false;

    Genetic::RecombinationType rt;
    Genetic::ParentsSelectionType pt;
    Genetic::NewGenerationSelectionType st;

    if(ui -> cbRecombination -> currentIndex() == -1)
        errFound = true;
    else
        rt = (Genetic::RecombinationType)(0x100 + (ui -> cbRecombination -> currentIndex()));

    if(ui -> cbParentsSelection -> currentIndex() == -1)
        errFound = true;
    else
        pt = (Genetic::ParentsSelectionType)(0x300 + (ui -> cbParentsSelection -> currentIndex()));

    if(ui -> cbGenerationSelection -> currentIndex() == -1)
        errFound = true;
    else
        st = (Genetic::NewGenerationSelectionType)(0x200 + (ui -> cbGenerationSelection -> currentIndex()));

    if(!errFound)
    {
        geneticSettings.setGenerationSelectionParameter(ui -> sbSelectionParameter -> value());
        geneticSettings.setMutationAttempts(ui -> sbMaxMutations -> value());
        geneticSettings.setMutationParameter(ui -> sbMutationParameter -> value());
        geneticSettings.setMutationProbability(ui -> sbMutationProbability -> value() / 100.0);
        geneticSettings.setNewGenerationSelectionType(st);
        geneticSettings.setParentsSelectionType(pt);
        geneticSettings.setRecombinationParameter(ui -> sbRecombParam -> value());
        geneticSettings.setRecombinationType(rt);
    }
    else
    {
        QMessageBox mb;
        mb.setIcon(QMessageBox::Critical);
        mb.setText("Genetic settings are incorrect and can`t be applied!");
        mb.exec();
    }
}

