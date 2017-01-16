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

#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include "Bank.h"
#include "TransControl.h"
#include "Transaction.h"
#include "TransArray.h"

class TransControl;

class View
{
  public:
    void mainMenu(int&);
    void adminMenu(int&);
    void custMenu(int&);
    void readCustId(int&);
    void readAcctType(AcctType&);
    void printAccounts(Bank&);
    void printCustomers(Bank&);
    void printTrans(TransControl&);
    void printBalance(float);
    void printError(string);
    void printNum(int);
    void pause();
    int removeAccount(Bank&);
    void readTrans(float&, int&);

  private:
    int  readInt();
};

#endif
