#include <QDebug>
#include "bankaccount.h"

BankAccount::BankAccount(Bank *parentBank) : QObject(parentBank)
{
    m_balance = 0;
    // TODO: connect Bank slots to BankAccount signals
    connect(this, SIGNAL(balanceChanged(long)), parentBank, SLOT(updateTotalBalance()));

    qDebug() << "BankAccount was created";
}

BankAccount::~BankAccount()
{
    qDebug() << "BankAccount was destroyed";
}

long BankAccount::balance() const
{
    return m_balance;
}

void BankAccount::setBalance(long newBalance)
{
    m_balance = newBalance;
    // TODO: add here signal emition
    emit balanceChanged( newBalance);
}

void BankAccount::deposit(long amount)
{
    // TODO: implement this function
    m_balance += amount;
    emit balanceChanged( amount);
}

void BankAccount::withdraw(long amount)
{
    // TODO: implement this function
    m_balance -= amount;
    emit balanceChanged( amount);
}
