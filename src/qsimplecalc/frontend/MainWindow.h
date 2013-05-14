#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
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
    void onOpenParPressed();
    void onCloseParPressed();
    void onDotPressed();
    void onDelPressed();
};

#endif // MAINWINDOW_H
