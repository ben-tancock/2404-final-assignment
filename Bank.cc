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


#include "Bank.h"
#include <string>
#include <stdio.h>
#include <iostream>

AcctList& Bank::getAccounts() { return accounts; }
CustArray& Bank::getCustomers() { return customers; }

void Bank::addAcct(Account* acct)
{
  cout << "acct to add cust id:" << endl;
  cout << acct->getCust() << endl;
  cout << "acct to add cust id:" << endl;
  accounts+=acct;
}

void Bank::addCust(Customer* cust)
{
  customers.add(cust);
}

bool Bank::findCust(int x, Customer** cust)
{
 for(int i = 0; i < this->getCustomers().getSize(); i++)
 {
  if(this->getCustomers().get(i)->getID() == x)
  {
    *cust = getCustomers().get(i);
    return true;
  }
  
 }
 return false;
}

Account* Bank::findAcct(int x)
{
 accounts.find(x);
}

void Bank::removeAccount(int acctNum)
{
  accounts-=acctNum;
}

bool Bank::deposit(float amt, int acctNum)
{
  if(amt < 0){return false;}
  this->findAcct(acctNum)->deposit(amt);
  return true;
}

bool Bank::withdraw(float amt, int acctNum)
{
  if(amt < 0 || this->findAcct(acctNum)->getBalance() < amt){return false;}
  this->findAcct(acctNum)->withdraw(amt);
  return true;
}







