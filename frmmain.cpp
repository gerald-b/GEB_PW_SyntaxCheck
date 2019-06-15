#include "frmmain.hpp"
#include "ui_frmmain.h"

FrmMain::FrmMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmMain)
{
    ui->setupUi(this);
    /* Connects for the Menue */
    connect(ui->actionExit,&QAction::triggered,this,&FrmMain::close);

    /* Automated connects */
    /*** DO NOT UNCOMMENT ***/
    // connect(ui->actionImport,&QAction::triggered,this,&FrmMain::on_actionImport_triggered);

    this->updateStatus();
}

FrmMain::~FrmMain()
{
    delete ui;
}

void FrmMain::on_actionImport_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file for input"),"",
                                                    tr("Text files (*.txt);;csv (*.csv);;All files (*.*)")
                                                    );
    if (!fileName.isEmpty() && QFile::exists(fileName))
    {
        QFile fileToRead(fileName);

        if (!fileToRead.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::critical(this,tr("Error"),tr("Error during opening the file: ") + fileToRead.errorString());
            return;
        }
        int resReplace = QMessageBox::question(this,tr("Question"),
                                               tr("Do you want to replace or keep the list entries?"),
                                               tr("Replace"),
                                               tr("Keep")
                                               );
        if (0 == resReplace) // replace == 0 || keep == 1
        {
            ui->lstPassword->clear();
        }


        QList<QString> myNewEntries;
        for (int i=0; i< ui->lstPassword->count(); ++i)
        {
            myNewEntries.append(ui->lstPassword->item(i)->text());
        }
        bool isFirstTimeDupEntry = true;
        bool removeDupEntry = false;

        while (!fileToRead.atEnd()) {
            QByteArray line = fileToRead.readLine();
            QString s = QString(line);
            s = s.replace("\r\n",""); // for win
            s = s.replace("\n","");   // for lin
            s = s.replace("\r","");   // for mac
            if (myNewEntries.contains(s))
            {
                if (isFirstTimeDupEntry)
                {
                    isFirstTimeDupEntry = false;
                    int resDup  = QMessageBox::question(this,tr("Question"),
                                                        tr("Duplicate entries found. How to proceed with duplicated list entries?"),
                                                        tr("Remove"),
                                                        tr("Keep")
                                                        );
                    if (0 == resDup)
                    {
                        removeDupEntry = true;
                    }
                }
                if (!removeDupEntry)
                {
                    myNewEntries.append(s);
                }
            }

            else
            {
                myNewEntries.append(s);
            }
        }
        ui->lstPassword->clear();
        ui->lstPassword->addItems(myNewEntries);
        fileToRead.close();
        QMessageBox::information(this,tr("Information"),
                                 tr("Import successfull")
                                 );
        this->updateStatus();
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
