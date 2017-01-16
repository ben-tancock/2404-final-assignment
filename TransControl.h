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

#ifndef TRANSCONTROL_H
#define TRANSCONTROL_H

#include "TransArray.h"
#include "Bank.h"
#include "View.h"

class TransControl
{
  public:
    TransControl();
    void launch();
    void update(Transaction*);
    void retrieve(TransArray&);
    int getSize();
    Transaction& get(int);
    void getTime(string&);
  private:
    /*Bank bank;
    View view;
    void init();
    void processAdmin();
    void processCust();*/
    TransArray transactions;
};
#endif
