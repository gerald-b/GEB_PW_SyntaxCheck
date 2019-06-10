#ifndef ICHECK
#define ICHECK

#include <QObject>
#include <QString>

class iCheck: public QObject
{
    Q_OBJECT
public:
    iCheck() {}
    virtual ~iCheck() {}
    virtual bool check(QString s) = 0;

private:
};

#endif // ICHECK

