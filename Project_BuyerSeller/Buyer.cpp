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
		std::cout << "�ܾ� ����\n";
	}
	else
	{
		std::cout << "Buyer�� ��� " << num << "���� �����մϴ�\n";
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
	std::cout << "----- Buyer ���� -----\n";
	std::cout << "��� ��ȣ : " << getSerial() << std::endl;
	std::cout << "�̸� : ";
	showName();
	std::cout << "���� �ܾ� : " << getMoney() << " ��" << std::endl;
	std::cout << "��� ���� : " << getNumOfApple() << " ��" << std::endl;
	std::cout << "----------------------\n";
	std::cout << "\n";
}

int Buyer::getSerial()
{
	return serial;
}

