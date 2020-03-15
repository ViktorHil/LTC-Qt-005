#ifndef BANK_H
#define BANK_H

#include <QObject>

class Bank : public QObject
{
    Q_OBJECT
public:
    explicit Bank(QObject *parent = 0);

    long totalBalance() const;
signals:
    void totalBalanceChanged(long newTotalBalance);

public slots:
    // TODO: declare slot to listen account changes
    void updateTotalBalance();
//    void changedByDeposit( long val);
//    void changedByWithdraw( long val);
};

#endif // BANK_H
