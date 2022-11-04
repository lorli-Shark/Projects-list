#include "Work.h"
#include <cstdio>
#include <fstream>
#include <vector>

int getInput();
void updateInput(int& input, std::vector<Work>& list);

int main()
{
	int input;	
	std::vector<Work> list;

	while (true)
	{
		input = getInput();
		updateInput(input, list);
	}
	return 0;
}

int getInput()
{
	std::string input;

	printf(">> ");
	std::cin >> input;
	printf("\n");

	if (input == "1" || input == "Show list") return 1;
	if (input == "2" || input == "Add new member to list") return 2;
	if (input == "3" || input == "Remove member from the list") return 3;
	if (input == "4" || input == "Save") return 4;
	if (input == "5" || input == "Load") return 5;
	printf("Invalid command\n");
	printf("What would you like to do?\n"
			"1. Show list\n"
			"2. Add new member to list\n"
			"3. Remove member from the list\n"
			"4. Save\n"
	       		"5. Load\n");
	return -1;
}
void updateInput(int& input, std::vector<Work>& list)
{
	switch(input)
	{
	case 1:
		for (Work& i : list)
			std::cout << i.name << " " << i.level << " " <<  i.interesting << "\n";
		break;
	case 2:
		try
		{
			std::string name;
			int level, interesting;
			printf("Name level (interesting level)\n>> ");
			std::cin >> name >> level >> interesting;
			list.push_back(Work(name, level, interesting));
		}
		catch(...)
		{
			printf("looks like you inputed wrong input\n");
		} 
		break;
	case 3:
	{
		std::string name;
		std::cout << "Wich element (name)\n>> ";
		std::cin >> name;
		for (int i = 0; i < list.size(); i ++)
		{
			if (name == list[i].name)
				list.erase(list.begin() + i);
		}
	}
		break;
	case 4:
	{
		std::ofstream file;
		file.open("data.dat", std::ios::binary);
		for (Work& i : list)
		{
			file.write((char*)&i, sizeof(Work));
		}
	}
		break;
	case 5:
	try
	{
		std::ifstream file;
		file.open("data.dat", std::ios::binary);
		Work temp;
		for (Work& i : list)
		{
			file.read((char*)&temp, sizeof(Work));
			std::cout << i.name << " " << temp.name << "\n";
			i.name = temp.name;
		}
		for (Work& i : list)
			std::cout << i.name << "\n";
	}
	catch (...)
	{
		std::cout << "WHAT IS WRONG WITH YOU!?\n";
	}
		break;
	}
	printf("\n");
}
