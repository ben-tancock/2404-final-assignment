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

#include <string>
#include <cstdlib>
using namespace std;

#include "AcctList.h"
#include <iomanip>
#include <iostream>
#include <sstream>

AcctList::AcctList()
{
  size = 0;
  head = NULL;
  tail = NULL;
}

AcctList::~AcctList()
{
  for(int i = 0; i < getSize(); i++)
  {
    cout << "acct list dtor" << endl;
    cout << i << endl;
    Node* temp = head->next;
    delete head->data;
    delete head;
    head = temp;
  }
}

Account* AcctList::find(int x)
{
  Node* temp = head;
  for(int i = 0; i < size; i++)
  {
   if(temp->data->getAcctNum() == x)
   {
    //acct = *temp;
    return temp->data;
   }
   temp = temp->next;
  }
  return NULL;
}


int AcctList::getSize() { return size; }

Account& AcctList::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return *elements[index]->data;
}

Account* AcctList::getHead() { return head->data; }

void AcctList::add(Account* acct) // ascending order customer id
{
  Node* toAdd = new Node;
  toAdd->data = acct;
  toAdd->next = NULL;
  cout << "toAdd: " + toAdd->data->getName() << endl;
  //cout << toAdd->data->getAcctType() << endl;
 
  if(head != NULL && tail != NULL){
    cout << "head : " +head->data->getName() << endl;
    cout << "tail : " +tail->data->getName() << endl;
  }
  

  if (size >= MAX_ARR)
    return;

  if(size == 0){ // add with no nodes
    cout << "test size 0" << endl;
    head = toAdd;
    tail = toAdd;
    size++;
    return;
  }
  else if(size >= 1){
    if(acct->getCust() <= head->data->getCust()){ // add before the head
      cout << "test add before head" << endl;
      toAdd->next = head;
      head = toAdd;
      size++;
      
      return;	
    }
    if(acct->getCust() >= tail->data->getCust()){ // add after the tail
      cout << "test add after tail" << endl;
      cout << tail->data->getName() << endl;
      tail->next = toAdd;
      tail = toAdd;
      
      size++;
      cout << tail->data->getName() << endl;
      return;	
    }    
    Node* temp = head;
    for(int i = 0; i < size; i++){
      if(acct->getCust() < temp->next->data->getCust()){
	cout << "test add" << endl;
	toAdd->next = temp->next;
	temp->next = toAdd;
	size++;
	return;
      }
      temp = temp->next;
    }
  }
  return;
}

void AcctList::toString(string& outStr)
{
  //cout << "test1" <<endl;
  stringstream ss;
  Node* acct = head;
  Customer* temp;
  for (int i=0; i<size; i++) {

    if (acct->data->getAcctType() == CHEQUING)
      ss << "Chequing:  ";
    else if (acct->data->getAcctType() == SAVINGS)
      ss << "Savings:   ";
    else
      ss << "General:   ";
    
    //cout << "test" << endl;
    //cout << acct->data->getCustPtr()->getName() << endl;
    //temp = acct->data->getCustPtr();
    ss << acct->data->getAcctNum() << "  " << setw(4) << acct->data->getName() << "  " << setw(8) << fixed << setprecision(2) << acct->data->getBalance() << "  $" << endl;

    //cout << "test end" << endl;
    //cout << "next name:" + acct->next->data->getName();
    acct = acct->next;
  }
  outStr = ss.str();
  return;
}

void AcctList::removeAccount(int acctNum)
{
  Node* temp = head;

  if(head->data->getAcctNum() == acctNum){ // remove the head
   temp = head->next;
   delete head;
   head = temp;
   size--;
   return;
  }

  if(tail->data->getAcctNum() == acctNum){ // remove the tail
   while(temp->next != tail)
    temp = temp->next;

   delete tail;
   tail = temp;
   size--;
   return;
  }


  for(int i = 0; i < size; i++)
  {
    if(temp->next == NULL)
      return;

    if(temp->next->data->getAcctNum() == acctNum)
    {
      Node* next = temp->next->next;
      delete temp->next;
      temp->next = next;
      size--;
      return;
    }
    temp = temp->next;
    
  }
}




