/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Banking System                */
/*  Author:   Christine Laurendeau                 */
/*  Date:     08-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ACCTLIST_H
#define ACCTLIST_H

#include "defs.h"
#include "Account.h"


class AcctList
{
  class Node{
     friend class AcctList;
     public:
     private:
       Node*	      next;
       Account*	      data;
  };
  
  public:
    AcctList();
   ~AcctList();
    void add(Account*);
    Account& get(int);
    int getSize();
    Account* find(int);
    Account* getHead();
    void toString(string&);
    void removeAccount(int);

    void operator+=(Account* acct) {
	add(acct);
    }

    void operator-=(int acctNum) {
	removeAccount(acctNum);	
    }

  private:
    Node* elements[MAX_ARR];
    int size;
    Node* head;
    Node* tail;
};

#endif

