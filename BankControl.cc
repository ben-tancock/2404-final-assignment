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

#include "BankControl.h"
#include "Account.h"
#include "Customer.h"
#include "TransControl.h"
#include "Transaction.h"
//#include "Logger.h"


BankControl::BankControl() : logger(Logger(this))
{
  
  init();
}



int BankControl::getTransSize()
{
	view.printError("test size");
	return transctrl.getSize();
}

Transaction* BankControl::getLatest()
{
	view.printError("test latest");
	return &transctrl.get(getTransSize()-1);
}

void BankControl::subscribe(Observer* o)
{
  observers[oSize++] = o;
}

void BankControl::unsubscribe(Observer* o)
{
  for(int i = 0; i < oSize; i++){
    if(o == observers[i]){
      for(int j = i; j < oSize; j++){
        observers[j] = observers[j+1];
      }
      observers[oSize] = NULL;
      oSize--;      

    }

  }

}

void BankControl::notify()
{
  for(int i = 0; i <= oSize; i++){
	observers[i]->update();
  }

}


void BankControl::launch()
{
  int choice;

  while (1) {
    choice = -1;
    view.mainMenu(choice);
    if (choice == 1) {		// Admin menu
      processAdmin();
    }
    else if (choice == 2) {	// Customer menu
      processCust();
    }
    else {
      break;
    }
  }
}

void BankControl::processAdmin()
{
  int      choice;
  int      custId;
  AcctType acctType;

  while (1) {
    choice = -1;
    view.adminMenu(choice);
    if (choice == 1) {		// add account
      view.readCustId(custId);
      view.readAcctType(acctType);
      Customer* toAddCust;

      if(!bank.findCust(custId, &toAddCust)){
	view.printError("account not found...");
	break;
      }

      if(acctType == GENERAL){
	view.printError("GENERAL");
	GeneralAcct* acct = new GeneralAcct(toAddCust, acctType);
        bank.addAcct(acct);
        view.pause();
      }

      else if(acctType == SAVINGS){
	view.printError("SAVINGS");
	SavingsAcct* acct = new SavingsAcct(toAddCust, acctType, 0, 0);
        bank.addAcct(acct);
        view.pause();
      }

      else if(acctType == CHEQUING){
	view.printError("CHEQUING");
	ChequingAcct* acct = new ChequingAcct(toAddCust, acctType, 0);
        bank.addAcct(acct);
        view.pause();
      }
      
    }
    else if (choice == 2) {	// print accounts
      view.printAccounts(bank);
      view.pause();
    }
    else if (choice == 3) {	// print customers
      view.printCustomers(bank);
      view.pause();
    }
    else if (choice == 4) {	// remove account
      int acctNum = view.removeAccount(bank);
      bank.removeAccount(acctNum);
      view.pause();
    }
    else if (choice == 5) { // print transactions
     TransArray* tArray;
     //transctrl.retrieve(tArray);
     view.printTrans(transctrl);
    }
    else {
      break;
    }
  }
}

void BankControl::processCust()
{
  int choice;
  int AcctNum;
  Account* x;

  while (1) {
    choice = -1;
    view.custMenu(choice);
    if (choice == 1) {	
	view.readCustId(AcctNum);
	
	if(bank.findAcct(AcctNum)!= NULL)
	{
          
          x = bank.findAcct(AcctNum);
	  view.printBalance(x->getBalance());
	}
	else
	{
	  view.printError("Account not found... \n");
	}
    }
    else if(choice == 2){ // deposit
      float amt;
      int acctNum;
      view.readTrans(amt, acctNum);
      if(bank.deposit(amt, acctNum)){ // if the deposit is successful
	Transaction* t = new Transaction(DEPOSIT, SUCCESS, amt, acctNum);
	transctrl.update(t);
	logger.update();
      }
      else{
	Transaction* t = new Transaction(DEPOSIT, FAIL, amt, acctNum);
	transctrl.update(t);
	logger.update();
      }
     
    }
    else if(choice == 3){ // withdraw
      float amt;
      int acctNum;
      view.readTrans(amt, acctNum);
      if(bank.withdraw(amt, acctNum)){ // if the withdrawal is successful
	Transaction* t = new Transaction(WITHDRAWAL, SUCCESS, amt, acctNum);
	transctrl.update(t);
	logger.update();
      }
      else{
	Transaction* t = new Transaction(WITHDRAWAL, FAIL, amt, acctNum);
	transctrl.update(t);
	logger.update();
      }
    }
    else {
      break;
    }
  }
}

void BankControl::init()
{
  /*
     This function is so ugly!  It's because we're using 
     statically allocated memory, instead of dynamically
     alloated.  Don't worry, we'll fix this in Assignment #2.
  */
  // copying info back and forth, in here we are copying, but we're only copying a pointer
  //Customer* cust01 = new Customer(1001, "Mary"); 
  // in this funct you create a customer
  // then we create an account
  // you pass a pointer into this account
  // then when you add to the array, you're creating a new cust for a new account on the heap
  // on the heap yu create a customer and copy over, same with acct
  // but when you copy a pinter, its gonna point to the same place 
  // its pointing to the thing thats in the STACK
  // once this funct is over the STACK FRAME is erased
  // in this function we need to create everything here 

  
  Customer* cust01 = new Customer(1001, "Mary"); 
  bank.addCust(cust01);
  
  Customer* cust02 = new Customer(1002, "Sue"); 
  bank.addCust(cust02);

  Customer* cust03 = new Customer(1003, "Joe"); 
  bank.addCust(cust03);

  Customer* cust04 = new Customer(1004, "Bob"); 
  bank.addCust(cust04);

  Customer* cust05 = new Customer(1005, "Rachel"); 
  bank.addCust(cust05);
  
  Customer* cust06 = new Customer(1006, "John"); 
  bank.addCust(cust06);

  Customer* cust07 = new Customer(1007, "Bill"); 
  bank.addCust(cust07);

  Customer* cust08 = new Customer(1008, "Gary"); 
  bank.addCust(cust08);

  Customer* cust09 = new Customer(1009, "Erica"); 
  bank.addCust(cust09);
  
  Customer* cust10 = new Customer(1010, "Richard"); 
  bank.addCust(cust10);

  Customer* cust11 = new Customer(1011, "Myron Gains"); 
  bank.addCust(cust11);

  Customer* cust12 = new Customer(1012, "Hugh Mungus"); 
  bank.addCust(cust12);
  
  SavingsAcct* acc01 = new SavingsAcct(cust01, SAVINGS, 0.1, 0.1);//, SAVINGS);
  bank.addAcct(acc01);
  SavingsAcct* acc02 = new SavingsAcct(cust01, SAVINGS, 0.2, 0.2);
  bank.addAcct(acc02);
  ChequingAcct* acc03 = new ChequingAcct(cust02, CHEQUING, 0.1);
  bank.addAcct(acc03);

  SavingsAcct* acc04 = new SavingsAcct(cust03, SAVINGS, 0.4, 0.4);
  bank.addAcct(acc04);
  GeneralAcct* acc05 = new GeneralAcct(cust04, GENERAL);
  bank.addAcct(acc05);

  SavingsAcct* acc06 = new SavingsAcct(cust05, SAVINGS, 0.6, 0.6);
  bank.addAcct(acc06);
  ChequingAcct* acc07 = new ChequingAcct(cust05, CHEQUING, 0.3);
  bank.addAcct(acc07);
  GeneralAcct* acc08 = new GeneralAcct(cust06, GENERAL);
  bank.addAcct(acc08);

  ChequingAcct* acc09 = new ChequingAcct(cust07, CHEQUING, 0.2);
  bank.addAcct(acc09);

  SavingsAcct* acc10 = new SavingsAcct(cust08, SAVINGS, 0.7, 0.7);
  bank.addAcct(acc10);
  GeneralAcct* acc11 = new GeneralAcct(cust09, GENERAL);
  bank.addAcct(acc11);

  ChequingAcct* acc12 = new ChequingAcct(cust10, CHEQUING, 0.1);
  bank.addAcct(acc12);
  GeneralAcct* acc13 = new GeneralAcct(cust11, GENERAL);
  bank.addAcct(acc13);

  SavingsAcct* acc14 = new SavingsAcct(cust12, SAVINGS, 0.15, 0.15);
  bank.addAcct(acc14);
  SavingsAcct* acc15 = new SavingsAcct(cust12, SAVINGS, 0.16, 0.16);
  bank.addAcct(acc15);
}






