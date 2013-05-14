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
    connect(ui->clButton,       SIGNAL(clicked()), SLOT(clear()));
    connect(ui->exeButton,      SIGNAL(clicked()), SLOT(onExePressed()));
    connect(ui->n0Button,       SIGNAL(clicked()), SLOT(onN0Pressed()));
    connect(ui->n1Button,       SIGNAL(clicked()), SLOT(onN1Pressed()));
    connect(ui->n2Button,       SIGNAL(clicked()), SLOT(onN2Pressed()));
    connect(ui->n3Button,       SIGNAL(clicked()), SLOT(onN3Pressed()));
    connect(ui->n4Button,       SIGNAL(clicked()), SLOT(onN4Pressed()));
    connect(ui->n5Button,       SIGNAL(clicked()), SLOT(onN5Pressed()));
    connect(ui->n6Button,       SIGNAL(clicked()), SLOT(onN6Pressed()));
    connect(ui->n7Button,       SIGNAL(clicked()), SLOT(onN7Pressed()));
    connect(ui->n8Button,       SIGNAL(clicked()), SLOT(onN8Pressed()));
    connect(ui->n9Button,       SIGNAL(clicked()), SLOT(onN9Pressed()));
    connect(ui->divButton,      SIGNAL(clicked()), SLOT(onDivPressed()));
    connect(ui->multButton,     SIGNAL(clicked()), SLOT(onMultPressed()));
    connect(ui->subsButton,     SIGNAL(clicked()), SLOT(onSubsPressed()));
    connect(ui->addButton,      SIGNAL(clicked()), SLOT(onAddPressed()));
    connect(ui->logButton,      SIGNAL(clicked()), SLOT(onLogPressed()));
    connect(ui->dotButton,      SIGNAL(clicked()), SLOT(onDotPressed()));
    connect(ui->eqButton,       SIGNAL(clicked()), SLOT(onEqPressed()));
    connect(ui->xButton,        SIGNAL(clicked()), SLOT(onXPressed()));
    connect(ui->openParButton,  SIGNAL(clicked()), SLOT(onOpenParPressed()));
    connect(ui->closeParButton, SIGNAL(clicked()), SLOT(onCloseParPressed()));
    connect(ui->delButton,      SIGNAL(clicked()), SLOT(onDelPressed()));
}

void MainWindow::onExePressed()
{
    double result = QSimpleCalc().eval(ui->expText->text());
    ui->resultText->setText(QString::number(result));
}

void MainWindow::onN0Pressed()
{
    append("0");
}

void MainWindow::onN1Pressed()
{
    append("1");
}

void MainWindow::onN2Pressed()
{
    append("2");
}

void MainWindow::onN3Pressed()
{
    append("3");
}

void MainWindow::onN4Pressed()
{
    append("4");
}

void MainWindow::onN5Pressed()
{
    append("5");
}

void MainWindow::onN6Pressed()
{
    append("6");
}

void MainWindow::onN7Pressed()
{
    append("7");
}

void MainWindow::onN8Pressed()
{
    append("8");
}

void MainWindow::onN9Pressed()
{
    append("9");
}

void MainWindow::onDivPressed()
{
    append("/");
}

void MainWindow::onMultPressed()
{
    append("*");
}

void MainWindow::onAddPressed()
{
    append("+");
}

void MainWindow::onSubsPressed()
{
    append("-");
}

void MainWindow::onLogPressed()
{
    append("log ");
}

void MainWindow::onEqPressed()
{
    append("=");
}

void MainWindow::onXPressed()
{
    append("x");
}

void MainWindow::onDotPressed()
{
    append(".");
}

void MainWindow::onCloseParPressed()
{
    append(")");
}

void MainWindow::onOpenParPressed()
{
    append("(");
}

void MainWindow::append(const QString &s)
{
    ui->expText->setText(ui->expText->text() + s);
}

void MainWindow::onDelPressed()
{
    int expSize = ui->expText->text().size();
    if (expSize > 0) {
        ui->expText->setText(ui->expText->text().mid(0, expSize - 1));
    }
}
