#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//#include "BankControl.h"
//#include "Subject.h"
//#include "View.h"

//#include "Bank.h"
#include "Observer.h"
//#include "TransControl.h"
//#include "Transaction.h"
#include "TransArray.h"

// concrete observer
class BankControl;
class Logger : public Observer
{
  public:
	Logger(BankControl*);
	virtual void update();
        
	TransArray   transactions;

 private:
 	BankControl* bctrl;


};


#endif
