#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#include "defs.h"
#include "Observer.h"
#include <vector>
//#include "Bank.h"
//#include "BankControl.h"
//#include "TransControl.h"
//#include "Transaction.h"
//#include "TransArray.h"


class Subject
{
  public:
	  virtual void subscribe(Observer*)=0;
	  virtual void unsubscribe(Observer*)=0;
	  virtual void notify() = 0;
	  //int s = 64;
	  Observer* observers[];
	  int oSize;


};
#endif 
