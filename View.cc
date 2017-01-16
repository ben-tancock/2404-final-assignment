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

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "View.h"
using namespace std;

void View::mainMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   BANKING SYSTEM MAIN MENU\n\n";
  cout<< "          1. Admin menu \n\n";
  cout<< "          2. Customer menu \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 2) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void View::adminMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   BANKING SYSTEM ADMIN MENU\n\n";
  cout<< "          1. Add account \n\n";
  cout<< "          2. Print accounts \n\n";
  cout<< "          3. Print customers \n\n";
  cout<< "          4. Remove Account \n\n";
  cout<< "          5. Print Transactions \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 5) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void View::custMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   BANKING SYSTEM CUSTOMER MENU\n\n";
  cout<< "          1. Check balance \n\n";
  cout<< "          2. Deposit \n\n";
  cout<< "          3. Withdrawal \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 3) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void View::printAccounts(Bank& bank)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.

  stringstream ss;

  cout << endl << "ACCOUNTS: " << endl;
  cout<< endl << bank.getAccounts().getSize() << endl;

  string output;

  bank.getAccounts().toString(output);
  cout << output << endl;
}

void View::printCustomers(Bank& bank)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.

  stringstream ss;
  
  string s;
  cout << endl << "CUSTOMERS: " << endl;
  cout << endl << bank.getCustomers().getSize() << endl;
  for (int i=0; i<bank.getCustomers().getSize(); i++) {

    Customer* cust = bank.getCustomers().get(i);
    ostringstream convert;
    cout << "Name:  " + cust->getName()+ " ";
    int x = cust->getID();
    convert << x;
    s = "";
    s = convert.str();
    cout << "ID:  " + s << endl;
    ss.str("");
  }
}

void View::printTrans(TransControl& tctrl)
{
  stringstream ss;
  
  string s;
  cout << endl << "TRANSACTIONS: " << endl;
  cout << endl << tctrl.getSize() << endl;
  for (int i=0; i<tctrl.getSize(); i++) {

    Transaction& t = tctrl.get(i);
    ostringstream convert;
    cout << t.printData();
  }
}

void View::printBalance(float b)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.

  stringstream ss;
  ss << setw(8) << fixed << setprecision(2) << b;
  cout << endl << "Your balance is $" << ss.str() << endl << " -- press enter to continue...";
  cin.get();
}

void View::printError(string err)
{
  cout << endl << err << " -- press enter to continue...";
  cin.get();
}

void View::printNum(int n)
{
  stringstream ss;
  ss << n;
  cout << endl << "custID: " + ss.str();
}

void View::readCustId(int& id)
{
  string str;
  cout << "Customer id: ";
  getline(cin, str);
  stringstream ss(str);
  ss >> id;
}

void View::readAcctType(AcctType& acctType)
{
  string str;
  int    num;

  cout << "Account type [1 for chequing, 2 for savings, 3 for general]: ";
  getline(cin, str);
  stringstream ss(str);
  ss >> num;
  
  if (num == 1)
    acctType = CHEQUING;
  else if (num == 2)
    acctType = SAVINGS;
  else
    acctType = GENERAL;
}

int View::readInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

void View::readTrans(float& amt, int& acctNum)
{
  cout << endl << "enter account #: ";
  cin >> acctNum; cin.ignore();

  cout << endl << "enter amount: ";
  cin >> amt; cin.ignore();
}

void View::pause()
{
  string str;
  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}


int View::removeAccount(Bank& bank)
{
  int acctNum;
  string str;
  cout << "Account id: ";
  getline(cin, str);
  stringstream ss(str);
  ss >> acctNum;
  return acctNum;
 // bank.removeAccount(acctNum);
}
