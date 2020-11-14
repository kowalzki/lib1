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

	ScientificBook pbk = ScientificBook("PUchkin", "STIHI", 550, 1995, 85);
	libka.getHallInd(0).addBk(pbk, 2);
	std::cout << "Say hello to Pushkin's stihi\n"; libka.print();

	ScientificBook nbk = ScientificBook("ANOTHER", "CHANGED", 610, 1987, 67);
	libka.getHallInd(0).remakeBk(nbk, 2);
	std::cout << "Say bye to Pushkin. He's now CHANGED :(\n"; libka.print();

	libka.getHallInd(0).deleteInd(2);
	std::cout << "Say bye to CHANGED\n"; libka.print();

	ScientificLibraryHall nhl = generateHall();
	libka.remakeHl(nhl, 0);
	std::cout << "Say hello to new Hall\n"; libka.print();

	ScientificBook bb = libka.getBestBook();
	std::cout << "And the author of the Best Book is: " << bb.getAuthor()
		<< "\nwith the price of: " << bb.getPrice() << "\n \n";

	system("pause");
	return 0;
}

std::string generateRandString(int len)
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
	t.setAuthor(generateRandString());
	t.setName(generateRandString());
	t.setPrice(rand() % 100 + (rand() % 100 * 1. / 100));
	t.setYear(1900 + rand() % 121);
	t.setRating(rand() % 100);
	return t;
}
ScientificLibraryHall generateHall(int count)
{
	if (count == -1)
	{
		count = rand() % 3+3;
	}
	ScientificLibraryHall t;
	t.setHName(generateRandString());
	for (int i = 0; i < count; i++)
	{
		t.addBk(generateBook());
	}
	return t;
}
ScientificLibrary generateLibrary(int hallsNum)
{
	if (hallsNum == -1)
	{
		hallsNum = 4;// rand() % 5 + 5;
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