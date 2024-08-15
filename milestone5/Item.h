/*Final Project Milestone ms3
Module: Item
Filename: Item.h
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

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include "Status.h"
#include "iProduct.h"
using namespace std;
namespace sdds
{
	class Item : public iProduct
	{
		double m_price = 0;
		int m_qty = 0;
		int m_qtyNeeded = 0;
		char* m_description = nullptr;
		bool m_linear = false;
	protected:
		sdds::Status m_state;
		int m_sku = 0;
		bool linear()const;
	public:
		Item();

		//rule of 3
		Item(const Item&);
		Item& operator=(const Item&);
		~Item();

		//virtual query iProduct overrides
		int qtyNeeded()const;
		int qty()const;
		operator double()const;
		operator bool()const;

		//virtual public modifier iProduct overrides
		int operator-=(int);
		int operator+=(int);
		void linear(bool);

		//public modifier
		Item& clear();

		//virtual operator== iProduct overrides
		bool operator==(int)const;
		bool operator==(const char*)const;

		//virtual Input/Output method iProduct overrides
		ofstream& save(ofstream&)const;
		ifstream& load(ifstream&);
		ostream& display(ostream&)const;
		int readSku(istream&);
		istream& read(istream&);

	};
}
#endif // !SDDS_ITEM_H
