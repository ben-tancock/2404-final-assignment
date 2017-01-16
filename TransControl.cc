#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

#include "TransControl.h"
#include "Account.h"
#include "Customer.h"

TransControl::TransControl()
{
  
}

void TransControl::update(Transaction* trans)
{
  string time;
  this->getTime(time);
  trans->date = time;
  transactions.add(trans);
}

void TransControl::retrieve(TransArray& arr)
{
  for(int i = 0; i < transactions.getSize(); i++){
    Transaction* t = &(transactions.get(i));
    arr.add(t);
  }
}

int TransControl::getSize(){return transactions.getSize();}
Transaction& TransControl::get(int i){cout << "test T get" << endl; return transactions.get(i);}

void TransControl::getTime(string& outTime)
{
  time_t rawTime;
  struct tm* myTime;
  stringstream ss1, ss2, ss3;


  time(&rawTime);
  myTime = localtime(&rawTime);

  ss2 << setfill('0') << setw(2);
  ss3 << setfill('0') << setw(2);

  ss1 << myTime->tm_year + 1900;
  ss2 << myTime->tm_mon + 1;
  ss3 << myTime->tm_mday;

  outTime = "";

  outTime += ss1.str();
  outTime += "/";
  outTime += ss2.str();
  outTime += "/";
  outTime += ss3.str();

}


