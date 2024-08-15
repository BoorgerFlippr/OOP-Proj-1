/*Final Project Milestone ms3
Module: iProduct
Filename: iProduct.h
Version 1.0
Author	Glenn Parreno 115814196
Revision History
-----------------------------------------------------------
Date      Reason
2020/03/25  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_IPRODUCT_H
#define SDDS_IPRODUCT_H
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
using namespace std;
namespace sdds
{
	class iProduct
	{
	public:
		virtual int readSku(istream&) = 0;
		virtual int operator-=(int) = 0;
		virtual int operator+=(int) = 0;
		virtual operator double()const = 0;
		virtual operator bool()const = 0;
		virtual int qtyNeeded()const = 0;
		virtual int qty()const = 0;
		virtual void linear(bool) = 0;
		virtual ofstream& save(ofstream&)const = 0;
		virtual ifstream& load(ifstream&) = 0;
		virtual ostream& display(ostream&)const = 0;
		virtual istream& read(istream&) = 0;
		virtual bool operator==(int)const = 0;
		virtual bool operator==(const char*)const = 0;
		virtual ~iProduct() {};
	};

	ostream& operator<<(ostream&, const iProduct&);
	istream& operator>>(istream&, iProduct&);
}
#endif // !SDDS_IPRODUCT_H
