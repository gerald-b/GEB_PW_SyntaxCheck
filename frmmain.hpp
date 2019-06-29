#ifndef FRMMAIN_HPP
#define FRMMAIN_HPP

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

// all includes for checks
#include "icheck.hpp"
#include "chkpwlength.hpp"
#include "chkcontainsuppercase.hpp"

namespace Ui {
class FrmMain;
}

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

private slots:
    void on_actionImport_triggered();
    void on_actionExport_triggered();
    void on_actionCheck_triggered();

private:
    Ui::FrmMain *ui;
    void updateStatus();
};

#endif // FRMMAIN_HPP
