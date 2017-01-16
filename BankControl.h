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

#ifndef BANKCONTROL_H
#define BANKCONTROL_H

#include "Bank.h"
#include "Observer.h"
#include "Subject.h"
#include "View.h"
#include "TransControl.h"
#include "Logger.h"
#include "defs.h"



class BankControl: public Subject
{
 
  public:
    BankControl();
    void launch();
    int getTransSize();
    Transaction* getLatest();
    
  private:
    Bank bank;
    View view;
    Logger logger;
    TransControl transctrl;
    void init();
    void processAdmin();
    void processCust();
    virtual void subscribe(Observer*);
    virtual void unsubscribe(Observer*);
    virtual void notify();
    
};





#endif
