// CustArray.h

#ifndef CUSTARRAY_H
#define CUSTARRAY_H

#include "defs.h"
#include "Customer.h"
#include <string>

class CustArray
{
  public:
    CustArray();
   ~CustArray();
    void add(Customer*);
    Customer* get(int);
    int getSize();
    bool isFound(int);
    bool find(int, Customer&);
  private:
    Customer* elements[MAX_ARR];
    int size;
};

#endif
