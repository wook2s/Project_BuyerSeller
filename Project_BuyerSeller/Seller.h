#pragma once
#include <iostream>
#include "Person.h"
class Buyer;

class Seller : public Person
{
private:
	int price;
	int serial;
public:

	Seller(std::string name = "", int money = 10000, int apple = 100, int price = 500);
	~Seller();
	void sell(Buyer* b, int num);
	void showData();
	int getPrice();
	void setPrice(int price);
	void setMoney(int money); // override
	void setNumOfApple(int num); // override
	void setPerson(std::string sName, int sMoney, int sNum, int sPrice);// override
	static int checkNum;
	int getSerial();

};


