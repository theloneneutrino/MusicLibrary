#include "..\headers\Song.h"

ostream& operator<<(ostream& os, const songLength& dt)
{
    if (dt.hours < 1)
    {
        os << setfill('0') 
            << setw(2) << dt.minutes << ":"
            << setw(2) << dt.seconds 
            << setfill(' ');
    }
    else
    {
        os << dt.hours << ":"
            << setfill('0') 
            << setw(2) << dt.minutes << ":"
            << setw(2) << dt.seconds 
            << setfill(' ');
    }
    return os;
}

istream& operator>>(istream& is, songLength& dt)
{
    cout << "hours: ";
    is >> dt.hours;
    cout << "minutes: ";
    is >> dt.minutes;
    cout << "seconds: ";
    is >> dt.seconds;
    return is;
}

ostream& operator<<(ostream& os, const Song& dt)
{
    os << "# " 
        << left << setw(4) << dt.trackNum
        << "length: " 
        << right << dt.length
        << ", name: " 
        << setw(dt.name.size() + 2) << dt.name;
    return os;
}

bool Song::operator<(Song& other)
{
    return this->length < other.length;
}

bool Song::operator<=(Song& other)
{
    return this->length <= other.length;
}

bool Song::operator>(Song& other)
{
    return this->length > other.length;
}

bool Song::operator>=(Song& other)
{
    return this->length >= other.length;
}

bool Song::operator==(Song& other) 
{
    return (this->length == other.length) && (this->name == other.name) && (this->trackNum == other.trackNum);
}

Song::Song() : trackNum(1), name("Jibble")
{}

Song::Song(string nm, int plce)
{
    name = nm;
    trackNum = plce;
}

songLength::songLength() : hours(0), minutes(0), seconds(0)
{}

bool songLength::operator<(songLength& other)
{
    bool value;
    if (hours != other.hours) // if hours are not the same
    {
        value = hours < other.hours; // whichever one has less hours
    }
    else if (minutes != other.minutes) // if minutes are not the same
    {
        value = minutes < other.minutes; // whichever one has less minutes
    }
    else // all else being the same...
    {
        value = seconds < other.seconds; // compare the seconds
    }
    return value;
}

bool songLength::operator==(songLength& other) // sees if all measurements of time are identical
{
    return (hours == other.hours)
        && (minutes == other.minutes)
        && (seconds == other.seconds);
}

bool songLength::operator>=(songLength& other)
{
    return !(*this < other);
}

bool songLength::operator>(songLength& other)
{
    return !((*this < other) && (*this == other));
}

bool songLength::operator<=(songLength& other)
{
    return !(*this > other);
}

