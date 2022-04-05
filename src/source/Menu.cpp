#include "..\headers\Menu.h"



Menu::Menu()
{
	serialize("Library.csv");
}

void Menu::displayOptions()
{
	int selec;
	cout << endl << stringifyFile("fileOptions.txt");
	cin >> selec;
	selectOption(selec);
}

void Menu::selectOption(int selec)
{
	std::ofstream output;
	switch (selec)
	{
	case 1:
		addSong();
		break;

	case 2:
		removeSong();
		break;

	case 3:
		output.open("Library.csv");
		print(output);
		output.close();
		break;

	case 4:
		mergeSort(0, library.getSize() - 1);
		break;

	case 5:
		print();
		return;

	case 6:
		exit(EXIT_SUCCESS);
		return;

	default:
		cout << "That is not a valid option." << endl;
		break;
	}
}

template<typename T>
T Menu::coutAndCin(const char* question)
{
	T answer;
	cout << question << endl;
	cin >> answer;
	return answer;
}

void Menu::addSong()
{
	std::ifstream file;
	Song* tmpSong = new Song;
	tmpSong->name = coutAndCin<string>("What is the name of the song?");
	// tmpSong->length = coutAndCin<songLength>("What is the length of the song?");
	tmpSong->trackNum = coutAndCin<int>("What is the track number of the song?");
	int place = coutAndCin<int>("Where would you like to place this song?");

	library.add(tmpSong, place);
}

void Menu::removeSong()
{
	int place = coutAndCin<int>("Which song do you want to remove?");

	library.remove(place);
}

void Menu::print()
{
	for (int i = 0; i < library.getSize(); i++)
	{
		cout << *library.at(i) << endl;
	}
}

void Menu::print(ostream& out)
{
	for (int i = 0; i < library.getSize(); i++)
	{
		out << library.at(i)->name << "," 
			<< library.at(i)->trackNum << ","
			<< library.at(i)->length.hours << "," 
			<< library.at(i)->length.minutes << "," 
			<< library.at(i)->length.seconds << endl;
	}
}

void Menu::serialize(const char* filename)
{
	std::ifstream input;
	input.open(filename);
	library.clear();
	while (!input.eof())
	{
		Song* tmpSong = new Song;
		getline(input, tmpSong->name, ',');

		int tmpSongData;
		input >> tmpSongData;
		tmpSong->trackNum = tmpSongData;
		input.ignore();

		input >> tmpSongData;
		tmpSong->length.hours = tmpSongData;
		input.ignore();

		input >> tmpSongData;
		tmpSong->length.minutes = tmpSongData;
		input.ignore();

		input >> tmpSongData;
		tmpSong->length.seconds = tmpSongData;
		input.ignore();

		library.push_back(tmpSong);
	}
	input.close();
}


string Menu::stringifyFile(const char* filename)
{
	std::ifstream input;
	string tmp;
	string tmpFile;
	input.open(filename);
	while (!input.eof()) 
	{
		getline(input, tmp);
		tmpFile += tmp;
		tmpFile += '\n';
	}
	return tmpFile;
}


void Menu::mergeSort(int first, int last)
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		mergeSort(first, middle);
		mergeSort(middle + 1, last);

		merge(first, middle, last);
	}
}

void Menu::merge(const int first, const int middle, const int last)
{
	int mergedSize = last - first + 1; // last index - first index + 1
	int pos = 0; // position of mergedarray
	int lpos = 0;
	int rpos = 0;
	Dynque<Song*> mergedQueue;

	lpos = first;
	rpos = middle + 1;

	while ((lpos <= middle) && (rpos <= last)) 
	{
		if (library.at(lpos) <= library.at(rpos)) 
		{
			mergedQueue.enqueue(library.at(lpos));
			lpos++;
		}
		else
		{
			mergedQueue.enqueue(library.at(rpos));
			rpos++;
		}
		pos++;
	}

	while (lpos <= middle)
	{
		mergedQueue.enqueue(library.at(lpos));
		lpos++;
		pos++;
	}

	while (rpos <= last)
	{
		mergedQueue.enqueue(library.at(rpos));
		lpos++;
		pos++;
	}

	for (pos = 0; pos < mergedSize; pos++) 
	{
		library.at(first + pos) = mergedQueue.dequeue();
	}
}

Song Menu::binSearch(Song obj)
{
	int first = 0, middle, last = library.getSize();
	middle = (first + last) / 2;
	
	while (last >= first)
	{
		if (obj < *library.at(middle)) // if object is less than middle
		{
			last = middle - 1;
			middle = (first + last) / 2;
		}
		else if (obj > *library.at(middle)) // if obj is greater than middle
		{
			first = middle + 1;
			middle = (first + last) / 2;
		}
		else if (obj == *library.at(middle))
		{
			return obj;
		}
		else 
		{
			mergeSort(0, library.getSize() - 1);
			binSearch(obj);
		}
	}

	return Song();
}
