#include "frmmain.hpp"
#include "ui_frmmain.h"

FrmMain::FrmMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmMain)
{
    ui->setupUi(this);
    /* Connects for the Menue */
    connect(ui->actionExit,&QAction::triggered,this,&FrmMain::close);

    this->updateStatus();
}

FrmMain::~FrmMain()
{
    delete ui;
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
