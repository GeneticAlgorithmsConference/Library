#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent)
{
    translateX = 0.0;
    translateY = 0.0;
    translateXSpeed = 40.0;
    translateYSpeed = 40.0;
    translateXAcceleration = 1.0;
    translateYAcceleration = 1.0;
    scale = 0.5;
    dragging = false;
    followMode = true;
    currentPlace = MAIN_MENU;
    maxWidth = 200;
    gameRunning = false;

    manualEngineControl = false;

    map = new Map();
    map -> generate();
    map -> setShowInfo(false);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer -> start(16);

    continueGameAction = new QAction(this);
    continueGameAction -> setShortcut(Qt::Key_Escape);
    addAction(continueGameAction);

    mainMenuLayout = new QFormLayout(this);
    mainMenuLayout -> setHorizontalSpacing(0);
    mainMenuLayout -> setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    mainMenuLayout -> setFormAlignment(Qt::AlignBottom | Qt::AlignHCenter);

    lastUpdateTime = QTime::currentTime();

    saveNameLabel = new QLabel(this);
    saveNameLabel -> setText(tr("Name:"));
    saveNameLabel -> setVisible(false);
    saveNameLabel -> setFixedWidth(maxWidth);
    mainMenuLayout -> addRow(saveNameLabel);

    saveName = new QLineEdit(this);
    saveName -> setVisible(false);
    saveName -> setFixedWidth(maxWidth);
    mainMenuLayout -> addRow(saveName);

    loadName = new QComboBox(this);
    loadName -> setVisible(false);
    loadName -> setFixedWidth(maxWidth);
    mainMenuLayout -> addRow(loadName);

    createNewGameMenu();
    createOptionsMenu();
    createHelpMenu();
    createButtons();
    createActions();

    // Loading help
    QFile *file = new QFile(QDir::currentPath() + "\\help.txt");
    if(!file -> open(QIODevice::ReadOnly | QIODevice::Text))
    {
        helpLabel -> setText("Error: help file not found!");
    }
    else
    {
        QTextStream fin(file);
        QString tmp = fin.readAll();

        helpLabel -> setText(tmp);
    }
    file -> close();


    QFont tmpFont = this -> font();
    tmpFont.setBold(true);
    helpLabel -> setFont(tmpFont);

    QPalette tmpPallet = this -> palette();
    tmpPallet.setColor(QPalette::WindowText, Qt::white);
    helpLabel -> setPalette(tmpPallet);
    saveNameLabel -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(manualEngineControlEdit) -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(mapLengthEdit) -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(deltaXEdit) -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(minDeltaYEdit) -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(maxDeltaYEdit) -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(leftPopulationSizeEdit) -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(rightPopulationSizeEdit) -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(populationTestTypeEdit) -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(maxMutationsCountEdit) -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(vehiclePointsNumEdit) -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(vehicleMaxWheelsNumEdit) -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(vehicleVectorLengthEdit) -> setPalette(tmpPallet);
    mainMenuLayout -> labelForField(vehicleWheelsSizeEdit) -> setPalette(tmpPallet);

    showFullScreen();
}

void MainMenu::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillRect(0, 0, width(), height(), Qt::white);
    painter.setTransform(QTransform(1.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0));
    painter.translate(width() / 2, -height() / 2);
    painter.scale(scale, scale);
    painter.translate(-translateX, -translateY);
    map -> show(painter, translateX - width() / 2 / scale, translateX + width() / 2 / scale);
    if(currentPlace != GAME)
    {
        painter.setTransform(QTransform(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0));
        painter.fillRect(0, 0, width(), height(), QColor(0, 0, 0, 150));
    }
}

void MainMenu::mousePressEvent(QMouseEvent *event)
{
    if(currentPlace == GAME)
    {
        if(!followMode)
        {
            if(event -> button() == Qt::LeftButton)
            {
                dragging = true;
                mousePosition = event -> pos();
            } else {
                dragging = false;
            }
        }
    }
}

void MainMenu::mouseReleaseEvent(QMouseEvent *event)
{
    if(currentPlace == GAME)
    {
        dragging = false;
    }
}

void MainMenu::mouseMoveEvent(QMouseEvent *event)
{
    if(currentPlace == GAME)
    {
        if(dragging && (!followMode))
        {
            translateX += (mousePosition.x() - event -> x()) / scale;
            translateY += (event -> y() - mousePosition.y()) / scale;
            mousePosition = event -> pos();
        }
        repaint();
    }
}

void MainMenu::keyPressEvent(QKeyEvent *event)
{
    if(currentPlace == GAME)
    {
        switch(event -> key())
        {
        case Qt::Key_Plus:
            scale *= 1.1;
            break;
        case Qt::Key_Minus:
            scale /= 1.1;
            break;
        case Qt::Key_F3:
            // Переход к тестированию следующего индивида
            if((!map -> getFirstPopulation() -> getPopulationType()) && (map -> getFirstPopulation() -> getCurrentVehicle() -> alive()))
            {
                map -> getFirstPopulation() -> testFinish();
                if(map -> getFirstPopulation() -> currentEnd())
                {
                    map -> getFirstPopulation() -> genNextGeneration();
                }
                map -> updateAllPhysics();
            }
            break;
        case Qt::Key_F5:
            // Создание новой популяции
            map -> generate();
            map -> updateAllPhysics();
            break;
        case Qt::Key_C:
            // Включение/Выключение следящего режима
            followMode = !followMode;
            break;
        case Qt::Key_Space:
            // Включение/Выключение мотора
            if((manualEngineControl) && (map -> getFirstPopulation() -> getPopulationType()))
            {
                map -> getFirstPopulation() -> getCurrentVehicle() -> setMotorEnabled(true);
                lastUpdateTime = QTime::currentTime();
            }
            break;
        case Qt::Key_S:
            if(event -> modifiers() == Qt::ControlModifier)
            {
                QString path = QDir::currentPath() + "\\Saves\\QuickSave";
                map -> save(path);
            }
            break;
        case Qt::Key_L:
            if(event -> modifiers() == Qt::ControlModifier)
            {
                QString path = QDir::currentPath() + "\\Saves\\QuickSave";
                map -> load(path);
                map -> updateAllPhysics();
            }
            break;
        case Qt::Key_F12:
            screenshot();
            break;
        case Qt::Key_P:
            if(timer -> isActive())
                timer -> stop();
            else
                timer -> start();
            break;
        }

        repaint();
    }
}

void MainMenu::keyReleaseEvent(QKeyEvent *event)
{
}

void MainMenu::wheelEvent(QWheelEvent *event)
{
    if(currentPlace == GAME)
    {
        if(!followMode)
        {
            QPoint numDegrees = event -> angleDelta() / 8;
            int count = qRound(numDegrees.y() / 15.0);
            if(count > 0)
            {
                for(int i = 0; i < count; ++i)
                {
                    translateX += (width() / 2 - event -> x()) / scale * 0.1;
                    translateY += (-height() / 2 + event -> y()) / scale * 0.1;
                    scale *= 1.1;
                }
            } else {
                count = -count;
                for(int i = 0; i < count; ++i)
                {
                    scale /= 1.1;
                }
            }

        }
    }
}

void MainMenu::screenshot()
{
   QPixmap originalPixmap = QPixmap();

    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen)
        originalPixmap = screen->grabWindow(0);

    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    QString initialPath = QDir::currentPath() + "\\Screenshots\\";
    QDir dir(initialPath);
    dir.mkdir(initialPath);

    QString curDate = QString::number(cd.year()) + "_" +
                      QString::number(cd.month()) + "_" +
                      QString::number(cd.day());

    QString curTime = QString::number(ct.hour()) + "_" +
                      QString::number(ct.minute()) + "_" +
                      QString::number(ct.second());

    QString fileName = initialPath + curDate + "_" + curTime + ".png";
    if (!fileName.isEmpty())
        originalPixmap.save(fileName, "PNG");
}

void MainMenu::showMainMenu()
{
    if(gameRunning)
    {
        continueButton -> setVisible(true);
        saveGameButton -> setVisible(true);
    }
    newGameButton -> setVisible(true);
    loadGameButton -> setVisible(true);
    optionsButton -> setVisible(true);
    helpButton -> setVisible(true);
    exitButton -> setVisible(true);
}

void MainMenu::tick()
{
    map -> tick();
    if(followMode)
    {
        if(map -> getFirstPopulation() -> getPopulationType())
        {
            Vehicle *tmpVehicle;
            for(int i = 0; i < map -> getFirstPopulation() -> getSize(); ++i)
            {
                tmpVehicle = map -> getFirstPopulation() -> getVehicle(i);
                if(tmpVehicle -> alive())
                {
                    b2Vec2 position = tmpVehicle -> GetPosition();
                    moveCameraTo(position.x * 100, position.y * 100);
                    break;
                }
            }
        } else if(map -> getFirstPopulation() -> getCurrentVehicle() -> alive())
        {
            b2Vec2 position = map -> getFirstPopulation() -> getFocusPosition();
            translateX = position.x * 100;
            translateY = position.y * 100;
        }
    }
    if((!map -> getFirstPopulation() -> getPopulationType())
        && manualEngineControl && (lastUpdateTime.msecsTo(QTime::currentTime()) >= 1000))
    {
        map -> getFirstPopulation() -> getCurrentVehicle() -> setMotorEnabled(false);
    }
    repaint();
}

void MainMenu::showNewGameOptions()
{
    currentPlace = NEW_GAME_MENU;
    continueButton -> setVisible(false);
    newGameButton -> setVisible(false);
    saveGameButton -> setVisible(false);
    loadGameButton -> setVisible(false);
    optionsButton -> setVisible(false);
    helpButton -> setVisible(false);
    exitButton -> setVisible(false);

    startButton -> setVisible(true);
    backButton -> setVisible(true);
    mapLengthEdit -> setVisible(true);
    deltaXEdit -> setVisible(true);
    minDeltaYEdit -> setVisible(true);
    maxDeltaYEdit -> setVisible(true);
    leftPopulationSizeEdit -> setVisible(true);
    rightPopulationSizeEdit -> setVisible(true);
    populationTestTypeEdit -> setVisible(true);
    maxMutationsCountEdit -> setVisible(true);
    vehiclePointsNumEdit -> setVisible(true);
    vehicleMaxWheelsNumEdit -> setVisible(true);
    vehicleVectorLengthEdit -> setVisible(true);
    vehicleWheelsSizeEdit -> setVisible(true);

    mainMenuLayout -> labelForField(mapLengthEdit) -> setVisible(true);
    mainMenuLayout -> labelForField(deltaXEdit) -> setVisible(true);
    mainMenuLayout -> labelForField(minDeltaYEdit) -> setVisible(true);
    mainMenuLayout -> labelForField(maxDeltaYEdit) -> setVisible(true);
    mainMenuLayout -> labelForField(leftPopulationSizeEdit) -> setVisible(true);
    mainMenuLayout -> labelForField(rightPopulationSizeEdit) -> setVisible(true);
    mainMenuLayout -> labelForField(populationTestTypeEdit) -> setVisible(true);
    mainMenuLayout -> labelForField(maxMutationsCountEdit) -> setVisible(true);
    mainMenuLayout -> labelForField(vehiclePointsNumEdit) -> setVisible(true);
    mainMenuLayout -> labelForField(vehicleMaxWheelsNumEdit) -> setVisible(true);
    mainMenuLayout -> labelForField(vehicleVectorLengthEdit) -> setVisible(true);
    mainMenuLayout -> labelForField(vehicleWheelsSizeEdit) -> setVisible(true);
}

void MainMenu::showSaveGameOptions()
{
    currentPlace = SAVE_MENU;
    continueButton -> setVisible(false);
    newGameButton -> setVisible(false);
    saveGameButton -> setVisible(false);
    loadGameButton -> setVisible(false);
    optionsButton -> setVisible(false);
    helpButton -> setVisible(false);
    exitButton -> setVisible(false);

    saveName -> setText("UntitledSave");
    saveName -> setVisible(true);
    saveNameLabel -> setVisible(true);
    saveButton -> setVisible(true);

    backButton -> setVisible(true);
}

void MainMenu::showLoadGameOptions()
{
    currentPlace = LOAD_MENU;
    continueButton -> setVisible(false);
    newGameButton -> setVisible(false);
    saveGameButton -> setVisible(false);
    loadGameButton -> setVisible(false);
    optionsButton -> setVisible(false);
    helpButton -> setVisible(false);
    exitButton -> setVisible(false);

    QDir *dir = new QDir(QDir::currentPath() + "\\Saves\\");
    loadName -> clear();
    loadName -> addItems(dir -> entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name));

    loadName -> setVisible(true);
    saveNameLabel -> setVisible(true);
    loadButton -> setVisible(true);

    backButton -> setVisible(true);
    deleteButton -> setVisible(true);
}

void MainMenu::showOptions()
{
    currentPlace = OPTIONS_MENU;
    continueButton -> setVisible(false);
    newGameButton -> setVisible(false);
    saveGameButton -> setVisible(false);
    loadGameButton -> setVisible(false);
    optionsButton -> setVisible(false);
    helpButton -> setVisible(false);
    exitButton -> setVisible(false);

    backButton -> setVisible(true);
    manualEngineControlEdit -> setVisible(true);

    mainMenuLayout -> labelForField(manualEngineControlEdit) -> setVisible(true);
}

void MainMenu::showHelp()
{
    currentPlace = HELP_MENU;
    backButton -> setVisible(true);
    helpLabel -> setVisible(true);
    continueButton -> setVisible(false);
    newGameButton -> setVisible(false);
    saveGameButton -> setVisible(false);
    loadGameButton -> setVisible(false);
    optionsButton -> setVisible(false);
    helpButton -> setVisible(false);
    exitButton -> setVisible(false);
}

void MainMenu::continueAction()
{
    if(currentPlace == MAIN_MENU)
    {
        if(gameRunning)
        {
            map -> updateLoseTimer();
            currentPlace = GAME;
            grabKeyboard();
            grabMouse();
            continueButton -> setVisible(false);
            newGameButton -> setVisible(false);
            saveGameButton -> setVisible(false);
            loadGameButton -> setVisible(false);
            optionsButton -> setVisible(false);
            helpButton -> setVisible(false);
            exitButton -> setVisible(false);
            timer -> start(16);
        }
    } else if(currentPlace == GAME)
    {
        currentPlace = MAIN_MENU;
        timer -> stop();
        releaseKeyboard();
        releaseMouse();
        showMainMenu();
        repaint();
    }
}

void MainMenu::backButtonClick()
{
    if(gameRunning)
    {
        continueButton -> setVisible(true);
        saveGameButton -> setVisible(true);
    }
    newGameButton -> setVisible(true);
    loadGameButton -> setVisible(true);
    optionsButton -> setVisible(true);
    helpButton -> setVisible(true);
    exitButton -> setVisible(true);
    backButton -> setVisible(false);

    if(currentPlace == NEW_GAME_MENU)
    {

        startButton -> setVisible(false);

        mapLengthEdit -> setVisible(false);
        deltaXEdit -> setVisible(false);
        minDeltaYEdit -> setVisible(false);
        maxDeltaYEdit -> setVisible(false);
        leftPopulationSizeEdit -> setVisible(false);
        rightPopulationSizeEdit -> setVisible(false);
        populationTestTypeEdit -> setVisible(false);
        maxMutationsCountEdit -> setVisible(false);
        vehiclePointsNumEdit -> setVisible(false);
        vehicleMaxWheelsNumEdit -> setVisible(false);
        vehicleVectorLengthEdit -> setVisible(false);
        vehicleWheelsSizeEdit -> setVisible(false);

        mainMenuLayout -> labelForField(mapLengthEdit) -> setVisible(false);
        mainMenuLayout -> labelForField(deltaXEdit) -> setVisible(false);
        mainMenuLayout -> labelForField(minDeltaYEdit) -> setVisible(false);
        mainMenuLayout -> labelForField(maxDeltaYEdit) -> setVisible(false);
        mainMenuLayout -> labelForField(leftPopulationSizeEdit) -> setVisible(false);
        mainMenuLayout -> labelForField(rightPopulationSizeEdit) -> setVisible(false);
        mainMenuLayout -> labelForField(populationTestTypeEdit) -> setVisible(false);
        mainMenuLayout -> labelForField(maxMutationsCountEdit) -> setVisible(false);
        mainMenuLayout -> labelForField(vehiclePointsNumEdit) -> setVisible(false);
        mainMenuLayout -> labelForField(vehicleMaxWheelsNumEdit) -> setVisible(false);
        mainMenuLayout -> labelForField(vehicleVectorLengthEdit) -> setVisible(false);
        mainMenuLayout -> labelForField(vehicleWheelsSizeEdit) -> setVisible(false);

    } else if(currentPlace == OPTIONS_MENU)
    {
        manualEngineControlEdit -> setVisible(false);

        mainMenuLayout -> labelForField(manualEngineControlEdit) -> setVisible(false);

        manualEngineControl = (manualEngineControlEdit -> checkState() == Qt::Checked);

        if(!map -> getFirstPopulation() -> getPopulationType())
        {
            map -> getFirstPopulation() -> setDefaultMotorEnabled(!manualEngineControl);
        }
    } else if(currentPlace == HELP_MENU)
    {
        helpLabel -> setVisible(false);

    } else if(currentPlace == SAVE_MENU)
    {
        saveName -> setVisible(false);
        saveNameLabel -> setVisible(false);
        saveButton -> setVisible(false);

    } else if(currentPlace == LOAD_MENU)
    {
        loadName -> setVisible(false);
        saveNameLabel -> setVisible(false);
        loadButton -> setVisible(false);
        deleteButton -> setVisible(false);
    }

    currentPlace = MAIN_MENU;
}

void MainMenu::startNewGame()
{
    if(gameRunning)
    {
        timer -> start(16);
    }
    qsrand(QTime(0, 0, 0).msecsTo(QTime::currentTime()));
    gameRunning = true;
    currentPlace = GAME;
    grabKeyboard();
    grabMouse();
    backButton -> setVisible(false);
    startButton -> setVisible(false);
    mapLengthEdit -> setVisible(false);
    mainMenuLayout -> labelForField(mapLengthEdit) -> setVisible(false);
    deltaXEdit -> setVisible(false);
    mainMenuLayout -> labelForField(deltaXEdit) -> setVisible(false);
    minDeltaYEdit -> setVisible(false);
    mainMenuLayout -> labelForField(minDeltaYEdit) -> setVisible(false);
    maxDeltaYEdit -> setVisible(false);
    mainMenuLayout -> labelForField(maxDeltaYEdit) -> setVisible(false);
    leftPopulationSizeEdit -> setVisible(false);
    mainMenuLayout -> labelForField(leftPopulationSizeEdit) -> setVisible(false);
    rightPopulationSizeEdit -> setVisible(false);
    mainMenuLayout -> labelForField(rightPopulationSizeEdit) -> setVisible(false);
    populationTestTypeEdit -> setVisible(false);
    mainMenuLayout -> labelForField(populationTestTypeEdit) -> setVisible(false);
    maxMutationsCountEdit -> setVisible(false);
    mainMenuLayout -> labelForField(maxMutationsCountEdit) -> setVisible(false);
    vehiclePointsNumEdit -> setVisible(false);
    mainMenuLayout -> labelForField(vehiclePointsNumEdit) -> setVisible(false);
    vehicleMaxWheelsNumEdit -> setVisible(false);
    mainMenuLayout -> labelForField(vehicleMaxWheelsNumEdit) -> setVisible(false);
    vehicleVectorLengthEdit -> setVisible(false);
    mainMenuLayout -> labelForField(vehicleVectorLengthEdit) -> setVisible(false);
    vehicleWheelsSizeEdit -> setVisible(false);
    mainMenuLayout -> labelForField(vehicleWheelsSizeEdit) -> setVisible(false);
    map -> setShowInfo(true);
    map -> setMapLength(mapLengthEdit -> value());
    map -> setMinDeltaX(deltaXEdit -> value());
    map -> setMaxDeltaX(deltaXEdit -> value() * 2.0);
    map -> setMinDeltaY(minDeltaYEdit -> value());
    map -> setMaxDeltaY(maxDeltaYEdit -> value());

    map -> getFirstPopulation() -> setPopulationSize(leftPopulationSizeEdit -> value());
    map -> getFirstPopulation() -> setMaxMutationsCount(maxMutationsCountEdit -> value());
    map -> getFirstPopulation() -> setVehiclePointsNum(vehiclePointsNumEdit -> value());
    map -> getFirstPopulation() -> setVehicleMaxWheelsNum(vehicleMaxWheelsNumEdit -> value());
    map -> getFirstPopulation() -> setVehicleVectorLength(static_cast<double>(vehicleVectorLengthEdit -> value()) / 50.0);
    map -> getFirstPopulation() -> setVehicleWheelsSize(static_cast<double>(vehicleWheelsSizeEdit -> value()) / 200.0);

    map -> getSecondPopulation() -> setPopulationSize(rightPopulationSizeEdit -> value());
    map -> getSecondPopulation() -> setMaxMutationsCount(maxMutationsCountEdit -> value());
    map -> getSecondPopulation() -> setVehiclePointsNum(vehiclePointsNumEdit -> value());
    map -> getSecondPopulation() -> setVehicleMaxWheelsNum(vehicleMaxWheelsNumEdit -> value());
    map -> getSecondPopulation() -> setVehicleVectorLength(static_cast<double>(vehicleVectorLengthEdit -> value()) / 50.0);
    map -> getSecondPopulation() -> setVehicleWheelsSize(static_cast<double>(vehicleWheelsSizeEdit -> value()) / 200.0);

    map -> getFirstPopulation() -> setPopulationType(populationTestTypeEdit -> checkState() == Qt::Unchecked);
    map -> getSecondPopulation() -> setPopulationType(populationTestTypeEdit -> checkState() == Qt::Unchecked);
    map -> generate();
}

void MainMenu::saveGame()
{
    map -> save(QDir::currentPath() + "\\Saves\\" + saveName -> text());
}

void MainMenu::loadGame()
{
    map -> load(QDir::currentPath() + "\\Saves\\" + loadName -> currentText());
    map -> updateAllPhysics();

    if(gameRunning)
    {
        backButtonClick();
        continueAction();
    }
    else
    {
        gameRunning = true;
        grabKeyboard();
        grabMouse();
        backButtonClick();
        continueAction();
    }
}

//Функция удаления папки
int removeFolder(QString path)
{
    QDir dir = QDir(path);

   int res = 0;
   //Получаем список каталогов
   QStringList lstDirs  = dir.entryList(QDir::Dirs  |
                                   QDir::AllDirs |
                                   QDir::NoDotAndDotDot);
   //Получаем список файлов
   QStringList lstFiles = dir.entryList(QDir::Files);
   //Удаляем файлы
   foreach (QString entry, lstFiles)
   {
      QString entryAbsPath = dir.absolutePath() + "/" + entry;
      QFile::remove(entryAbsPath);
   }
   //Для папок делаем рекурсивный вызов
   foreach (QString entry, lstDirs)
   {
      QString entryAbsPath = dir.absolutePath() + "/" + entry;
      removeFolder(entryAbsPath);
   }
   //Удаляем обрабатываемую папку
   if (!QDir().rmdir(dir.absolutePath()))
   {
      res = 1;
   }
   return res;
}

void MainMenu::deleteGame()
{
    QString initialPath = QDir::currentPath() + "\\Saves\\" + loadName -> currentText();

    QMessageBox msgBox;
    msgBox.setText(tr("Do you want to delete save \"") + loadName -> currentText() + "\"?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    int ret = msgBox.exec();

    if(ret == QMessageBox::Yes)
    {
        removeFolder(initialPath);

        QMessageBox msgBox2;
        msgBox2.setText(tr("Saved game was successfully deleted!"));
        msgBox2.exec();

        showLoadGameOptions();
    }

}

void MainMenu::minDeltaYUpdate(double value)
{
    if(value > maxDeltaYEdit -> value())
    {
        minDeltaYEdit -> setValue(maxDeltaYEdit -> value());
    }
}

void MainMenu::maxDeltaYUpdate(double value)
{
    if(value < minDeltaYEdit -> value())
    {
        maxDeltaYEdit -> setValue(minDeltaYEdit -> value());
    }
}

void MainMenu::vehiclePointsNumChanged(int value)
{
    if(value < vehicleMaxWheelsNumEdit -> value())
    {
        vehicleMaxWheelsNumEdit -> setValue(value);
    }
}

void MainMenu::vehicleMaxWheelsNumChanged(int value)
{
    if(value > vehiclePointsNumEdit -> value())
    {
        vehicleMaxWheelsNumEdit -> setValue(vehiclePointsNumEdit -> value());
    }
}

void MainMenu::createNewGameMenu()
{
    mapLengthEdit = new QSpinBox(this);
    mapLengthEdit -> setMinimum(100);
    mapLengthEdit -> setMaximum(10000);
    mapLengthEdit -> setValue(200);
    mapLengthEdit -> setFixedWidth(maxWidth / 2);
    mapLengthEdit -> setVisible(false);
    mainMenuLayout -> addRow("Map length: ", mapLengthEdit);
    mainMenuLayout -> labelForField(mapLengthEdit) -> setFixedWidth(maxWidth / 2);
    mainMenuLayout -> labelForField(mapLengthEdit) -> setVisible(false);

    deltaXEdit = new QDoubleSpinBox(this);
    deltaXEdit -> setMinimum(0.1);
    deltaXEdit -> setMaximum(1000.0);
    deltaXEdit -> setValue(5.0);
    deltaXEdit -> setFixedWidth(maxWidth / 2);
    deltaXEdit -> setVisible(false);
    mainMenuLayout -> addRow("Delta x: ", deltaXEdit);
    mainMenuLayout -> labelForField(deltaXEdit) -> setFixedWidth(maxWidth / 2);
    mainMenuLayout -> labelForField(deltaXEdit) -> setVisible(false);

    minDeltaYEdit = new QDoubleSpinBox(this);
    minDeltaYEdit -> setMinimum(-1000.0);
    minDeltaYEdit -> setMaximum(1000.0);
    minDeltaYEdit -> setValue(-2.5);
    minDeltaYEdit -> setFixedWidth(maxWidth / 2);
    minDeltaYEdit -> setVisible(false);
    mainMenuLayout -> addRow("Min delta y: ", minDeltaYEdit);
    mainMenuLayout -> labelForField(minDeltaYEdit) -> setFixedWidth(maxWidth / 2);
    mainMenuLayout -> labelForField(minDeltaYEdit) -> setVisible(false);

    maxDeltaYEdit = new QDoubleSpinBox(this);
    maxDeltaYEdit -> setMinimum(-1000.0);
    maxDeltaYEdit -> setMaximum(1000.0);
    maxDeltaYEdit -> setValue(2.5);
    maxDeltaYEdit -> setFixedWidth(maxWidth / 2);
    maxDeltaYEdit -> setVisible(false);
    mainMenuLayout -> addRow("Max delta y: ", maxDeltaYEdit);
    mainMenuLayout -> labelForField(maxDeltaYEdit) -> setFixedWidth(maxWidth / 2);
    mainMenuLayout -> labelForField(maxDeltaYEdit) -> setVisible(false);

    leftPopulationSizeEdit = new QSpinBox(this);
    leftPopulationSizeEdit -> setMinimum(1);
    leftPopulationSizeEdit -> setMaximum(100);
    leftPopulationSizeEdit -> setValue(10);
    leftPopulationSizeEdit -> setFixedWidth(maxWidth / 2);
    leftPopulationSizeEdit -> setVisible(false);
    mainMenuLayout -> addRow("Left population size: ", leftPopulationSizeEdit);
    mainMenuLayout -> labelForField(leftPopulationSizeEdit) -> setFixedWidth(maxWidth / 2);
    mainMenuLayout -> labelForField(leftPopulationSizeEdit) -> setVisible(false);

    rightPopulationSizeEdit = new QSpinBox(this);
    rightPopulationSizeEdit -> setMinimum(1);
    rightPopulationSizeEdit -> setMaximum(100);
    rightPopulationSizeEdit -> setValue(10);
    rightPopulationSizeEdit -> setFixedWidth(maxWidth / 2);
    rightPopulationSizeEdit -> setVisible(false);
    mainMenuLayout -> addRow("Right population size: ", rightPopulationSizeEdit);
    mainMenuLayout -> labelForField(rightPopulationSizeEdit) -> setFixedWidth(maxWidth / 2);
    mainMenuLayout -> labelForField(rightPopulationSizeEdit) -> setVisible(false);

    populationTestTypeEdit = new QCheckBox(this);
    populationTestTypeEdit -> setFixedSize(QSize(populationTestTypeEdit -> minimumSizeHint()));
    populationTestTypeEdit -> setVisible(false);
    mainMenuLayout -> addRow("Test one by one: ", populationTestTypeEdit);
    mainMenuLayout -> labelForField(populationTestTypeEdit) -> setFixedSize(
                 mainMenuLayout -> labelForField(populationTestTypeEdit) -> minimumSizeHint());
    mainMenuLayout -> labelForField(populationTestTypeEdit) -> setVisible(false);

    maxMutationsCountEdit = new QSpinBox(this);
    maxMutationsCountEdit -> setMinimum(0);
    maxMutationsCountEdit -> setMaximum(100);
    maxMutationsCountEdit -> setValue(1);
    maxMutationsCountEdit -> setFixedWidth(maxWidth / 2);
    maxMutationsCountEdit -> setVisible(false);
    mainMenuLayout -> addRow("Maximum mutations: ", maxMutationsCountEdit);
    mainMenuLayout -> labelForField(maxMutationsCountEdit) -> setFixedWidth(maxWidth / 2);
    mainMenuLayout -> labelForField(maxMutationsCountEdit) -> setVisible(false);

    vehiclePointsNumEdit = new QSpinBox(this);
    vehiclePointsNumEdit -> setMinimum(4);
    vehiclePointsNumEdit -> setMaximum(100);
    vehiclePointsNumEdit -> setValue(8);
    vehiclePointsNumEdit -> setFixedWidth(maxWidth / 2);
    vehiclePointsNumEdit -> setVisible(false);
    mainMenuLayout -> addRow("Vectors number: ", vehiclePointsNumEdit);
    mainMenuLayout -> labelForField(vehiclePointsNumEdit) -> setFixedWidth(maxWidth / 2);
    mainMenuLayout -> labelForField(vehiclePointsNumEdit) -> setVisible(false);

    vehicleMaxWheelsNumEdit = new QSpinBox(this);
    vehicleMaxWheelsNumEdit -> setMinimum(0);
    vehicleMaxWheelsNumEdit -> setMaximum(100);
    vehicleMaxWheelsNumEdit -> setValue(4);
    vehicleMaxWheelsNumEdit -> setFixedWidth(maxWidth / 2);
    vehicleMaxWheelsNumEdit -> setVisible(false);
    mainMenuLayout -> addRow("Maximum wheels: ", vehicleMaxWheelsNumEdit);
    mainMenuLayout -> labelForField(vehicleMaxWheelsNumEdit) -> setFixedWidth(maxWidth / 2);
    mainMenuLayout -> labelForField(vehicleMaxWheelsNumEdit) -> setVisible(false);

    vehicleVectorLengthEdit = new QSlider(Qt::Horizontal, this);
    vehicleVectorLengthEdit -> setMinimum(1);
    vehicleVectorLengthEdit -> setMaximum(100);
    vehicleVectorLengthEdit -> setValue(50);
    vehicleVectorLengthEdit -> setFixedWidth(maxWidth / 2);
    vehicleVectorLengthEdit -> setVisible(false);
    mainMenuLayout -> addRow("Vectors length: ", vehicleVectorLengthEdit);
    mainMenuLayout -> labelForField(vehicleVectorLengthEdit) -> setFixedWidth(maxWidth / 2);
    mainMenuLayout -> labelForField(vehicleVectorLengthEdit) -> setVisible(false);

    vehicleWheelsSizeEdit = new QSlider(Qt::Horizontal, this);
    vehicleWheelsSizeEdit -> setMinimum(1);
    vehicleWheelsSizeEdit -> setMaximum(100);
    vehicleWheelsSizeEdit -> setValue(50);
    vehicleWheelsSizeEdit -> setFixedWidth(maxWidth / 2);
    vehicleWheelsSizeEdit -> setVisible(false);
    mainMenuLayout -> addRow("Wheels size: ", vehicleWheelsSizeEdit);
    mainMenuLayout -> labelForField(vehicleWheelsSizeEdit) -> setFixedWidth(maxWidth / 2);
    mainMenuLayout -> labelForField(vehicleWheelsSizeEdit) -> setVisible(false);
}

void MainMenu::createOptionsMenu()
{
    manualEngineControlEdit = new QCheckBox(this);
    manualEngineControlEdit -> setFixedSize(QSize(manualEngineControlEdit -> minimumSizeHint()));
    manualEngineControlEdit -> setVisible(false);
    mainMenuLayout -> addRow("Manual engine control: ", manualEngineControlEdit);
    mainMenuLayout -> labelForField(manualEngineControlEdit) -> setFixedSize(
                 mainMenuLayout -> labelForField(manualEngineControlEdit) -> minimumSizeHint());
    mainMenuLayout -> labelForField(manualEngineControlEdit) -> setVisible(false);
}

void MainMenu::createHelpMenu()
{
    helpLabel = new QLabel(tr("This is help."), this);
    helpLabel -> setFixedWidth(maxWidth);
    helpLabel -> setVisible(false);
    mainMenuLayout -> addRow(helpLabel);
}

void MainMenu::createButtons()
{
    continueButton = new QPushButton(tr("Continue"), this);
    continueButton -> setFixedWidth(maxWidth);
    continueButton -> setVisible(false);
    mainMenuLayout -> addRow(continueButton);

    newGameButton = new QPushButton(tr("New Game"), this);
    newGameButton -> setFixedWidth(maxWidth);
    mainMenuLayout -> addRow(newGameButton);

    saveGameButton = new QPushButton(tr("Save Game"), this);
    saveGameButton -> setFixedWidth(maxWidth);
    saveGameButton -> setVisible(false);
    mainMenuLayout -> addRow(saveGameButton);

    loadGameButton = new QPushButton(tr("Load Game"), this);
    loadGameButton -> setFixedWidth(maxWidth);
    mainMenuLayout -> addRow(loadGameButton);

    optionsButton = new QPushButton(tr("Options"), this);
    optionsButton -> setFixedWidth(maxWidth);
    mainMenuLayout -> addRow(optionsButton);

    helpButton = new QPushButton(tr("Help"), this);
    helpButton -> setFixedWidth(maxWidth);
    mainMenuLayout -> addRow(helpButton);

    exitButton = new QPushButton(tr("Exit"), this);
    exitButton -> setFixedWidth(maxWidth);
    mainMenuLayout -> addRow(exitButton);

    startButton = new QPushButton(tr("Start"), this);
    startButton -> setFixedWidth(maxWidth);
    mainMenuLayout -> addRow(startButton);
    startButton -> setVisible(false);

    saveButton = new QPushButton(tr("Save"), this);
    saveButton -> setFixedWidth(maxWidth);
    saveButton -> setVisible(false);
    mainMenuLayout -> addRow(saveButton);

    loadButton = new QPushButton(tr("Load"), this);
    loadButton -> setFixedWidth(maxWidth);
    loadButton -> setVisible(false);
    mainMenuLayout -> addRow(loadButton);

    deleteButton = new QPushButton(tr("Delete"), this);
    deleteButton -> setFixedWidth(maxWidth);
    mainMenuLayout -> addRow(deleteButton);
    deleteButton -> setVisible(false);

    backButton = new QPushButton(tr("Back"), this);
    backButton -> setFixedWidth(maxWidth);
    mainMenuLayout -> addRow(backButton);
    backButton -> setVisible(false);

    setLayout(mainMenuLayout);
}

void MainMenu::createActions()
{
    connect(continueButton, SIGNAL(pressed()), this, SLOT(continueAction()));
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(showNewGameOptions()));
    connect(saveGameButton, SIGNAL(clicked()), this, SLOT(showSaveGameOptions()));
    connect(loadGameButton, SIGNAL(clicked()), this, SLOT(showLoadGameOptions()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteGame()));
    connect(optionsButton, SIGNAL(clicked()), this, SLOT(showOptions()));
    connect(helpButton, SIGNAL(clicked()), this, SLOT(showHelp()));
    connect(exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(startButton, SIGNAL(clicked()), this, SLOT(startNewGame()));
    connect(loadButton, SIGNAL(clicked()), this, SLOT(loadGame()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveGame()));
    connect(backButton, SIGNAL(clicked()), this, SLOT(backButtonClick()));

    connect(minDeltaYEdit, SIGNAL(valueChanged(double)), this, SLOT(minDeltaYUpdate(double)));
    connect(maxDeltaYEdit, SIGNAL(valueChanged(double)), this, SLOT(maxDeltaYUpdate(double)));

    connect(vehiclePointsNumEdit, SIGNAL(valueChanged(int)), this, SLOT(vehiclePointsNumChanged(int)));
    connect(vehicleMaxWheelsNumEdit, SIGNAL(valueChanged(int)), this, SLOT(vehicleMaxWheelsNumChanged(int)));

    connect(continueGameAction, SIGNAL(triggered()), this, SLOT(continueAction()));
}

void MainMenu::moveCameraTo(double x, double y)
{
    if(translateX - x > translateXSpeed)
    {
        translateX -= translateXSpeed;
    } else if(translateX - x < -translateXSpeed)
    {
        translateX += translateXSpeed;
    } else {
        translateX = x;
    }

    if(translateY - y > translateYSpeed)
    {
        translateY -= translateYSpeed;
    } else if(translateY - y < -translateYSpeed)
    {
        translateY += translateYSpeed;
    } else {
        translateY = y;
    }
}
