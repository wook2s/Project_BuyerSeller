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
	std::cout << "----- Seller ���� -----\n";
	std::cout << "��� ��ȣ : " << getSerial() << std::endl;
	std::cout << "�̸� : ";
	showName();
	std::cout << "���� �ܾ� : " << Seller::getMoney() << " ��" << std::endl;
	std::cout << "��� ���� : " << Seller::getNumOfApple() << " ��" << std::endl;
	std::cout << "��� ���� : " << price << " ��" << std::endl;
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
		std::cout << "��� ���� ����, �ǸźҰ� \n";
	}
	else
	{
		std::cout << "Seller �� " << num << "���� �Ǹ��մϴ� \n";
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
	std::cout << "Seller�� ��� ������ " << getPrice() << " ���� " << price << "���� �ٲߴϴ�\n";
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
	//delete[] name; // ���⵵ �����߻� 
	char* tmp = (char*)sName.c_str();
	int len = strlen(tmp) + 1;
	Person::name = new char[len];
	strcpy_s(Person::name, len, tmp);

	money = sMoney;
	numOfApple = sNum;
	price = sPrice;

}