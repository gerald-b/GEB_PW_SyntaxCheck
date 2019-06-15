#ifndef FRMMAIN_HPP
#define FRMMAIN_HPP

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>

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
    void closeEvent (QCloseEvent *event);

private:
    Ui::FrmMain *ui;
    void updateStatus();
};

#endif // FRMMAIN_HPP
