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
    // connect(ui->actionExport,&QAction::triggered,this,&FrmMain::on_actionExport_triggered);
    // connect(ui->actionCheck,&QAction::triggered,this,&FrmMain::on_actionCheck_triggered);

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
        if (ui->lstPassword->count() > 0)
        {
            int resReplace = QMessageBox::question(this,tr("Question"),
                                                   tr("Do you want to replace or keep the list entries?"),
                                                   tr("Replace"),
                                                   tr("Keep")
                                                   );
            if (0 == resReplace) // replace == 0 || keep == 1
            {
                ui->lstPassword->clear();
            }
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

void FrmMain::on_actionExport_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save"),"",tr("Text files (*.txt);;CSV (*.csv)"));
    if (!fileName.isEmpty())
    {
        QFile writeFile(fileName);
        if (!writeFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return;
        }
        for(int i=0; i<ui->lstPassword->count();++i)
        {
#ifdef __linux__
            writeFile.write(ui->lstPassword->item(i)->text().toUtf8() + "\n");
#elif  WIN32 || __WIN32 || __WIN32__
            writeFile.write(ui->lstPassword->item(i)->text().toUtf8() + "\r\n");
#else
            writeFile.write(ui->lstPassword->item(i)->text().toUtf8() + "\r");
#endif
        }
        writeFile.flush();
        writeFile.close();
    }
    QMessageBox::information(this,tr("Information"),tr("Export successfully finished"));
}

void FrmMain::on_actionCheck_triggered()
{
    iCheck *checkrun = nullptr;
    if (ui->lstPassword->count() == 0)
    {
        QMessageBox::warning(this,tr("Warning"),tr("No entries to check"));
        return;
    }
    for(int i=0; i < ui->lstPassword->count(); ++i)
    {
        ui->lstPassword->item(i)->setBackground(Qt::white);

        // CHKPWLENGTH
        if (ui->cbxPWLength->isChecked())
        {
            checkrun = new ChkPWLength(ui->sbxPWMinLength->value(),ui->sbxPWMaxLength->value());

            if (!checkrun->check(ui->lstPassword->item(i)->text()))
            {
                ui->lstPassword->item(i)->setBackground(Qt::red);
            }

            delete checkrun;
        }

        // CHKContainLowerCase
        if(ui->cbxContainsLowerCase->isChecked())
        {
            checkrun = new ChkContainsLowerCase();

            if (!checkrun->check(ui->lstPassword->item(i)->text()))
            {
                ui->lstPassword->item(i)->setBackground(Qt::red);
            }

            delete checkrun;
        }
    }
    QMessageBox::information(this,tr("Information"),tr("Check successfully finished"));
}
