#ifndef FRMMAIN_HPP
#define FRMMAIN_HPP

#include <QMainWindow>

namespace Ui {
class FrmMain;
}

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

private:
    Ui::FrmMain *ui;
    void updateStatus();
};

#endif // FRMMAIN_HPP
