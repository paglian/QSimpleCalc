#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class provides the calculator main window.
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
};

#endif // MAINWINDOW_H
