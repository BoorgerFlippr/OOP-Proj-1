/*Final Project Milestone ms4
Module: Perishable
Filename: Perishable.h
Version 1.0
Author	Glenn Parreno 115814196
Revision History
-----------------------------------------------------------
Date      Reason
2020/04/02  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Perishable.h"
#include "Utils.h"
#include<string>
#include<string.h>
#include<cstring>
#include<iomanip>

using namespace std;
namespace sdds
{
	Perishable::Perishable()
	{
		//Item::Item();
		m_handling = nullptr;
	}

	Perishable::Perishable(const Perishable& src)
	{
		*this = src;
	}

	Perishable& Perishable::operator=(const Perishable& src)
	{
		if (this != &src)
		{
			Item::operator=(src);
			ut.alocpy(m_handling, src.m_handling);
			m_expiry = src.m_expiry;
		}

		return *this;
	}

	Perishable::~Perishable()
	{
		delete[] m_handling;
		m_handling = nullptr;
	}

	const Date& Perishable::expiry() const
	{
		return this->m_expiry;
	}

	int Perishable::readSku(istream& istr)
	{
		cout << "SKU: ";
		m_sku = ut.getint(10000, 39999, nullptr, nullptr);

		return m_sku;
	}

	ofstream& Perishable::save(ofstream& ofstr) const
	{
		if ((bool)this)
		{
			Item::save(ofstr);
			ofstr << '\t';
			if (m_handling != nullptr)
			{
				ofstr << m_handling;
			}
			ofstr << '\t';
			Date copyDate(m_expiry);
			copyDate.formatted(false);
			ofstr << copyDate;

		}

		return ofstr;
	}

	ifstream& Perishable::load(ifstream& ifstr)
	{
		delete[] m_handling;
		m_handling = nullptr;
		string hand;
		string emp = "";
		Item::load(ifstr);
		ifstr.ignore();
		getline(ifstr, hand, '\t');
		if (hand.compare(emp) == 0)
		{
			m_handling = nullptr;
		}
		else
		{
			ut.alocpy(m_handling, hand.c_str());
		}
		//ut.alocpy(m_handling, hand.c_str());
		ifstr >> m_expiry;
		ifstr.ignore();

		if (ifstr.fail())
		{
			m_state = "Input file stream read (perishable) failed!";
		}

		return ifstr;
	}

	ostream& Perishable::display(ostream& ostr)const
	{
		if ((bool)this == false)
		{
			ostr << m_state;
		}
		else
		{

			if (linear())
			{
				Item::display(ostr);
				if (m_handling != nullptr)
				{
					ostr << '*' << m_expiry;
				}
				else
				{
					ostr << ' ' << m_expiry;
				}
			}
			else
			{
				ostr << "Perishable ";
				Item::display(ostr);
				ostr << "Expiry date: " << m_expiry << endl;
				if (m_handling != nullptr)
				{
					ostr << "Handling Instructions: " << m_handling << endl;
				}
			}
		}

		return ostr;
	}


	istream& Perishable::read(istream& istr)
	{
		Item::read(istr);
		delete[] m_handling;
		m_handling = nullptr;
		string hand;
		char c;

		cout << "Expiry date (YYMMDD): ";
		istr >> m_expiry;

		istr.ignore(1000, '\n');


		cout << "Handling Instructions, ENTER to skip: ";
		c = istr.peek();
		if (c == '\n')
		{
			m_handling = nullptr;
		}
		else
		{
			getline(istr, hand);
			ut.alocpy(m_handling, hand.c_str());
		}
		if (istr.fail())
			m_state = "Perishable console date entry failed!";

		return istr;
	}

}