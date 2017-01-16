// customer class

#include "defs.h"
#include "Customer.h"
#include <string>


Customer::Customer(int x, string c) 
{ 
  name = c;
  ID = x;
}


int      	    Customer::getID()    { return ID;     }
string  	    Customer::getName()  { return name;  }
