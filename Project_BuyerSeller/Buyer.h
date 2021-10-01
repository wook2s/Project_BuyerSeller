#pragma once
#include <iostream>

#include "Person.h"

class Seller;

class Buyer : public Person
{
private:
	int serial;
public:
	Buyer(std::string name = "", int money = 10000, int apple = 0);
	~Buyer();
	void buy(Seller* s, int num);
	void showData();
	static int checkNum;
	int getSerial();
};

