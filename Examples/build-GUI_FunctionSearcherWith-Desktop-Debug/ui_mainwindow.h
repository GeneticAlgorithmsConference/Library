/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QComboBox *cbGenerationSelection;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *sbSelectionParameter;
    QLabel *label_3;
    QComboBox *cbParentsSelection;
    QDoubleSpinBox *sbMutationProbability;
    QLabel *label_1;
    QSpinBox *sbMaxMutations;
    QLabel *label_7;
    QLabel *label_6;
    QComboBox *cbRecombination;
    QLabel *label_8;
    QDoubleSpinBox *sbRecombParam;
    QDoubleSpinBox *sbMutationParameter;
    QLabel *label_11;
    QPushButton *btApllySets;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *gbSize;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *sbSize;
    QGroupBox *gbInterval;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *sbInterval;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *gbFunction;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *tbFunction;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *gbFiles_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btSaveGenetics;
    QPushButton *btLoadGenetics;
    QGroupBox *gbFiles;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btSaveGeneration;
    QPushButton *btLoadGeneration;
    QVBoxLayout *verticalLayout;
    QGroupBox *gbControl;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lStatus;
    QPushButton *btStart;
    QPushButton *btContinue;
    QPushButton *btPause;
    QPushButton *btStop;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLCDNumber *lcdGeneration;
    QLabel *label_9;
    QLCDNumber *lcdBestScore;
    QTableWidget *tableWidget;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(747, 601);
        horizontalLayoutWidget_3 = new QWidget(MainWindow);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 10, 727, 586));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupBox = new QGroupBox(horizontalLayoutWidget_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        cbGenerationSelection = new QComboBox(groupBox);
        cbGenerationSelection->setObjectName(QString::fromUtf8("cbGenerationSelection"));
        cbGenerationSelection->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(cbGenerationSelection, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        sbSelectionParameter = new QDoubleSpinBox(groupBox);
        sbSelectionParameter->setObjectName(QString::fromUtf8("sbSelectionParameter"));
        sbSelectionParameter->setMaximumSize(QSize(200, 16777215));
        sbSelectionParameter->setValue(1);

        gridLayout->addWidget(sbSelectionParameter, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        cbParentsSelection = new QComboBox(groupBox);
        cbParentsSelection->setObjectName(QString::fromUtf8("cbParentsSelection"));
        cbParentsSelection->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(cbParentsSelection, 2, 1, 1, 1);

        sbMutationProbability = new QDoubleSpinBox(groupBox);
        sbMutationProbability->setObjectName(QString::fromUtf8("sbMutationProbability"));
        sbMutationProbability->setMaximumSize(QSize(200, 16777215));
        sbMutationProbability->setMaximum(100);
        sbMutationProbability->setValue(25);

        gridLayout->addWidget(sbMutationProbability, 6, 1, 1, 1);

        label_1 = new QLabel(groupBox);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_1, 6, 0, 1, 1);

        sbMaxMutations = new QSpinBox(groupBox);
        sbMaxMutations->setObjectName(QString::fromUtf8("sbMaxMutations"));
        sbMaxMutations->setMaximumSize(QSize(200, 16777215));
        sbMaxMutations->setMaximum(1024);
        sbMaxMutations->setValue(1);

        gridLayout->addWidget(sbMaxMutations, 5, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        cbRecombination = new QComboBox(groupBox);
        cbRecombination->setObjectName(QString::fromUtf8("cbRecombination"));
        cbRecombination->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(cbRecombination, 3, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        sbRecombParam = new QDoubleSpinBox(groupBox);
        sbRecombParam->setObjectName(QString::fromUtf8("sbRecombParam"));
        sbRecombParam->setMaximumSize(QSize(200, 16777215));
        sbRecombParam->setValue(1);

        gridLayout->addWidget(sbRecombParam, 4, 1, 1, 1);

        sbMutationParameter = new QDoubleSpinBox(groupBox);
        sbMutationParameter->setObjectName(QString::fromUtf8("sbMutationParameter"));
        sbMutationParameter->setMaximumSize(QSize(200, 16777215));
        sbMutationParameter->setValue(25);

        gridLayout->addWidget(sbMutationParameter, 7, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label_11, 7, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        btApllySets = new QPushButton(groupBox);
        btApllySets->setObjectName(QString::fromUtf8("btApllySets"));

        verticalLayout_5->addWidget(btApllySets);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_9->addWidget(groupBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gbSize = new QGroupBox(horizontalLayoutWidget_3);
        gbSize->setObjectName(QString::fromUtf8("gbSize"));
        horizontalLayout_6 = new QHBoxLayout(gbSize);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        sbSize = new QSpinBox(gbSize);
        sbSize->setObjectName(QString::fromUtf8("sbSize"));
        sbSize->setMinimum(2);
        sbSize->setMaximum(100000);
        sbSize->setSingleStep(2);
        sbSize->setValue(16);

        horizontalLayout_6->addWidget(sbSize);


        horizontalLayout_4->addWidget(gbSize);

        gbInterval = new QGroupBox(horizontalLayoutWidget_3);
        gbInterval->setObjectName(QString::fromUtf8("gbInterval"));
        horizontalLayout_7 = new QHBoxLayout(gbInterval);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        sbInterval = new QSpinBox(gbInterval);
        sbInterval->setObjectName(QString::fromUtf8("sbInterval"));
        sbInterval->setMinimum(1);
        sbInterval->setMaximum(30000);
        sbInterval->setValue(200);

        horizontalLayout_3->addWidget(sbInterval);

        label_12 = new QLabel(gbInterval);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_3->addWidget(label_12);


        horizontalLayout_7->addLayout(horizontalLayout_3);


        horizontalLayout_4->addWidget(gbInterval);


        verticalLayout_9->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        gbFunction = new QGroupBox(horizontalLayoutWidget_3);
        gbFunction->setObjectName(QString::fromUtf8("gbFunction"));
        verticalLayout_8 = new QVBoxLayout(gbFunction);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        tbFunction = new QLineEdit(gbFunction);
        tbFunction->setObjectName(QString::fromUtf8("tbFunction"));

        verticalLayout_7->addWidget(tbFunction);

        label_2 = new QLabel(gbFunction);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_7->addWidget(label_2);


        verticalLayout_8->addLayout(verticalLayout_7);


        horizontalLayout_5->addWidget(gbFunction);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gbFiles_2 = new QGroupBox(horizontalLayoutWidget_3);
        gbFiles_2->setObjectName(QString::fromUtf8("gbFiles_2"));
        horizontalLayout = new QHBoxLayout(gbFiles_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btSaveGenetics = new QPushButton(gbFiles_2);
        btSaveGenetics->setObjectName(QString::fromUtf8("btSaveGenetics"));

        verticalLayout_2->addWidget(btSaveGenetics);

        btLoadGenetics = new QPushButton(gbFiles_2);
        btLoadGenetics->setObjectName(QString::fromUtf8("btLoadGenetics"));

        verticalLayout_2->addWidget(btLoadGenetics);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addWidget(gbFiles_2);

        gbFiles = new QGroupBox(horizontalLayoutWidget_3);
        gbFiles->setObjectName(QString::fromUtf8("gbFiles"));
        horizontalLayout_2 = new QHBoxLayout(gbFiles);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btSaveGeneration = new QPushButton(gbFiles);
        btSaveGeneration->setObjectName(QString::fromUtf8("btSaveGeneration"));

        verticalLayout_3->addWidget(btSaveGeneration);

        btLoadGeneration = new QPushButton(gbFiles);
        btLoadGeneration->setObjectName(QString::fromUtf8("btLoadGeneration"));

        verticalLayout_3->addWidget(btLoadGeneration);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_4->addWidget(gbFiles);


        horizontalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_9->addLayout(horizontalLayout_5);


        horizontalLayout_11->addLayout(verticalLayout_9);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gbControl = new QGroupBox(horizontalLayoutWidget_3);
        gbControl->setObjectName(QString::fromUtf8("gbControl"));
        horizontalLayout_9 = new QHBoxLayout(gbControl);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lStatus = new QLabel(gbControl);
        lStatus->setObjectName(QString::fromUtf8("lStatus"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        lStatus->setPalette(palette);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lStatus->setFont(font);

        horizontalLayout_8->addWidget(lStatus);

        btStart = new QPushButton(gbControl);
        btStart->setObjectName(QString::fromUtf8("btStart"));

        horizontalLayout_8->addWidget(btStart);

        btContinue = new QPushButton(gbControl);
        btContinue->setObjectName(QString::fromUtf8("btContinue"));
        btContinue->setEnabled(false);

        horizontalLayout_8->addWidget(btContinue);

        btPause = new QPushButton(gbControl);
        btPause->setObjectName(QString::fromUtf8("btPause"));
        btPause->setEnabled(false);

        horizontalLayout_8->addWidget(btPause);

        btStop = new QPushButton(gbControl);
        btStop->setObjectName(QString::fromUtf8("btStop"));
        btStop->setEnabled(false);

        horizontalLayout_8->addWidget(btStop);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        verticalLayout->addWidget(gbControl);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_10 = new QLabel(horizontalLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_10->addWidget(label_10);

        lcdGeneration = new QLCDNumber(horizontalLayoutWidget_3);
        lcdGeneration->setObjectName(QString::fromUtf8("lcdGeneration"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        lcdGeneration->setPalette(palette1);
        lcdGeneration->setDigitCount(5);
        lcdGeneration->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_10->addWidget(lcdGeneration);

        label_9 = new QLabel(horizontalLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);
        label_9->setWordWrap(true);

        horizontalLayout_10->addWidget(label_9);

        lcdBestScore = new QLCDNumber(horizontalLayoutWidget_3);
        lcdBestScore->setObjectName(QString::fromUtf8("lcdBestScore"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        lcdBestScore->setPalette(palette2);
        lcdBestScore->setSmallDecimalPoint(true);
        lcdBestScore->setDigitCount(10);
        lcdBestScore->setSegmentStyle(QLCDNumber::Flat);
        lcdBestScore->setProperty("value", QVariant(0));

        horizontalLayout_10->addWidget(lcdBestScore);


        verticalLayout->addLayout(horizontalLayout_10);

        tableWidget = new QTableWidget(horizontalLayoutWidget_3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setAlternatingRowColors(true);

        verticalLayout->addWidget(tableWidget);


        horizontalLayout_11->addLayout(verticalLayout);

        gbControl->raise();
        horizontalLayoutWidget_3->raise();

        retranslateUi(MainWindow);

        cbGenerationSelection->setCurrentIndex(1);
        cbParentsSelection->setCurrentIndex(0);
        cbRecombination->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Function minimum searcher", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Genetic settings", 0, QApplication::UnicodeUTF8));
        cbGenerationSelection->clear();
        cbGenerationSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "TRUNCATION_SELECTION", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ELITE_SELECTION", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("MainWindow", "Generation selection\n"
"parameter", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Selection type", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Parents selection type", 0, QApplication::UnicodeUTF8));
        cbParentsSelection->clear();
        cbParentsSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "PANMIXIA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "INBREEDING_FENOTYPE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "INBREEDING_GENOTYPE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "OUTBREEDING_FENOTYPE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "OUTBREEDING_GENOTYPE", 0, QApplication::UnicodeUTF8)
        );
        label_1->setText(QApplication::translate("MainWindow", "Mutation probability, %", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Recombination parameter", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Recombination type", 0, QApplication::UnicodeUTF8));
        cbRecombination->clear();
        cbRecombination->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "DISCRETE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "INTERMEDIATE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "CROSSOVER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "UNIFORM_CROSSOVER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "TRIADIC_CROSSOVER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "SHUFFLER_CROSSOVER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "CROSSOVER_WITH_REDUCED_SURROGATE", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("MainWindow", "Max. nuber of mutations\n"
"per generation", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Mutation Parameter", 0, QApplication::UnicodeUTF8));
        btApllySets->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        gbSize->setTitle(QApplication::translate("MainWindow", "Population size", 0, QApplication::UnicodeUTF8));
        gbInterval->setTitle(QApplication::translate("MainWindow", "Generation interval", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "ms", 0, QApplication::UnicodeUTF8));
        gbFunction->setTitle(QApplication::translate("MainWindow", "Target function", 0, QApplication::UnicodeUTF8));
        tbFunction->setText(QApplication::translate("MainWindow", "0.25*{0}^2-3*{0}+9-sin({1})", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Here should be some help.", 0, QApplication::UnicodeUTF8));
        gbFiles_2->setTitle(QApplication::translate("MainWindow", "Genetics", 0, QApplication::UnicodeUTF8));
        btSaveGenetics->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        btLoadGenetics->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        gbFiles->setTitle(QApplication::translate("MainWindow", "Generation", 0, QApplication::UnicodeUTF8));
        btSaveGeneration->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        btLoadGeneration->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        gbControl->setTitle(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        lStatus->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Status</p></body></html>", 0, QApplication::UnicodeUTF8));
        btStart->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        btContinue->setText(QApplication::translate("MainWindow", "Continue", 0, QApplication::UnicodeUTF8));
        btPause->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        btStop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Current generation:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", " Best score in generation:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
