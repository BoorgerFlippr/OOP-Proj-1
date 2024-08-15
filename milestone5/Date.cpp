/* Citation and Sources...
Final Project Milestone ms5
Module: Date
Filename: Date.cpp
Version 1.0
Author	Glenn Parreno 115814196
Revision History
-----------------------------------------------------------
Date      Reason
2020/04/05  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Utils.h"
#include "Date.h"
using namespace std;
namespace sdds
{
	bool Date::validate()
	{
		//bool toReturn;

		if (dYear > MAX_YEAR || dYear < 2022)
		{
			dState = "Invalid year in date";
			dState = 1;
			return false;
		}
		if (dMonth > 12 || dMonth < 1)
		{
			dState = "Invalid month in date";
			dState = 2;
			return false;
		}
		if (dDay > ut.daysOfMon(2, 2022) || dDay < 1)
		{
			dState = "Invalid day in date";
			dState = 3;
			return false;
		}

		dState.clear();

		return true;
	}

	int Date::dateValue(int year, int mon, int day)
	{
		int toReturn = year * 372 + mon * 31 + day;

		return toReturn;
	}

	Date::Date()
	{
		ut.getSystemDate(&dYear, &dMonth, &dDay);
	}

	Date::Date(int year, int mon, int day)
	{
		dYear = year;
		dMonth = mon;
		dDay = day;
	}

	Date::Date(const Date& dt)
	{
		dYear = (dt.dYear);
		dMonth = (dt.dMonth);
		dDay = (dt.dDay);
	}

	bool Date::operator==(Date& d)
	{
		int left, right;

		left = dateValue(this->dYear, this->dMonth, this->dDay);
		right = dateValue(d.dYear, d.dMonth, d.dDay);

		if (left == right)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator!=(Date& d)
	{
		int left, right;

		left = dateValue(this->dYear, this->dMonth, this->dDay);
		right = dateValue(d.dYear, d.dMonth, d.dDay);

		if (left != right)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator<(Date& d)
	{
		int left, right;

		left = dateValue(this->dYear, this->dMonth, this->dDay);
		right = dateValue(d.dYear, d.dMonth, d.dDay);

		if (left < right)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator>(Date& d)
	{
		int left, right;

		left = dateValue(this->dYear, this->dMonth, this->dDay);
		right = dateValue(d.dYear, d.dMonth, d.dDay);

		if (left > right)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator<=(Date& d)
	{
		int left, right;

		left = dateValue(this->dYear, this->dMonth, this->dDay);
		right = dateValue(d.dYear, d.dMonth, d.dDay);

		if (left <= right)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator>=(Date& d)
	{
		int left, right;

		left = dateValue(this->dYear, this->dMonth, this->dDay);
		right = dateValue(d.dYear, d.dMonth, d.dDay);

		if (left >= right)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	const Status& Date::state()
	{
		return this->dState;
	}

	Date& Date::formatted(bool format)
	{
		dFormat = format;
		return *this;
	}

	Date::operator bool() const
	{
		return dState.operator bool();
	}

	ostream& Date::write(ostream& os) const
	{
		if (dFormat == true)
		{
			os << dYear;
			os << "/";
			os << setfill('0') << setw(2) << dMonth;
			os << "/";
			os << setfill('0') << setw(2) << dDay;
		}
		else
		{
			os << dYear - 2000;
			os << setfill('0') << setw(2) << dMonth;
			os << setfill('0') << setw(2) << dDay;
		}

		return os;
	}

	istream& Date::read(istream& is)
	{
		int dt = 0;
		string date = "";
		stringstream ss;

		is >> dt;
		if (cin.fail())
		{
			cout << "Invalid date value";
		}
		ss << dt;
		ss >> date;

		if (date.length() == 4)
		{
			dYear = 2022;
			dMonth = stoi(date.substr(0, 2));
			dDay = stoi(date.substr(2, 4));
			if (validate() == false)
			{
				is.setstate(ios::badbit);
			}

		}
		else if (date.length() == 6)
		{
			dYear = (stoi(date.substr(0, 2)) + 2000);
			dMonth = stoi(date.substr(2, 2));
			dDay = stoi(date.substr(4, 6));
			if (validate() == false)
			{
				is.setstate(ios::badbit);
			}

		}
		else if (date.length() == 2)
		{
			dMonth = 13;
			if (validate() == false)
			{
				is.setstate(ios::badbit);
			}

		}
		return is;
	}

	ostream& operator<<(ostream& os, const Date& d)
	{
		return d.write(os);
	}

	istream& operator>>(istream& is, Date& d)
	{
		return d.read(is);
	}

}