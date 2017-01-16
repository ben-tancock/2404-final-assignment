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

#ifndef BANK_H
#define BANK_H

#include "AcctList.h"
#include "Account.h"
#include "CustArray.h"
#include "Customer.h"

class Bank
{
  public:
    void       addAcct(Account*);
    void       addCust(Customer*);
    AcctList&  getAccounts();
    CustArray& getCustomers();
    bool       findCust(int, Customer**);
    Account*   findAcct(int);//, Account&);
    void       removeAccount(int);
    bool       deposit(float, int);
    bool       withdraw(float, int);


  private:
    AcctList   accounts;
    CustArray  customers;
};

#endif
