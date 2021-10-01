#include <iostream>
#include "Seller.h"
#include "Buyer.h"
#include "Person.h"

class Person;
class Buyer;

Seller::Seller(std::string name, int money, int apple, int price) : Person(name, money, apple), price(price)
{
	serial = checkNum++;
}

Seller::~Seller()
{}

void Seller::showData()
{
	std::cout << "----- Seller 정보 -----\n";
	std::cout << "등록 번호 : " << getSerial() << std::endl;
	std::cout << "이름 : ";
	showName();
	std::cout << "현재 잔액 : " << Seller::getMoney() << " 원" << std::endl;
	std::cout << "사과 갯수 : " << Seller::getNumOfApple() << " 개" << std::endl;
	std::cout << "사과 가격 : " << price << " 원" << std::endl;
	std::cout << "-----------------------\n";
	std::cout << "\n";
}

int Seller::getPrice()
{
	return price;
}

void Seller::sell(Buyer* b, int num)
{
	if (num > Seller::getNumOfApple())
	{
		std::cout << "사과 갯수 부족, 판매불가 \n";
	}
	else
	{
		std::cout << "Seller 가 " << num << "개를 판매합니다 \n";
		int price = getPrice() * num;
		this->setNumOfApple(num);
		this->setMoney(price);
		b->setNumOfApple(num);
		b->setMoney(price);
		b->showData();
		this->showData();
	}
}

void Seller::setPrice(int price)
{
	std::cout << "Seller가 사과 가격을 " << getPrice() << " 에서 " << price << "으로 바꿉니다\n";
	Seller::price = price;
}

void Seller::setMoney(int money)
{
	this->money += money;
}
void Seller::setNumOfApple(int num)
{
	numOfApple -= num;
}
int Seller::getSerial()
{
	return serial;
}
void Seller::setPerson(std::string sName, int sMoney, int sNum, int sPrice)
{
	//delete[] name; // 여기도 에러발생 
	char* tmp = (char*)sName.c_str();
	int len = strlen(tmp) + 1;
	Person::name = new char[len];
	strcpy_s(Person::name, len, tmp);

	money = sMoney;
	numOfApple = sNum;
	price = sPrice;

}