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
		print();
		break;

	case 6:
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
	tmpSong->length = coutAndCin<songLength>("What is the length of the song?");
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


void Menu::binSort()
{
	
}
