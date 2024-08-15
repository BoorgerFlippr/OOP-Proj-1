/* Citation and Sources...
Final Project Milestone ms1
Module: Date
Filename: Date.h
Version 1.0
Author	Glenn Parreno 115814196
Revision History
-----------------------------------------------------------
Date      Reason
2020/03/11  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include "Status.h"

using namespace std;
namespace sdds
{
	const int MAX_YEAR = 2030;

	class Date
	{
		int dYear;
		int dMonth;
		int dDay;
		sdds::Status dState;
		bool dFormat = false;
		//private methods
		bool validate();
		int dateValue(int, int, int);
	public:
		//constructors
		Date();
		Date(int, int, int);
		//overload comparison operators
		bool operator==(Date&);
		bool operator!=(Date&);
		bool operator<(Date&);
		bool operator>(Date&);
		bool operator<=(Date&);
		bool operator>=(Date&);
		//getter
		const Status& state();
		//setter
		Date& formatted(bool);
		//bool conversion
		operator bool() const;
		//read write
		ostream& write(ostream&)const;
		istream& read(istream&);
	};
	ostream& operator<<(ostream&, const Date&);
	istream& operator>>(istream&, Date&);
	//bool operator==(Date&, Date&);
}
#endif // !SDDS_DATE_H
