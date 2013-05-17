#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "backend/QSimpleCalc.h"
#include "mathlib/StringConstants.h"
#include "mathlib/Exceptions.h"

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
    connect(ui->expText,        SIGNAL(returnPressed()), SLOT(onExePressed()));
    connect(ui->exeButton,      SIGNAL(clicked()),       SLOT(onExePressed()));
    connect(ui->n0Button,       SIGNAL(clicked()),       SLOT(onN0Pressed()));
    connect(ui->n1Button,       SIGNAL(clicked()),       SLOT(onN1Pressed()));
    connect(ui->n2Button,       SIGNAL(clicked()),       SLOT(onN2Pressed()));
    connect(ui->n3Button,       SIGNAL(clicked()),       SLOT(onN3Pressed()));
    connect(ui->n4Button,       SIGNAL(clicked()),       SLOT(onN4Pressed()));
    connect(ui->n5Button,       SIGNAL(clicked()),       SLOT(onN5Pressed()));
    connect(ui->n6Button,       SIGNAL(clicked()),       SLOT(onN6Pressed()));
    connect(ui->n7Button,       SIGNAL(clicked()),       SLOT(onN7Pressed()));
    connect(ui->n8Button,       SIGNAL(clicked()),       SLOT(onN8Pressed()));
    connect(ui->n9Button,       SIGNAL(clicked()),       SLOT(onN9Pressed()));
    connect(ui->divButton,      SIGNAL(clicked()),       SLOT(onDivPressed()));
    connect(ui->multButton,     SIGNAL(clicked()),       SLOT(onMultPressed()));
    connect(ui->subsButton,     SIGNAL(clicked()),       SLOT(onSubsPressed()));
    connect(ui->addButton,      SIGNAL(clicked()),       SLOT(onAddPressed()));
    connect(ui->logButton,      SIGNAL(clicked()),       SLOT(onLogPressed()));
    connect(ui->dotButton,      SIGNAL(clicked()),       SLOT(onDotPressed()));
    connect(ui->eqButton,       SIGNAL(clicked()),       SLOT(onEqPressed()));
    connect(ui->xButton,        SIGNAL(clicked()),       SLOT(onXPressed()));
    connect(ui->oParButton,     SIGNAL(clicked()),       SLOT(onOParPressed()));
    connect(ui->cParButton,     SIGNAL(clicked()),       SLOT(onCParPressed()));
    connect(ui->delButton,      SIGNAL(clicked()),       SLOT(onDelPressed()));
    connect(ui->clButton,       SIGNAL(clicked()),       SLOT(clear()));
}

void MainWindow::onExePressed()
{
    if (ui->expText->text().trimmed().isEmpty()) {
        ui->expText->setText("");
        ui->resultText->setText("");
    } else {
        QString errMsg;
        double result = 0;

        try {
            result = QSimpleCalc().eval(ui->expText->text(), &errMsg);
        } catch (DivByZeroException &) {
            errMsg = tr("Division by zero is undefined");
        } catch (LogZeroException &) {
            errMsg = tr("Log of zero is undefined");
        } catch (LogNegativeException &) {
            errMsg = tr("Log of negative numbers is not supported");
        } catch (NullValueException &) {
            errMsg = tr("Null value");
        } catch (InvalidSyntaxException &) {
            errMsg = tr("Invalid syntax");
        }

        if (errMsg.isEmpty()) {
            ui->resultText->setText(QString::number(result, 'g', 12));
        } else {
            ui->resultText->setText(errMsg);
        }
    }
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
    append(STR_DIV);
}

void MainWindow::onMultPressed()
{
    append(STR_MULT);
}

void MainWindow::onAddPressed()
{
    append(STR_ADD);
}

void MainWindow::onSubsPressed()
{
    append(STR_SUBS);
}

void MainWindow::onLogPressed()
{
    append(STR_LOG);
}

void MainWindow::onEqPressed()
{
    append(STR_EQ);
}

void MainWindow::onXPressed()
{
    append(STR_X);
}

void MainWindow::onDotPressed()
{
    append(STR_DOT);
}

void MainWindow::onOParPressed()
{
    append(STR_OPAR);
}

void MainWindow::onCParPressed()
{
    append(STR_CPAR);
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
