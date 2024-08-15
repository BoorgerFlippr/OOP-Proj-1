/* Citation and Sources...
Final Project Milestone ms1
Module: Status
Filename: Status.h
Version 1.0
Author	Glenn Parreno
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

using namespace std;
namespace sdds
{
	class Status
	{
		char* sDesc = nullptr;
		int sCode = 0;
	public:
		//constructors
		Status();
		Status(const char*);
		//rule of 3
		Status(const Status&);
		Status& operator=(const Status&);
		~Status();
		//assignment overloads
		Status& operator=(const char*);
		Status& operator=(int);
		//type conversion operators
		operator int() const;
		operator const char* () const;
		operator bool() const;

		Status& clear();
	};

	ostream& operator<<(ostream&, const Status&);
}
#endif // !SDDS_STATUS_H


