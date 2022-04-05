#pragma once
#include "DynArray.h"
#include "DynQueue.h"
#include "Song.h"

class Menu
{
private:
	DynamicArray<Song*> library;

public:
	Menu();
	void displayOptions();
	void selectOption(int);

	template<typename T>
	T coutAndCin(const char*);

	void addSong();
	void removeSong();
	void print();
	void print(ostream&);
	void serialize(const char*);
	string stringifyFile(const char* filename);
	void mergeSort(int, int);
	void merge(const int, const int, const int);
	Song binSearch(Song obj);
	
	
};

