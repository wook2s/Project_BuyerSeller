#include <iostream>
#include "Person.h"
#include <string>
#include <cstring>

Person::Person(std::string name, int money, int numOfApple) : money(money), numOfApple(numOfApple)
{
	char* tmp = (char*)name.c_str();
	int len = strlen(tmp) + 1;
	Person::name = new char[len];
	strcpy_s(Person::name, len, tmp);
}
Person::~Person()
{
	//delete[]name; //..  에러
}

int Person::getMoney()
{
	return money;
}
int Person::getNumOfApple()
{
	return numOfApple;
}
void Person::setMoney(int money)
{
	Person::money -= money;
}
void Person::setNumOfApple(int num)
{
	Person::numOfApple += num;
}
char* Person::getName()
{
	return name;
}
void Person::showName()
{
	std::cout << name << std::endl;
}
void Person::setPerson(std::string sName, int sMoney, int sNum)
{
	//delete[] name; // 에러발생
	char* tmp = (char*)sName.c_str();
	int len = strlen(tmp) + 1;
	Person::name = new char[len];
	strcpy_s(Person::name, len, tmp);

	money = sMoney;
	numOfApple = sNum;
}
