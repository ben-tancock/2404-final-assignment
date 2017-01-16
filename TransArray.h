#ifndef TRANSARRAY_H
#define TRANSARRAY_H

#include "defs.h"
#include "Transaction.h"
#include <string>

class TransArray
{
  public:
    TransArray();
   ~TransArray();
    void add(Transaction*);
    Transaction& get(int);
    int getSize();
    bool isFound(int);
    bool find(int, TransArray&);
  private:
    Transaction* elements[MAX_ARR];
    int size;
};

#endif
