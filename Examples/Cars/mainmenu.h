#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QtWidgets>
#include <QtWebKitWidgets/QWebView>

#include "map.h"

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);

signals:
    
public slots:
    void screenshot();

    void showMainMenu();
    void tick();
    void showNewGameOptions();
    void showSaveGameOptions();
    void showLoadGameOptions();
    void showOptions();
    void showHelp();
    void continueAction();
    void backButtonClick();
    void startNewGame();
    void saveGame();
    void loadGame();
    void deleteGame();

    void minDeltaYUpdate(double value);
    void maxDeltaYUpdate(double value);

    void vehiclePointsNumChanged(int value);
    void vehicleMaxWheelsNumChanged(int value);

private:
    void createNewGameMenu();
    void createOptionsMenu();
    void createHelpMenu();
    void createButtons();
    void createActions();

    void moveCameraTo(double x, double y);

    QFormLayout *mainMenuLayout;
    QPushButton *continueButton;
    QPushButton *newGameButton;
    QPushButton *saveGameButton;
    QPushButton *loadGameButton;
    QPushButton *optionsButton;
    QPushButton *helpButton;
    QPushButton *exitButton;
    QPushButton *startButton;
    QPushButton *backButton;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QPushButton *deleteButton;

    QLabel *saveNameLabel;
    QComboBox *loadName;
    QLineEdit *saveName;

    QLabel *helpLabel;
    QAction *continueGameAction;

    QSpinBox *mapLengthEdit;
    QDoubleSpinBox *minDeltaYEdit;
    QDoubleSpinBox *maxDeltaYEdit;
    QDoubleSpinBox *deltaXEdit;

    QSpinBox *leftPopulationSizeEdit;
    QSpinBox *rightPopulationSizeEdit;
    QCheckBox *populationTestTypeEdit;
    QSpinBox *maxMutationsCountEdit;

    QSpinBox *vehiclePointsNumEdit;
    QSpinBox *vehicleMaxWheelsNumEdit;

    QSlider *vehicleVectorLengthEdit;
    QSlider *vehicleWheelsSizeEdit;

    QCheckBox *manualEngineControlEdit;

    QTimer *timer;

    QTime lastUpdateTime;

    Map *map;
    double translateX;
    double translateY;
    double translateXSpeed;
    double translateYSpeed;
    double translateXAcceleration;
    double translateYAcceleration;
    double scale;
    QPoint mousePosition;
    bool dragging;
    bool followMode;
    int maxWidth;
    bool gameRunning;

    bool manualEngineControl;

    enum MenuType {MAIN_MENU, NEW_GAME_MENU, OPTIONS_MENU, HELP_MENU, GAME, LOAD_MENU, SAVE_MENU} currentPlace;
};

#endif // MAINMENU_H
