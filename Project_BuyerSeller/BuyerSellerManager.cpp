#include <iostream>
#include "Buyer.h"
#include "Seller.h"
#include "Person.h"
#include "Function.h"
#include <vector>
#include <string>
#include <cstring>
#include <typeinfo>

int Seller::checkNum = 0;
int Buyer::checkNum = 0;

void manager()
{
	std::vector<Buyer> buyerVector;
	std::vector<Seller> sellerVector;

	Seller::checkNum = 0;
	Buyer::checkNum = 0;

	while (true)
	{
		std::cout << "메뉴를 선택해주세요\n";
		std::cout << "1. List 보기 \n";
		std::cout << "2. Buyer,Seller 추가/제거 \n";
		std::cout << "3. Buyer,Seller 검색하기\n";
		std::cout << "4. Buyer,Seller 수정하기\n";
		std::cout << "5. 구매/판매 시작하기 \n";
		std::cout << "6. 종료\n";
		std::cout << "\n";

		std::string input;
		std::cin >> input;
		int output;
		try
		{
			output = stoi(input);
		}
		catch (std::invalid_argument e)
		{
			std::cout << "문자열을 입력하였습니다. 1~4 값을 입력해주세요.\n";
			continue;
		}
		switch (output)
		{
		case 1:
			std::cout << "1을 선택했습니다.\n";
			showInfo(buyerVector, sellerVector);
			std::cout << "\n";
			break;
		case 2:
			std::cout << "2를 선택했습니다.\n";
			addAndRemove(buyerVector, sellerVector);
			std::cout << "\n";
			break;
		case 3:
			std::cout << "3를 선택했습니다.\n";
			find(buyerVector, sellerVector);
			break;
		case 4:
			std::cout << "4를 선택했습니다.\n";
			change(buyerVector, sellerVector);
			break;
		case 5:
			std::cout << "5를 선택했습니다.\n";
			start(buyerVector, sellerVector);
			break;
		case 6:
			std::cout << "6를 선택했습니다.\n";
			goto end;
		default:
			std::cout << "잘못 입력하였습니다 1~6 중 재입력하세요.\n";
			break;
		}

	}
end:
	std::cout << "종료되었습니다\n";
}
