/*Final Project Milestone ms3
Module: iProduct
Filename: iProduct.cpp
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

#include"iProduct.h"

using namespace std;
namespace sdds
{
	ostream& operator<<(ostream& ostr, const iProduct& ip)
	{
		ip.display(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, iProduct& ip)
	{
		ip.read(istr);
		return istr;
	}
}