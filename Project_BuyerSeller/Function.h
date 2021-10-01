
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "Buyer.h"
#include "Seller.h"


void showInfo(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV);
void addAndRemove(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV);
void start(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV);
int checkNum(std::string& strNum);
void buyAndSell(std::vector<Buyer>& bv, int& bIdx, std::vector<Seller>& sv, int& sIdx, int& num);
void find(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV);
int inputNum();
void change(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV);
void changeBuyer(std::vector<Buyer>& buyerV);
void changeSeller(std::vector<Seller>& sellerV);

template <class T>
void deletePerson(std::vector<T>& v, int idx);
template <class T>
void showPerson(std::vector<T>& v);
template <class T>
int checkVectorSize(std::vector<T>& v, int idx);
template <class T>
int checkNumAndVectorSize(std::vector<T>& v);
template <class T>
void findByname(std::vector<T>& v);
template<class T>
int searchBySerial(std::vector<T>& v, int& serial);
template <class T>
void showBySerial(std::vector<T>& v);
template <class T>
void deleteBySerial(std::vector<T>& v);
template <class T>
void findByNameOrSerial(std::vector<T>& v);
template <class T>
int checkIdxBySerial(std::vector<T>& v, int serial);

void showInfo(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV)
{

	std::cout << "\n------Buyer/Seller ����� ����մϴ�.------\n\n";
	if (buyerV.size() == 0)
	{
		std::cout << "Buyer�� �����ϴ�. Buyer�� �߰����ּ���\n\n";
		goto re1;
	}
	std::cout << "Buyer ����Դϴ�\n";
	showPerson<Buyer>(buyerV);
re1:
	if (sellerV.size() == 0)
	{
		std::cout << "Seller�� �����ϴ�. Seller�� �߰����ּ���\n\n";
		goto re2;
	}
	std::cout << "Seller ����Դϴ�\n";
	showPerson<Seller>(sellerV);
re2:
	std::cout << "\n-------------------------------------------\n";
}

void addAndRemove(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV)
{
	while (true)
	{
		std::cout << "1. Buyer �߰�\n";
		std::cout << "2. Seller �߰�\n";
		std::cout << "3. Buyer ����\n";
		std::cout << "4. Seller ����\n";
		std::cout << "5. �ڷΰ���\n";
		std::cout << "\n";

		std::string tmp;
		std::cin >> tmp;
		int tmpNum = checkNum(tmp);
		if (tmpNum < 1 || tmpNum >5)
		{
			std::cout << "�߸��Է��߽��ϴ�. 1~5 �� �Է��ϼ���.\n";
			continue;
		}

		if (tmpNum == 1)
		{
			std::cout << "name�� �Է��ϼ��� > \n";
			std::string nameTmp;
			std::cin >> nameTmp;
			std::cout << "money(���� �ܾ�)�� �Է��ϼ��� > \n";
			int moneyTmp;
			std::cin >> moneyTmp;
			std::cout << "num(��� ����)�� �Է��ϼ��� > \n";
			int numTmp;
			std::cin >> numTmp;
			Buyer buyer(nameTmp, moneyTmp, numTmp);
			buyerV.push_back(buyer);
			std::cout << "buyer�� ���� ��ϵǾ����ϴ�.\n";
		}
		else if (tmpNum == 2)
		{
			std::cout << "name�� �Է��ϼ��� > \n";
			std::string nameTmp;
			std::cin >> nameTmp;
			std::cout << "money(���� �ܾ�)�� �Է��ϼ��� > \n";
			int moneyTmp;
			std::cin >> moneyTmp;
			std::cout << "num(��� ����)�� �Է��ϼ��� > \n";
			int numTmp;
			std::cin >> numTmp;
			std::cout << "price(��� ����)�� �Է��ϼ��� > \n";
			int priceTmp;
			std::cin >> priceTmp;

			Seller seller(nameTmp, moneyTmp, numTmp, priceTmp);
			sellerV.push_back(seller);
			std::cout << "seller�� ���� ��ϵǾ����ϴ�.\n";
		}
		else if (tmpNum == 3)
		{
			std::cout << "���� �� Buyer�� \n";
			int serial = inputNum();
			int idx = searchBySerial(buyerV, serial);
			deletePerson<Buyer>(buyerV, idx);
		}
		else if (tmpNum == 4)
		{
			std::cout << "���� �� Seller�� \n";
			int serial = inputNum();
			int idx = searchBySerial(sellerV, serial);
			deletePerson<Seller>(sellerV, idx);
		}
		else if (tmpNum == 5)
		{
			break;
		}
		else
			std::cout << "�߸� �Է��Ͽ����ϴ�.\n";
	}

}

void start(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV)
{

	if (buyerV.size() == 0 || sellerV.size() == 0)
	{
		std::cout << "Buyer�� Seller�� �� 1�� �̻� �ʿ��մϴ�.\n";
		std::cout << "List�� Ȯ���� �� Buyer/Seller�� �߰��ϼ���.\n";
		std::cout << "\n";
		return;
	}

	std::cout << "Buyer�� Seller�� �������ּ��� \n";

	std::cout << "Buyer��";
	int serialBuyer = inputNum();
	std::cout << "Seller��";
	int serialSeller = inputNum();

	int buyerIdx = searchBySerial<Buyer>(buyerV, serialBuyer);
	int sellerIdx = searchBySerial<Seller>(sellerV, serialSeller);
	if (buyerIdx == -1 || sellerIdx == -1)
	{
		std::cout << "��Ϲ�ȣ�� Ȯ�����ּ���.\n";
		return;
	}
	if (buyerIdx != -1 || sellerIdx != -1)
	{
		std::cout << "��Ϲ�ȣ " << serialBuyer << "�� Buyer�� \n";
		std::cout << "��Ϲ�ȣ " << serialSeller << "�� Seller�� ���õǾ����ϴ�.\n";
	}
re2:
	std::cout << "�����ϰ���� ��� ����(num)�� ������ �Է��ϼ��� \n";
	std::string appleNumStr;
	std::cin >> appleNumStr;
	if (checkNum(appleNumStr) == -1)
	{
		goto re2;
	}
	int appleNum = stoi(appleNumStr);//

	buyAndSell(buyerV, buyerIdx, sellerV, sellerIdx, appleNum);

}

template <class T>
void deletePerson(std::vector<T>& v, int idx)
{
	if (v.size() - 1 < idx || idx < 0)
	{
		std::cout << "List���� ��� ��ȣ�� ��Ȯ�� �ϼ���.\n";
		return;
	}
	else
	{
		typename std::vector<T>::iterator it = v.begin();
		v.erase(it + idx);
		std::cout << "���� �Ϸ� \n";
	}
}

template <class T>
void showPerson(std::vector<T>& v)
{
	for (T t : v)
	{
		t.showData();
	}
}

int checkNum(std::string& strNum)
{
	int num;
	try
	{
		num = stoi(strNum);
		return num;
	}
	catch (std::invalid_argument e)
	{
		return -1;
	}
}

template <class T>
int checkVectorSize(std::vector<T>& v, int idx)
{
	int vectorSize = v.size();
	if (v.size() - 1 < idx || idx < 0)
	{
		return -1;
	}
	return 1;
}

template <class T>
int checkNumAndVectorSize(std::vector<T>& v)
{
	std::string idxStr;
re1:
	std::cout << "���Ͻô�" << typeid(T).name() << "�� idx�� ������ �Է��ϼ��� \n";
	std::cin >> idxStr;
	if (checkNum(idxStr) == -1)
	{
		std::cout << "���ڸ� �Է��Ͽ����ϴ�\n";
		goto re1;
	}
	int idxNum = stoi(idxStr);
	if (checkVectorSize<T>(v, idxNum) == -1)
	{
		std::cout << "idx�� vector ������ ������ϴ�.\n";
		goto re1;
	}
	std::cout << typeid(T).name() << "�� idx�� ���õǾ����ϴ�.\n";
	return idxNum;
}

void buyAndSell(std::vector<Buyer>& bv, int& bIdx, std::vector<Seller>& sv, int& sIdx, int& num)
{
	Buyer& b = bv[bIdx];
	Seller& s = sv[sIdx];
	b.buy(&s, num);
}

void find(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV)
{
	while (true)
	{
	re:
		std::cout << "1. Buyer �˻�\n";
		std::cout << "2. Seller �˻�\n";
		std::cout << "3. �ڷΰ��� \n";
		std::string tmp;
		std::cin >> tmp;

		if (checkNum(tmp) > 3 || checkNum(tmp) < 1)
		{
			std::cout << "�߸� �Է��Ͽ����ϴ�. 1~3�� �Է��ϼ���\n";
			goto re;
		}
		if (checkNum(tmp) == 1)
		{
			findByNameOrSerial(buyerV);
		}
		else if (checkNum(tmp) == 2)
		{
			findByNameOrSerial(sellerV);
		}
		else if (checkNum(tmp) == 3)
			break;

	}

}


template <class T>
void findByname(std::vector<T>& v)
{
	std::string str;
	std::cout << "�˻��Ϸ��� �̸��� �Է��ϼ���.\n";
	std::cin >> str;
	std::cout << "---------�˻� ���----------\n";

	for (T t : v)
	{
		std::string tmp = t.getName();
		if (tmp.find(str) != std::string::npos)
		{
			t.showData();
		}
	}
	std::cout << "----------------------------\n";
}

int inputNum()
{
	std::string tmp;
	std::cout << "��� ��ȣ�� �Է��ϼ���\n";
	std::cin >> tmp;
	int serial = checkNum(tmp);
	return serial;
}

template<class T>
int searchBySerial(std::vector<T>& v, int& serial)
{
	if (v.size() == 0)
	{
		std::cout << "��ϵ� ����� �����ϴ�\n";
		return -1;
	}
	if (serial >= 0)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].getSerial() == serial)
			{
				return i;
			}
			return -1;
		}
	}
}

template <class T>
void showBySerial(std::vector<T>& v)
{
	int idx = -1;
	int serial = inputNum();
	if (serial != -1)
	{
		int idx = searchBySerial(v, serial);
		if (idx >= 0)
		{
			v[idx].showData();
		}
	}
	else if (serial == -1)
	{
		std::cout << "�߸� �Է��Ͽ����ϴ�.\n";
	}
}

template <class T>
void deleteBySerial(std::vector<T>& v)
{
	int idx = -1;
	int serial = inputNum();
	if (serial > 0)
	{
		int idx = searchBySerial(v, serial);
		deletePerson(v, serial);
	}
	else if (serial == -1)
	{
		std::cout << "�߸� �Է��Ͽ����ϴ�.\n";
	}
}

template <class T>
void findByNameOrSerial(std::vector<T>& v)
{
	std::cout << "1. �̸����� �˻�\n";
	std::cout << "2. ��� ��ȣ�� �˻�\n";
	std::cout << "3. �ڷΰ���\n";

	int num = inputNum();
	if (num < 1 || num >3)
	{
		std::cout << "�߸� �Է��Ͽ����ϴ�. 1~3 �� �Է��ϼ���.\n";
	}
	else if (num == 1)
	{
		findByname(v);
	}
	else if (num == 2)
	{
		showBySerial(v);
	}
	else if (num == 3)
	{
		return;
	}
}

template <class T>
int checkIdxBySerial(std::vector<T>& v, int serial)
{
	if (serial < 0)
	{
		std::cout << "�߸� �Է��߽��ϴ�,\n";
		return -1;
	}
	int idx = searchBySerial(v, serial);
	return idx;
}


void change(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV)
{
	std::cout << "1. Buyer ����\n";
	std::cout << "2. Seller ����\n";
	std::cout << "3. �ڷΰ���\n";
	std::string inputstr;
	std::cin >> inputstr;
	int input = checkNum(inputstr);

	if (input < 1 || input >3)
	{
		std::cout << "�߸� �Է��Ͽ����ϴ�. 1~3 �� �Է��ϼ���.\n";
		return;
	}
	if (input == 1)
	{
		changeBuyer(buyerV);
	}
	if (input == 2)
	{
		changeSeller(sellerV);
	}
	if (input == 3)
	{
		return;
	}
}


void changeBuyer(std::vector<Buyer>& buyerV)
{
	if (buyerV.size() == 0)
	{
		std::cout << "Buyer�� �����ϴ�. Buyer�� �߰����ּ���\n\n";
		return;
	}
	int serial = inputNum();
	int idx = checkIdxBySerial(buyerV, serial);
	if (idx < 0)
		return;
	std::string cName;
	int cMoney;
	int cNum;
	std::cout << "��Ϲ�ȣ " << serial << " �� ������ �����մϴ�.\n";
	std::cout << "������ name�� �Է��ϼ���\n";
	std::cin >> cName;
	std::cout << "������ money�� �Է��ϼ���\n";
	std::cin >> cMoney;
	std::cout << "������ num�� �Է��ϼ���\n";
	std::cin >> cNum;
	buyerV[idx].setPerson(cName, cMoney, cNum);
	std::cout << "����Ǿ����ϴ�.\n";
}

void changeSeller(std::vector<Seller>& sellerV)
{
	if (sellerV.size() == 0)
	{
		std::cout << "Seller�� �����ϴ�. Seller�� �߰����ּ���\n\n";
		return;
	}
	int serial = inputNum();
	int idx = checkIdxBySerial(sellerV, serial);
	if (idx < 0)
		return;
	std::string cName;
	int cMoney;
	int cNum;
	int cPrice;
	std::cout << "��Ϲ�ȣ " << serial << " �� ������ �����մϴ�.\n";
	std::cout << "������ name�� �Է��ϼ���\n";
	std::cin >> cName;
	std::cout << "������ money�� �Է��ϼ���\n";
	std::cin >> cMoney;
	std::cout << "������ num�� �Է��ϼ���\n";
	std::cin >> cNum;
	std::cout << "������ price�� �Է��ϼ���\n";
	std::cin >> cPrice;
	sellerV[idx].setPerson(cName, cMoney, cNum, cPrice);
	std::cout << "����Ǿ����ϴ�.\n";
}