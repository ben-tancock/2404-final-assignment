#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//#include "Bank.h"
//#include "BankControl.h"
//#include "Logger.h"
//include "Subject.h"
//#include "TransControl.h"
//#include "Transaction.h"
//#include "TransArray.h"
//  observer
class Observer
{
  public:
	virtual void update() = 0;



};


#endif
