/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *cbGenerationSelection;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *sbSelectionParameter;
    QLabel *label_3;
    QComboBox *cbParentsSelection;
    QComboBox *cbRecombination;
    QLabel *label_8;
    QDoubleSpinBox *sbRecombParam;
    QDoubleSpinBox *sbMutationParameter;
    QLabel *label_11;
    QDoubleSpinBox *sbMutationProbability;
    QLabel *label_1;
    QSpinBox *sbMaxMutations;
    QLabel *label_7;
    QLabel *label_6;
    QPushButton *btApllySets;
    QTableView *tableView;
    QGroupBox *gbFunction;
    QLineEdit *tbFunction;
    QLabel *label_2;
    QLCDNumber *lcdBestScore;
    QLCDNumber *lcdGeneration;
    QLabel *label_9;
    QLabel *label_10;
    QGroupBox *gbControl;
    QPushButton *btStart;
    QPushButton *btStop;
    QPushButton *btPause;
    QLabel *label;
    QPushButton *btContinue;
    QGroupBox *gbFiles;
    QPushButton *btSaveGeneration;
    QPushButton *btLoadGeneration;
    QGroupBox *gbFiles_2;
    QPushButton *btSaveGenetics;
    QPushButton *btLoadGenetics;
    QGroupBox *gbSize;
    QSpinBox *sbSize;
    QGroupBox *gbInterval;
    QSlider *sldInterval;
    QLabel *label_12;
    QLabel *label_13;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(820, 518);
        groupBox = new QGroupBox(MainWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 351, 291));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 21, 331, 241));
        gridLayout = new QGridLayout(formLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cbGenerationSelection = new QComboBox(formLayoutWidget);
        cbGenerationSelection->setObjectName(QStringLiteral("cbGenerationSelection"));
        cbGenerationSelection->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(cbGenerationSelection, 0, 1, 1, 1);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        sbSelectionParameter = new QDoubleSpinBox(formLayoutWidget);
        sbSelectionParameter->setObjectName(QStringLiteral("sbSelectionParameter"));
        sbSelectionParameter->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(sbSelectionParameter, 1, 1, 1, 1);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        cbParentsSelection = new QComboBox(formLayoutWidget);
        cbParentsSelection->setObjectName(QStringLiteral("cbParentsSelection"));
        cbParentsSelection->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(cbParentsSelection, 2, 1, 1, 1);

        cbRecombination = new QComboBox(formLayoutWidget);
        cbRecombination->setObjectName(QStringLiteral("cbRecombination"));
        cbRecombination->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(cbRecombination, 3, 1, 1, 1);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        sbRecombParam = new QDoubleSpinBox(formLayoutWidget);
        sbRecombParam->setObjectName(QStringLiteral("sbRecombParam"));
        sbRecombParam->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(sbRecombParam, 4, 1, 1, 1);

        sbMutationParameter = new QDoubleSpinBox(formLayoutWidget);
        sbMutationParameter->setObjectName(QStringLiteral("sbMutationParameter"));
        sbMutationParameter->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(sbMutationParameter, 7, 1, 1, 1);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_11, 7, 0, 1, 1);

        sbMutationProbability = new QDoubleSpinBox(formLayoutWidget);
        sbMutationProbability->setObjectName(QStringLiteral("sbMutationProbability"));
        sbMutationProbability->setMaximumSize(QSize(200, 16777215));
        sbMutationProbability->setMaximum(100);

        gridLayout->addWidget(sbMutationProbability, 6, 1, 1, 1);

        label_1 = new QLabel(formLayoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_1, 6, 0, 1, 1);

        sbMaxMutations = new QSpinBox(formLayoutWidget);
        sbMaxMutations->setObjectName(QStringLiteral("sbMaxMutations"));
        sbMaxMutations->setMaximumSize(QSize(200, 16777215));
        sbMaxMutations->setMaximum(1024);

        gridLayout->addWidget(sbMaxMutations, 5, 1, 1, 1);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        btApllySets = new QPushButton(groupBox);
        btApllySets->setObjectName(QStringLiteral("btApllySets"));
        btApllySets->setGeometry(QRect(10, 260, 331, 23));
        tableView = new QTableView(MainWindow);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(370, 100, 441, 411));
        gbFunction = new QGroupBox(MainWindow);
        gbFunction->setObjectName(QStringLiteral("gbFunction"));
        gbFunction->setGeometry(QRect(10, 350, 261, 161));
        tbFunction = new QLineEdit(gbFunction);
        tbFunction->setObjectName(QStringLiteral("tbFunction"));
        tbFunction->setGeometry(QRect(10, 20, 241, 20));
        label_2 = new QLabel(gbFunction);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 241, 121));
        lcdBestScore = new QLCDNumber(MainWindow);
        lcdBestScore->setObjectName(QStringLiteral("lcdBestScore"));
        lcdBestScore->setGeometry(QRect(670, 70, 131, 23));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        lcdBestScore->setPalette(palette);
        lcdBestScore->setSmallDecimalPoint(true);
        lcdBestScore->setDigitCount(10);
        lcdBestScore->setProperty("value", QVariant(0));
        lcdGeneration = new QLCDNumber(MainWindow);
        lcdGeneration->setObjectName(QStringLiteral("lcdGeneration"));
        lcdGeneration->setGeometry(QRect(490, 70, 51, 23));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        lcdGeneration->setPalette(palette1);
        lcdGeneration->setDigitCount(5);
        label_9 = new QLabel(MainWindow);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(570, 70, 91, 20));
        label_10 = new QLabel(MainWindow);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(390, 70, 111, 21));
        gbControl = new QGroupBox(MainWindow);
        gbControl->setObjectName(QStringLiteral("gbControl"));
        gbControl->setGeometry(QRect(370, 0, 441, 51));
        btStart = new QPushButton(gbControl);
        btStart->setObjectName(QStringLiteral("btStart"));
        btStart->setGeometry(QRect(120, 20, 71, 23));
        btStop = new QPushButton(gbControl);
        btStop->setObjectName(QStringLiteral("btStop"));
        btStop->setEnabled(false);
        btStop->setGeometry(QRect(360, 20, 71, 23));
        btPause = new QPushButton(gbControl);
        btPause->setObjectName(QStringLiteral("btPause"));
        btPause->setEnabled(false);
        btPause->setGeometry(QRect(280, 20, 71, 23));
        label = new QLabel(gbControl);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 61, 20));
        QPalette palette2;
        QBrush brush1(QColor(255, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        label->setPalette(palette2);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        btContinue = new QPushButton(gbControl);
        btContinue->setObjectName(QStringLiteral("btContinue"));
        btContinue->setEnabled(false);
        btContinue->setGeometry(QRect(200, 20, 71, 23));
        gbFiles = new QGroupBox(MainWindow);
        gbFiles->setObjectName(QStringLiteral("gbFiles"));
        gbFiles->setGeometry(QRect(280, 430, 81, 81));
        btSaveGeneration = new QPushButton(gbFiles);
        btSaveGeneration->setObjectName(QStringLiteral("btSaveGeneration"));
        btSaveGeneration->setGeometry(QRect(10, 20, 61, 23));
        btLoadGeneration = new QPushButton(gbFiles);
        btLoadGeneration->setObjectName(QStringLiteral("btLoadGeneration"));
        btLoadGeneration->setGeometry(QRect(10, 50, 61, 23));
        gbFiles_2 = new QGroupBox(MainWindow);
        gbFiles_2->setObjectName(QStringLiteral("gbFiles_2"));
        gbFiles_2->setGeometry(QRect(280, 350, 81, 81));
        btSaveGenetics = new QPushButton(gbFiles_2);
        btSaveGenetics->setObjectName(QStringLiteral("btSaveGenetics"));
        btSaveGenetics->setGeometry(QRect(10, 20, 61, 23));
        btLoadGenetics = new QPushButton(gbFiles_2);
        btLoadGenetics->setObjectName(QStringLiteral("btLoadGenetics"));
        btLoadGenetics->setGeometry(QRect(10, 50, 61, 23));
        gbSize = new QGroupBox(MainWindow);
        gbSize->setObjectName(QStringLiteral("gbSize"));
        gbSize->setGeometry(QRect(10, 290, 161, 61));
        sbSize = new QSpinBox(gbSize);
        sbSize->setObjectName(QStringLiteral("sbSize"));
        sbSize->setGeometry(QRect(10, 20, 141, 22));
        sbSize->setMinimum(2);
        sbSize->setMaximum(100000);
        sbSize->setSingleStep(2);
        sbSize->setValue(16);
        gbInterval = new QGroupBox(MainWindow);
        gbInterval->setObjectName(QStringLiteral("gbInterval"));
        gbInterval->setGeometry(QRect(180, 290, 181, 61));
        sldInterval = new QSlider(gbInterval);
        sldInterval->setObjectName(QStringLiteral("sldInterval"));
        sldInterval->setGeometry(QRect(10, 20, 160, 19));
        sldInterval->setMinimum(1);
        sldInterval->setMaximum(30000);
        sldInterval->setOrientation(Qt::Horizontal);
        label_12 = new QLabel(gbInterval);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 30, 20, 31));
        label_13 = new QLabel(gbInterval);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(150, 29, 21, 31));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Function minimum searcher", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Genetic settings", 0));
        cbGenerationSelection->clear();
        cbGenerationSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "TRUNCATION_SELECTION", 0)
         << QApplication::translate("MainWindow", "ELITE_SELECTION", 0)
        );
        label_4->setText(QApplication::translate("MainWindow", "Generation selection\n"
"parameter", 0));
        label_5->setText(QApplication::translate("MainWindow", "Selection type", 0));
        label_3->setText(QApplication::translate("MainWindow", "Parents selection type", 0));
        cbParentsSelection->clear();
        cbParentsSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "PANMIXIA", 0)
         << QApplication::translate("MainWindow", "INBREEDING_FENOTYPE", 0)
         << QApplication::translate("MainWindow", "INBREEDING_GENOTYPE", 0)
         << QApplication::translate("MainWindow", "OUTBREEDING_FENOTYPE", 0)
         << QApplication::translate("MainWindow", "OUTBREEDING_GENOTYPE", 0)
        );
        cbRecombination->clear();
        cbRecombination->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "DISCRETE", 0)
         << QApplication::translate("MainWindow", "INTERMEDIATE", 0)
         << QApplication::translate("MainWindow", "CROSSOVER", 0)
         << QApplication::translate("MainWindow", "UNIFORM_CROSSOVER", 0)
         << QApplication::translate("MainWindow", "TRIADIC_CROSSOVER", 0)
         << QApplication::translate("MainWindow", "SHUFFLER_CROSSOVER", 0)
         << QApplication::translate("MainWindow", "CROSSOVER_WITH_REDUCED_SURROGATE", 0)
        );
        label_8->setText(QApplication::translate("MainWindow", "Max. nuber of mutations\n"
"per generation", 0));
        label_11->setText(QApplication::translate("MainWindow", "Mutation Parameter", 0));
        label_1->setText(QApplication::translate("MainWindow", "Mutation probability, %", 0));
        label_7->setText(QApplication::translate("MainWindow", "Recombination parameter", 0));
        label_6->setText(QApplication::translate("MainWindow", "Recombination type", 0));
        btApllySets->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        gbFunction->setTitle(QApplication::translate("MainWindow", "Target function", 0));
        tbFunction->setText(QApplication::translate("MainWindow", "{0}^2-12*{0}+36", 0));
        label_2->setText(QApplication::translate("MainWindow", "Here should be some help.", 0));
        label_9->setText(QApplication::translate("MainWindow", " Best score in gen.:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Current generation:", 0));
        gbControl->setTitle(QApplication::translate("MainWindow", "Status", 0));
        btStart->setText(QApplication::translate("MainWindow", "Start", 0));
        btStop->setText(QApplication::translate("MainWindow", "Stop", 0));
        btPause->setText(QApplication::translate("MainWindow", "Pause", 0));
        label->setText(QApplication::translate("MainWindow", "Stopped.", 0));
        btContinue->setText(QApplication::translate("MainWindow", "Continue", 0));
        gbFiles->setTitle(QApplication::translate("MainWindow", "Generation", 0));
        btSaveGeneration->setText(QApplication::translate("MainWindow", "Save", 0));
        btLoadGeneration->setText(QApplication::translate("MainWindow", "Load", 0));
        gbFiles_2->setTitle(QApplication::translate("MainWindow", "Genetics", 0));
        btSaveGenetics->setText(QApplication::translate("MainWindow", "Save", 0));
        btLoadGenetics->setText(QApplication::translate("MainWindow", "Load", 0));
        gbSize->setTitle(QApplication::translate("MainWindow", "Population size", 0));
        gbInterval->setTitle(QApplication::translate("MainWindow", "Generation interval", 0));
        label_12->setText(QApplication::translate("MainWindow", "1 ms", 0));
        label_13->setText(QApplication::translate("MainWindow", "30 s", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
