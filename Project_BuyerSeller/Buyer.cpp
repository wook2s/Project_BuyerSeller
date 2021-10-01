#include <iostream>
#include "Seller.h"
#include "Buyer.h"
#include "Person.h"

class Person;
class Seller;

Buyer::Buyer(std::string name, int money, int apple) : Person(name, money, apple)
{
	serial = checkNum++;
}
Buyer::~Buyer()
{	}
void  Buyer::buy(Seller* s, int num)
{
	int price = s->getPrice();
	int totalPrice = num * price;
	if (totalPrice > getMoney())
	{
		std::cout << "잔액 부족\n";
	}
	else
	{
		std::cout << "Buyer가 사과 " << num << "개를 구입합니다\n";
		s->setNumOfApple(num);
		s->setMoney(totalPrice);
		this->setNumOfApple(num);
		this->setMoney(totalPrice);
		this->showData();
		s->showData();
	}
}
void  Buyer::showData()
{
	std::cout << "----- Buyer 정보 -----\n";
	std::cout << "등록 번호 : " << getSerial() << std::endl;
	std::cout << "이름 : ";
	showName();
	std::cout << "현재 잔액 : " << getMoney() << " 원" << std::endl;
	std::cout << "사과 갯수 : " << getNumOfApple() << " 개" << std::endl;
	std::cout << "----------------------\n";
	std::cout << "\n";
}

int Buyer::getSerial()
{
	return serial;
}

