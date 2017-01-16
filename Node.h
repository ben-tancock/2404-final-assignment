// customer.h

#ifndef NODE_H
#define NODE_H
#include "defs.h"
#include "Account.h"
#include <string>
using namespace std;

class Node
{
  friend class AcctList;
  public:
  private:
    Node();
    Node*	      next;
    Account*	      data;
  //protected:
};

#endif
