// customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H
#define MAX_STR_LEN 32
#include "defs.h"
#include <string>
using namespace std;

// unique customer ID and name
class Customer
{
  
  public:
    Customer(int=0, string="");
    int	              getID();
    string 	      getName();
  protected:
    int 	      ID;
    string 	      name;
};

#endif
