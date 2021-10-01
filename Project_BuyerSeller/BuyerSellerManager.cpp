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
		std::cout << "�޴��� �������ּ���\n";
		std::cout << "1. List ���� \n";
		std::cout << "2. Buyer,Seller �߰�/���� \n";
		std::cout << "3. Buyer,Seller �˻��ϱ�\n";
		std::cout << "4. Buyer,Seller �����ϱ�\n";
		std::cout << "5. ����/�Ǹ� �����ϱ� \n";
		std::cout << "6. ����\n";
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
			std::cout << "���ڿ��� �Է��Ͽ����ϴ�. 1~4 ���� �Է����ּ���.\n";
			continue;
		}
		switch (output)
		{
		case 1:
			std::cout << "1�� �����߽��ϴ�.\n";
			showInfo(buyerVector, sellerVector);
			std::cout << "\n";
			break;
		case 2:
			std::cout << "2�� �����߽��ϴ�.\n";
			addAndRemove(buyerVector, sellerVector);
			std::cout << "\n";
			break;
		case 3:
			std::cout << "3�� �����߽��ϴ�.\n";
			find(buyerVector, sellerVector);
			break;
		case 4:
			std::cout << "4�� �����߽��ϴ�.\n";
			change(buyerVector, sellerVector);
			break;
		case 5:
			std::cout << "5�� �����߽��ϴ�.\n";
			start(buyerVector, sellerVector);
			break;
		case 6:
			std::cout << "6�� �����߽��ϴ�.\n";
			goto end;
		default:
			std::cout << "�߸� �Է��Ͽ����ϴ� 1~6 �� ���Է��ϼ���.\n";
			break;
		}

	}
end:
	std::cout << "����Ǿ����ϴ�\n";
}
