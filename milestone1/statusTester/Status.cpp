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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
#include "Status.h"
using namespace std;
namespace sdds
{

	Status::Status()
	{
		sDesc = nullptr;
		sCode = 0;
	}

	Status::Status(const char* desc)
	{
		ut.alocpy(sDesc, desc);
		sCode = 0;
	}

	Status::Status(const Status& st)
	{
		ut.alocpy(sDesc, st.sDesc);
		sCode = st.sCode;
	}

	Status& Status::operator=(const Status& st)
	{
		if (this != &st)
		{
			ut.alocpy(sDesc, st.sDesc);
			sCode = st.sCode;
		}

		return *this;
	}

	Status::~Status()
	{
		delete[] sDesc;
		sDesc = nullptr;
	}

	Status& Status::operator=(const char* desc)
	{
		ut.alocpy(sDesc, desc);

		return *this;
	}

	Status& Status::operator=(int code)
	{
		sCode = code;

		return *this;
	}

	Status::operator int() const
	{
		return sCode;
	}

	Status::operator const char* () const
	{
		return sDesc;
	}

	Status::operator bool() const
	{
		bool toReturn = true;

		if (sDesc != nullptr)
			toReturn = false;

		return toReturn;
	}

	Status& Status::clear()
	{
		delete[] sDesc;
		sDesc = nullptr;
		sCode = 0;

		return *this;
	}

	ostream& operator<<(ostream& os, const Status& st)
	{
		if (bool(st) == false)
		{
			if (int(st) == 0)
			{
				os << (const char*)(st);
			}
			else
			{
				os << "ERR#" << int(st) << ": " << (const char*)(st);
			}
		}

		return os;
	}


}