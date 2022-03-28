#include "..\headers\DynArray.h"
#include "..\headers\Menu.h"
#include <iostream>
#include <vector>
#include <random>


int main() 
{
	cout << "Test" << endl;
	Menu OneMenu;
	for (int i = 0; i < 10000; i++)
	{
		OneMenu.displayOptions();
	}

	return 0;
}