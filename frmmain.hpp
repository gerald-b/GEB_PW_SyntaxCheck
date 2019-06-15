#ifndef FRMMAIN_HPP
#define FRMMAIN_HPP

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

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

private:
    Ui::FrmMain *ui;
};

#endif // FRMMAIN_HPP
