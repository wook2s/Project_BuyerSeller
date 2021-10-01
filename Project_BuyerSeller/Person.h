#pragma once
#include <cstring>
#include <iostream>
#include <string>

class Person
{
protected:
	char* name;
	int money;
	int numOfApple;
public:
	Person(std::string name, int money, int numOfApple); 
	~Person();
	virtual void showData() {}
	int getMoney();;
	int getNumOfApple();
	void setMoney(int money);
	void setNumOfApple(int num);
	char* getName();
	void showName();

	void setPerson(std::string sName, int sMoney, int sNum);


};