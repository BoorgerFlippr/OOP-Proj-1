/*Final Project Milestone ms5
Module: Perishable
Filename: Perishable.h
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
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include "iProduct.h"
#include "Item.h"
#include "Date.h"
using namespace std;
namespace sdds
{
	class Perishable : public Item
	{
		sdds::Date m_expiry;
		char* m_handling = nullptr;

	public:
		Perishable();

		//rule of 3
		Perishable(const Perishable&);
		Perishable& operator=(const Perishable&);
		~Perishable();

		//query
		const Date& expiry() const;

		//virtual overrides
		int readSku(istream&);
		ofstream& save(ofstream&)const;
		ifstream& load(ifstream&);
		ostream& display(ostream&)const;
		istream& read(istream&);
	};
}

#endif // !SDDS_PERISHABLE_H
