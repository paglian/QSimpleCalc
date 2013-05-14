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

private slots:
    void onExePressed();
};

#endif // MAINWINDOW_H
