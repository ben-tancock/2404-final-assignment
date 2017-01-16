#include <string>
#include <cstdlib>
#include "TransArray.h"
#include<iostream>
using namespace std;



TransArray::TransArray()
{
  size = 0;
}

TransArray::~TransArray()
{
  for(int i = 0; i < getSize(); i++)
  {
    delete elements[i];
  }
}

int TransArray::getSize() { cout << "test tArr size" << endl; return size; }

Transaction& TransArray::get(int index)
{
  cout << "test transArr get start" << endl;
  cout << index << endl;
  cout << size << endl;
  if (index < 0 || index >= size){
    cout << "test exit" << endl;
    exit(1);
  }
  cout << "test get" << endl;
  return *elements[index];
}

void TransArray::add(Transaction* trans)
{
  if (size >= MAX_ARR)
    return;

  elements[size++] = trans;
}

