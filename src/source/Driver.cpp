#include "..\headers\DynArray.h"
#include "..\headers\Menu.h"
#include <iostream>
#include <vector>
#include <random>


int main() 
{

#ifdef _DEBUG
	cout << "Music Library: DEBUG Edition!" << endl;
#else
	cout << "Music Library version 1.0" << endl;
#endif // DEBUG

	Menu OneMenu;
	for (int i = 0; i < 10000; i++)
	{
		OneMenu.selectOption(4);
	}

	return 0;
}