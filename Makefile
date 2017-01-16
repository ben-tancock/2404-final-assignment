OBJ = main.o BankControl.o Bank.o Account.o Customer.o View.o CustArray.o AcctList.o Transaction.o TransArray.o TransControl.o Observer.o Subject.o Logger.o

bsys:	$(OBJ)
	g++ -o bsys $(OBJ)

main.o:	main.cc 
	g++ -g -c main.cc

BankControl.o:	BankControl.cc BankControl.h Bank.h View.h
	g++ -g -c BankControl.cc

View.o:	View.cc View.h 
	g++ -g -c View.cc

Bank.o:	Bank.cc Bank.h AcctList.h  
	g++ -g -c Bank.cc

Account.o:	Account.cc Account.h 
	g++ -g -c Account.cc


AcctList.o:	AcctList.cc AcctList.h Account.h defs.h
	g++ -g -c AcctList.cc

Customer.o:	Customer.cc Customer.h
	g++ -g -c Customer.cc

CustArray.o:	CustArray.cc CustArray.h Customer.h defs.h
	g++ -g -c CustArray.cc

Transaction.o: Transaction.cc Transaction.h 
	g++ -g -c Transaction.cc

TransArray.o: TransArray.cc TransArray.h  Transaction.h defs.h
	g++ -g -c TransArray.cc

TransControl.o: TransControl.cc TransControl.h 
	g++ -g -c TransControl.cc

Subject.o: Subject.h Subject.cc
	g++ -g -c Subject.cc

Observer.o: Observer.h Observer.cc
	g++ -g -c Observer.cc

Logger.o: Logger.h Logger.cc
	g++ -g -c Logger.cc

clean:
	rm -f $(OBJ) bsys
