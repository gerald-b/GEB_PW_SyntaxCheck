#include "frmmain.hpp"
#include "ui_frmmain.h"

FrmMain::FrmMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmMain)
{
    ui->setupUi(this);
    /* Connects for the Menue */
    connect(ui->actionExit,&QAction::triggered,this,&FrmMain::close);

    this->setWindowTitle(tr("GEB_PW_SyntaxCheck"));
    this->updateStatus();
}

FrmMain::~FrmMain()
{
    delete ui;
}

void FrmMain::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn =
        QMessageBox::question(this,tr("Question"),tr("Do you really want to exit?"),
            QMessageBox::No | QMessageBox::Yes,
            QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes)
    {
        event->ignore();
    }
    else
    {
        event->accept();
    }
}

void FrmMain::updateStatus()
{
    if (ui->lstPassword->count() == 1)
    {
        ui->statusBar->showMessage(QString::number(ui->lstPassword->count()) + " " + tr(" Entry"));
    }
    else
    {
        ui->statusBar->showMessage(QString::number(ui->lstPassword->count()) + " " + tr(" Entries"));
    }
}
