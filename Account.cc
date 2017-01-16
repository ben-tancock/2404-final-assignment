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

#include "defs.h"
#include "Account.h"

int Account::nextAcctNum = 7001;

Account::Account(Customer* c, AcctType t) 
{ 
  acctNum  = nextAcctNum++;
  acctType = t;
  custPtr = c;
  balance  = 0;
}

Account::~Account(){
  cout << "acct destructor" << endl;
 }

/*Account::Account(AcctType t) 
{ 
  acctNum  = nextAcctNum++;
  acctType = t;
  balance  = 0;
}
*/

AcctType Account::getAcctType() { return acctType; }
int      Account::getAcctNum()  { return acctNum;  }
int      Account::getCust()     {return custPtr->getID(); }//return cust;     }
string   Account::getName()     {return custPtr->getName();}
Customer* Account::getCustPtr() {return custPtr;}
float    Account::getBalance()  { return balance;  }
void     Account::setBalance(int amt) {this->balance = amt;}
