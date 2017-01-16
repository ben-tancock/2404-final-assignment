#include "defs.h"
#include "Logger.h"
#include "BankControl.h"
#include "TransArray.h"
#include <string>

Logger::Logger(BankControl* b)
{
  bctrl = b;

}

void Logger::update()
{
  //cout << "hi" << endl;
  //int tSize = bctrl.getTransSize();
  Transaction* t = bctrl->getLatest();
  //cout << "hi" << endl;
  if(t->amount > 1000){
    cout << "hi" << endl;
    transactions.add(t);
    return;
  }
  return;
}
