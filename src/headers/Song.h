#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#ifdef _IOSTREAM_
using std::ostream;
using std::istream;
using std::string;

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setfill;
using std::left;
using std::right;


struct songLength
{
	int hours, minutes, seconds;
	songLength();

	bool operator<(songLength&);
	friend ostream& operator<<(ostream& os, const songLength& dt);
	friend istream& operator>>(istream& is, const songLength& dt);
};

struct Song 
{
	int trackNum;
	songLength length;
	std::string name;

	friend ostream& operator<<(ostream& os, const Song& dt);
	bool operator<(Song&);
	bool operator>=(Song&);

	Song();
	Song(string, int);
};
#endif // IOSTREAM