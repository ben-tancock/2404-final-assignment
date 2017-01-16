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

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "defs.h"
#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;

// store two initialized data members: interest rate and penalty amount
// interest rate: applied as bonus to every amount deposited into savings acct
// e.g. if rate = 10% and 340 is deposited, actual amount 340 + (340*0.10) = 340 + 34

// penalty: deduction imposed every withdrawal (opposite of savings account)

class Account
{
  public:
    //Account(AcctType t=GENERAL) : acctType(t) {};
    Account(Customer*, AcctType t=GENERAL);
    virtual ~Account() = 0;
    AcctType   getAcctType();
    int        getAcctNum();
    int        getCust();
    float      getBalance();
    void       setBalance(int);
    Customer*  getCustPtr();
    string     getName();
    virtual void deposit(float&)=0;
    virtual void withdraw(float&)=0;
    
  private:
    static int nextAcctNum;
    AcctType   acctType;
    int        acctNum;
    Customer*   custPtr;
    float      balance;
};

class SavingsAcct : public Account
{
  public:
    SavingsAcct(Customer* c=NULL, AcctType t=SAVINGS, float i=0, float p=0) : Account(c, t), interest(i), penalty(p) {};
    
   ~SavingsAcct(){
     cout << "savings destructor" << endl;
   }

    float	interest;
    float	penalty;

    virtual void       deposit(float& amt)  {
	int a = getBalance() + (amt + (amt*interest));
	setBalance(a);

    }

     virtual void       withdraw(float& amt)  {
	int a = getBalance() - (amt + (amt*penalty));
	setBalance(a);

    }
};

class ChequingAcct : public Account
{
    // deduction on every withdrawal (if the cheque costs 50 cents and the withdrawal is 40$ the 
    // amount deducted is $40 + $0.50 = $40.50
  public:
    ChequingAcct(Customer* c=NULL, AcctType t=CHEQUING, float cheque=0) : Account(c, t), chequeCost(cheque) {};
    virtual void       deposit(float& amt){int a = getBalance()+amt; setBalance(a);}

     virtual void       withdraw(float& amt)  {
	int a = getBalance() - (amt + chequeCost);
	setBalance(a);

    }
    
    ~ChequingAcct(){
	cout << "chequing dtor" << endl;
    }

    float        chequeCost;

};

class GeneralAcct : public Account
{
  public:
    GeneralAcct(Customer* c=NULL, AcctType t=GENERAL) : Account(c, t) {};

    ~GeneralAcct(){
	cout << "general dtor" << endl;
    }

    virtual void       deposit(float& amt){int a = getBalance()+amt; setBalance(a);}
    virtual void       withdraw(float& amt){int a = getBalance()-amt; setBalance(a);}


    // doesn't store anything new

};


#endif
