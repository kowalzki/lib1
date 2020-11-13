#include <string.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "ScientificLibrary.h"

std::string generateRandString(int lgh = 0);
ScientificBook generateBook();
ScientificLibraryHall generateHall(int count = -1);
ScientificLibrary generateLibrary(int hallsNum = -1);

int main() {
	srand(time(NULL));

	ScientificLibrary libka = generateLibrary();
	libka.print();



	system("pause");
	return 0;
}

std::string generateRandString(int len = 0)
{
	std::string t = "";
	if (!len)
	{
		len = rand() % 5 + 3;
	}
	for (int i = 0; i < len; i++)
	{
		t += char(rand() % 26 + 97);
	}
	return t;
}
ScientificBook generateBook()
{
	ScientificBook t;
	t.set_author(generateRandString());
	t.set_name(generateRandString());
	t.set_cost(rand() % 100 + (rand() % 100 * 1. / 100));
	t.set_yearPost(1900 + rand() % 121);
	t.set_rating(rand() % 100 * 1. / 100);
	return t;
}
ScientificLibraryHall generateHall(int count = -1)
{
	if (count == -1)
	{
		count = rand() % 5 + 5;
	}
	ScientificLibraryHall t;
	t.setHName(generateRandString());
	for (int i = 0; i < count; i++)
	{
		t.addBk(generateBook());
	}
	return t;
}
ScientificLibrary generateLibrary(int hallsNum = -1)
{
	if (hallsNum == -1)
	{
		hallsNum = rand() % 5 + 5;
	}
	ScientificLibrary t;
	ScientificLibraryHall hall;
	for (int i = 0; i < hallsNum; i++)
	{
		hall = generateHall();
		t.add(hall);
	}
	return t;
}