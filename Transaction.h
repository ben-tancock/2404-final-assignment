

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "defs.h"
#include <string>
using namespace std;

enum Type{DEPOSIT, WITHDRAWAL, PURCHASE, CHEQUE};
enum State{SUCCESS, FAIL};

class Transaction
{
  public:
    Transaction();
    Transaction(Type, State, int, int);
    int id;
    Type type;
    State state;
    string date;
    int acctNum;
    int amount;
    string printData(); 
  private:
    static int nextTransNum;
};

#endif
