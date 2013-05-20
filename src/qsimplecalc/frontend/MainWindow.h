/*
 * Copyright (C) 2013 Andres Pagliano.
 *
 * This file is part of QSimpleCalc.
 *
 * QSimpleCalc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QSimpleCalc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QSimpleCalc.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

/**
 * @brief The MainWindow class provides the application main window.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    /**
     * @brief Constructs a MainWindow object which is a child of \a parent.
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
     * @brief Destroys the window.
     */
    ~MainWindow();
    
public slots:

    /**
     * @brief Clears all the user input from the window
     */
    void clear();

private:
    Ui::MainWindow *ui;

    void connectSignals();
    void append(const QString &s);

private slots:
    void onExePressed();
    void onN0Pressed();
    void onN1Pressed();
    void onN2Pressed();
    void onN3Pressed();
    void onN4Pressed();
    void onN5Pressed();
    void onN6Pressed();
    void onN7Pressed();
    void onN8Pressed();
    void onN9Pressed();
    void onDivPressed();
    void onMultPressed();
    void onAddPressed();
    void onSubsPressed();
    void onLogPressed();
    void onEqPressed();
    void onXPressed();
    void onOParPressed();
    void onCParPressed();
    void onDotPressed();
    void onDelPressed();
    void onHelpPressed();
};

#endif // MAINWINDOW_H
