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
    QLabel *label_5;
    QComboBox *cbGenerationSelection;
    QLabel *label_4;
    QLabel *label_3;
    QComboBox *cbParsentsSelection;
    QLabel *label_6;
    QComboBox *cbRecombination;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *sbMaxMutations;
    QLabel *label_1;
    QDoubleSpinBox *cbMutationProbability;
    QPushButton *btApllySets;
    QTableView *tableView;
    QGroupBox *gbFunction;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QGroupBox *gbControl;
    QPushButton *btStart;
    QPushButton *btStop;
    QPushButton *btPause;
    QLabel *label;
    QPushButton *btContinue;
    QLCDNumber *lcdBestScore;
    QLCDNumber *lcdGeneration;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(750, 428);
        groupBox = new QGroupBox(MainWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 351, 231));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 21, 331, 172));
        gridLayout = new QGridLayout(formLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        cbGenerationSelection = new QComboBox(formLayoutWidget);
        cbGenerationSelection->setObjectName(QStringLiteral("cbGenerationSelection"));

        gridLayout->addWidget(cbGenerationSelection, 0, 1, 1, 1);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        cbParsentsSelection = new QComboBox(formLayoutWidget);
        cbParsentsSelection->setObjectName(QStringLiteral("cbParsentsSelection"));

        gridLayout->addWidget(cbParsentsSelection, 2, 1, 1, 1);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        cbRecombination = new QComboBox(formLayoutWidget);
        cbRecombination->setObjectName(QStringLiteral("cbRecombination"));

        gridLayout->addWidget(cbRecombination, 3, 1, 1, 1);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        sbMaxMutations = new QSpinBox(formLayoutWidget);
        sbMaxMutations->setObjectName(QStringLiteral("sbMaxMutations"));
        sbMaxMutations->setMaximum(1024);

        gridLayout->addWidget(sbMaxMutations, 5, 1, 1, 1);

        label_1 = new QLabel(formLayoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));

        gridLayout->addWidget(label_1, 6, 0, 1, 1);

        cbMutationProbability = new QDoubleSpinBox(formLayoutWidget);
        cbMutationProbability->setObjectName(QStringLiteral("cbMutationProbability"));
        cbMutationProbability->setMaximum(100);

        gridLayout->addWidget(cbMutationProbability, 6, 1, 1, 1);

        btApllySets = new QPushButton(groupBox);
        btApllySets->setObjectName(QStringLiteral("btApllySets"));
        btApllySets->setGeometry(QRect(10, 200, 331, 23));
        tableView = new QTableView(MainWindow);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(370, 40, 371, 381));
        gbFunction = new QGroupBox(MainWindow);
        gbFunction->setObjectName(QStringLiteral("gbFunction"));
        gbFunction->setGeometry(QRect(10, 240, 261, 181));
        lineEdit = new QLineEdit(gbFunction);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 241, 20));
        label_2 = new QLabel(gbFunction);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 241, 121));
        gbControl = new QGroupBox(MainWindow);
        gbControl->setObjectName(QStringLiteral("gbControl"));
        gbControl->setGeometry(QRect(280, 240, 81, 181));
        btStart = new QPushButton(gbControl);
        btStart->setObjectName(QStringLiteral("btStart"));
        btStart->setGeometry(QRect(10, 60, 61, 23));
        btStop = new QPushButton(gbControl);
        btStop->setObjectName(QStringLiteral("btStop"));
        btStop->setGeometry(QRect(10, 150, 61, 23));
        btPause = new QPushButton(gbControl);
        btPause->setObjectName(QStringLiteral("btPause"));
        btPause->setGeometry(QRect(10, 120, 61, 23));
        label = new QLabel(gbControl);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 61, 20));
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
        label->setPalette(palette);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        btContinue = new QPushButton(gbControl);
        btContinue->setObjectName(QStringLiteral("btContinue"));
        btContinue->setGeometry(QRect(10, 90, 61, 23));
        btStart->raise();
        btStop->raise();
        btPause->raise();
        label->raise();
        tableView->raise();
        btContinue->raise();
        lcdBestScore = new QLCDNumber(MainWindow);
        lcdBestScore->setObjectName(QStringLiteral("lcdBestScore"));
        lcdBestScore->setGeometry(QRect(610, 10, 131, 23));
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
        lcdBestScore->setPalette(palette1);
        lcdBestScore->setSmallDecimalPoint(true);
        lcdBestScore->setDigitCount(10);
        lcdBestScore->setProperty("value", QVariant(0));
        lcdGeneration = new QLCDNumber(MainWindow);
        lcdGeneration->setObjectName(QStringLiteral("lcdGeneration"));
        lcdGeneration->setGeometry(QRect(470, 10, 51, 23));
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
        lcdGeneration->setPalette(palette2);
        lcdGeneration->setDigitCount(5);
        label_9 = new QLabel(MainWindow);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(550, 10, 71, 20));
        label_10 = new QLabel(MainWindow);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(370, 10, 111, 21));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Function minimum searcher", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Genetic settings", 0));
        label_5->setText(QApplication::translate("MainWindow", "Selection type", 0));
        cbGenerationSelection->clear();
        cbGenerationSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "TRUNCATION_SELECTION", 0)
         << QApplication::translate("MainWindow", "ELITE_SELECTION", 0)
        );
        label_4->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_3->setText(QApplication::translate("MainWindow", "Parents selection type", 0));
        cbParsentsSelection->clear();
        cbParsentsSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "PANMIXIA", 0)
         << QApplication::translate("MainWindow", "INBREEDING_FENOTYPE", 0)
         << QApplication::translate("MainWindow", "INBREEDING_GENOTYPE", 0)
         << QApplication::translate("MainWindow", "OUTBREEDING_FENOTYPE", 0)
         << QApplication::translate("MainWindow", "OUTBREEDING_GENOTYPE", 0)
        );
        label_6->setText(QApplication::translate("MainWindow", "Recombination type", 0));
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
        label_7->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_8->setText(QApplication::translate("MainWindow", "Max. nuber of mutations\n"
"per generation", 0));
        label_1->setText(QApplication::translate("MainWindow", "Mutation probability, %", 0));
        btApllySets->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        gbFunction->setTitle(QApplication::translate("MainWindow", "Target function", 0));
        lineEdit->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Here should be some help.", 0));
        gbControl->setTitle(QApplication::translate("MainWindow", "Status", 0));
        btStart->setText(QApplication::translate("MainWindow", "Start", 0));
        btStop->setText(QApplication::translate("MainWindow", "Stop", 0));
        btPause->setText(QApplication::translate("MainWindow", "Pause", 0));
        label->setText(QApplication::translate("MainWindow", "Stopped.", 0));
        btContinue->setText(QApplication::translate("MainWindow", "Continue", 0));
        label_9->setText(QApplication::translate("MainWindow", "Best score:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Current generation:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
