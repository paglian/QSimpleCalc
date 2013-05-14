#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "backend/QSimpleCalc.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clear();

    connectSignals();

    ui->expText->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clear()
{
    ui->resultText->clear();
    ui->expText->clear();
}

void MainWindow::connectSignals()
{
    connect(ui->clButton, SIGNAL(clicked()), SLOT(clear()));
    connect(ui->exeButton, SIGNAL(clicked()), SLOT(onExePressed()));
}

void MainWindow::onExePressed()
{
    double result = QSimpleCalc().eval(ui->expText->text());
    ui->resultText->setText(QString::number(result));
}
