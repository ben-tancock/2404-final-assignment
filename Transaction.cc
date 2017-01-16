#include "defs.h"
#include "Transaction.h"
#include <string>
#include <sstream>

int Transaction::nextTransNum = 1001;

Transaction::Transaction() 
{ 
  id = nextTransNum++;
}

Transaction::Transaction(Type t, State s, int a, int n) 
{ 
  id = nextTransNum++;
  type = t;
  state = s;
  amount = a;
  acctNum = n;
}



string Transaction::printData()
{
  ostringstream convert;
  string output;
  convert << id;
  output += "Transaction ID:" + convert.str() + " ";
  convert.str("");
  if(type == WITHDRAWAL){
   output += " Type:WITHDRAWAL ";
  }
  else{
   output += " Type:DEPOSIT    ";
  }

  convert << amount;
  output += " Amount:" + convert.str();
  convert.str("");
  convert << acctNum;  
  output += " Account #:" + convert.str();
  convert.str("");
  if(state == SUCCESS){
   output += " State:SUCCESS ";
  }
  else{
   output += " State:FAIL    ";
  }
  output += " Date:" + date + "\n";
  return output;

}


