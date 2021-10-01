
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

	std::cout << "\n------Buyer/Seller 목록을 출력합니다.------\n\n";
	if (buyerV.size() == 0)
	{
		std::cout << "Buyer가 없습니다. Buyer를 추가해주세요\n\n";
		goto re1;
	}
	std::cout << "Buyer 목록입니다\n";
	showPerson<Buyer>(buyerV);
re1:
	if (sellerV.size() == 0)
	{
		std::cout << "Seller가 없습니다. Seller를 추가해주세요\n\n";
		goto re2;
	}
	std::cout << "Seller 목록입니다\n";
	showPerson<Seller>(sellerV);
re2:
	std::cout << "\n-------------------------------------------\n";
}

void addAndRemove(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV)
{
	while (true)
	{
		std::cout << "1. Buyer 추가\n";
		std::cout << "2. Seller 추가\n";
		std::cout << "3. Buyer 삭제\n";
		std::cout << "4. Seller 삭제\n";
		std::cout << "5. 뒤로가기\n";
		std::cout << "\n";

		std::string tmp;
		std::cin >> tmp;
		int tmpNum = checkNum(tmp);
		if (tmpNum < 1 || tmpNum >5)
		{
			std::cout << "잘못입력했습니다. 1~5 를 입력하세요.\n";
			continue;
		}

		if (tmpNum == 1)
		{
			std::cout << "name을 입력하세요 > \n";
			std::string nameTmp;
			std::cin >> nameTmp;
			std::cout << "money(현재 잔액)을 입력하세요 > \n";
			int moneyTmp;
			std::cin >> moneyTmp;
			std::cout << "num(사과 갯수)을 입력하세요 > \n";
			int numTmp;
			std::cin >> numTmp;
			Buyer buyer(nameTmp, moneyTmp, numTmp);
			buyerV.push_back(buyer);
			std::cout << "buyer가 정상 등록되었습니다.\n";
		}
		else if (tmpNum == 2)
		{
			std::cout << "name을 입력하세요 > \n";
			std::string nameTmp;
			std::cin >> nameTmp;
			std::cout << "money(현재 잔액)를 입력하세요 > \n";
			int moneyTmp;
			std::cin >> moneyTmp;
			std::cout << "num(사과 개수)을 입력하세요 > \n";
			int numTmp;
			std::cin >> numTmp;
			std::cout << "price(사과 가격)를 입력하세요 > \n";
			int priceTmp;
			std::cin >> priceTmp;

			Seller seller(nameTmp, moneyTmp, numTmp, priceTmp);
			sellerV.push_back(seller);
			std::cout << "seller가 정상 등록되었습니다.\n";
		}
		else if (tmpNum == 3)
		{
			std::cout << "삭제 할 Buyer의 \n";
			int serial = inputNum();
			int idx = searchBySerial(buyerV, serial);
			deletePerson<Buyer>(buyerV, idx);
		}
		else if (tmpNum == 4)
		{
			std::cout << "삭제 할 Seller의 \n";
			int serial = inputNum();
			int idx = searchBySerial(sellerV, serial);
			deletePerson<Seller>(sellerV, idx);
		}
		else if (tmpNum == 5)
		{
			break;
		}
		else
			std::cout << "잘못 입력하였습니다.\n";
	}

}

void start(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV)
{

	if (buyerV.size() == 0 || sellerV.size() == 0)
	{
		std::cout << "Buyer와 Seller는 각 1개 이상 필요합니다.\n";
		std::cout << "List를 확인한 후 Buyer/Seller를 추가하세요.\n";
		std::cout << "\n";
		return;
	}

	std::cout << "Buyer와 Seller를 선택해주세요 \n";

	std::cout << "Buyer의";
	int serialBuyer = inputNum();
	std::cout << "Seller의";
	int serialSeller = inputNum();

	int buyerIdx = searchBySerial<Buyer>(buyerV, serialBuyer);
	int sellerIdx = searchBySerial<Seller>(sellerV, serialSeller);
	if (buyerIdx == -1 || sellerIdx == -1)
	{
		std::cout << "등록번호를 확인해주세요.\n";
		return;
	}
	if (buyerIdx != -1 || sellerIdx != -1)
	{
		std::cout << "등록번호 " << serialBuyer << "번 Buyer와 \n";
		std::cout << "등록번호 " << serialSeller << "번 Seller가 선택되었습니다.\n";
	}
re2:
	std::cout << "구매하고싶은 사과 갯수(num)을 정수로 입력하세요 \n";
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
		std::cout << "List에서 등록 번호를 재확인 하세요.\n";
		return;
	}
	else
	{
		typename std::vector<T>::iterator it = v.begin();
		v.erase(it + idx);
		std::cout << "삭제 완료 \n";
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
	std::cout << "원하시는" << typeid(T).name() << "의 idx를 정수로 입력하세요 \n";
	std::cin >> idxStr;
	if (checkNum(idxStr) == -1)
	{
		std::cout << "문자를 입력하였습니다\n";
		goto re1;
	}
	int idxNum = stoi(idxStr);
	if (checkVectorSize<T>(v, idxNum) == -1)
	{
		std::cout << "idx가 vector 범위를 벗어났습니다.\n";
		goto re1;
	}
	std::cout << typeid(T).name() << "의 idx가 선택되었습니다.\n";
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
		std::cout << "1. Buyer 검색\n";
		std::cout << "2. Seller 검색\n";
		std::cout << "3. 뒤로가기 \n";
		std::string tmp;
		std::cin >> tmp;

		if (checkNum(tmp) > 3 || checkNum(tmp) < 1)
		{
			std::cout << "잘못 입력하였습니다. 1~3을 입력하세요\n";
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
	std::cout << "검색하려는 이름을 입력하세요.\n";
	std::cin >> str;
	std::cout << "---------검색 결과----------\n";

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
	std::cout << "등록 번호를 입력하세요\n";
	std::cin >> tmp;
	int serial = checkNum(tmp);
	return serial;
}

template<class T>
int searchBySerial(std::vector<T>& v, int& serial)
{
	if (v.size() == 0)
	{
		std::cout << "등록된 사람이 없습니다\n";
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
		std::cout << "잘못 입력하였습니다.\n";
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
		std::cout << "잘못 입력하였습니다.\n";
	}
}

template <class T>
void findByNameOrSerial(std::vector<T>& v)
{
	std::cout << "1. 이름으로 검색\n";
	std::cout << "2. 등록 번호로 검색\n";
	std::cout << "3. 뒤로가기\n";

	int num = inputNum();
	if (num < 1 || num >3)
	{
		std::cout << "잘못 입력하였습니다. 1~3 중 입력하세요.\n";
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
		std::cout << "잘못 입력했습니다,\n";
		return -1;
	}
	int idx = searchBySerial(v, serial);
	return idx;
}


void change(std::vector<Buyer>& buyerV, std::vector<Seller>& sellerV)
{
	std::cout << "1. Buyer 수정\n";
	std::cout << "2. Seller 수정\n";
	std::cout << "3. 뒤로가기\n";
	std::string inputstr;
	std::cin >> inputstr;
	int input = checkNum(inputstr);

	if (input < 1 || input >3)
	{
		std::cout << "잘못 입력하였습니다. 1~3 중 입력하세요.\n";
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
		std::cout << "Buyer가 없습니다. Buyer를 추가해주세요\n\n";
		return;
	}
	int serial = inputNum();
	int idx = checkIdxBySerial(buyerV, serial);
	if (idx < 0)
		return;
	std::string cName;
	int cMoney;
	int cNum;
	std::cout << "등록번호 " << serial << " 의 정보를 수정합니다.\n";
	std::cout << "변경할 name을 입력하세요\n";
	std::cin >> cName;
	std::cout << "변경할 money를 입력하세요\n";
	std::cin >> cMoney;
	std::cout << "변경할 num을 입력하세요\n";
	std::cin >> cNum;
	buyerV[idx].setPerson(cName, cMoney, cNum);
	std::cout << "변경되었습니다.\n";
}

void changeSeller(std::vector<Seller>& sellerV)
{
	if (sellerV.size() == 0)
	{
		std::cout << "Seller가 없습니다. Seller를 추가해주세요\n\n";
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
	std::cout << "등록번호 " << serial << " 의 정보를 수정합니다.\n";
	std::cout << "변경할 name을 입력하세요\n";
	std::cin >> cName;
	std::cout << "변경할 money를 입력하세요\n";
	std::cin >> cMoney;
	std::cout << "변경할 num을 입력하세요\n";
	std::cin >> cNum;
	std::cout << "변경할 price를 입력하세요\n";
	std::cin >> cPrice;
	sellerV[idx].setPerson(cName, cMoney, cNum, cPrice);
	std::cout << "변경되었습니다.\n";
}