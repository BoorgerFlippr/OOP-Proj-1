/*Final Project Milestone ms3
Module: Item
Filename: Item.cpp
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

#include"Item.h"
#include"Utils.h"
#include<string>
#include<string.h>
#include<cstring>
#include<iomanip>
using namespace std;
namespace sdds
{
	Item::Item()
	{
		m_price = 0;
		m_qty = 0;
		m_qtyNeeded = 0;
		m_description = nullptr;
		m_linear = false;
		m_sku = 0;
		//m_state = "ds";
		
	}

	Item::Item(const Item& it)
	{
		m_price = it.m_price;
		m_qty = it.m_qty;
		m_qtyNeeded = it.m_qtyNeeded;
		ut.alocpy(m_description, it.m_description);
		m_linear = it.m_linear;
		m_sku = it.m_sku;
	}

	Item& Item::operator=(const Item& it)
	{
		if (this != &it)
		{
			m_price = it.m_price;
			m_qty = it.m_qty;
			m_qtyNeeded = it.m_qtyNeeded;
			ut.alocpy(m_description, it.m_description);
			m_linear = it.m_linear;
			m_sku = it.m_sku;
		}

		return *this;
	}

	Item::~Item()
	{
		delete[] m_description;
	}


	bool Item::linear() const
	{
		return m_linear;
	}

	/*bool Item::isEmpty() const
	{
		bool isEmpty = false;

		if (m_sku == 0)
			isEmpty = true;
		else if (m_description == nullptr)
			isEmpty = true;

		return isEmpty;
	}*/

	int Item::qtyNeeded() const
	{
		return m_qtyNeeded;
	}

	int Item::qty()const
	{
		return m_qty;
	}

	Item::operator double()const
	{
		return m_price;
	}

	Item::operator bool() const
	{
		bool ret = true;
		if (m_sku == 0)
		{
			ret = false;
		}

		return ret;
		//return m_state.operator bool();
		//return isEmpty();
	}

	int Item::operator-=(int qty)
	{
		m_qty -= qty;
		return m_qty;
	}

	int Item::operator+=(int qty)
	{
		m_qty += qty;
		return m_qty;
	}

	void Item::linear(bool isLinear)
	{
		m_linear = isLinear;
	}

	Item& Item::clear()
	{
		m_state.clear();
		return *this;
	}

	bool Item::operator==(int sku)const
	{
		bool toReturn = false;

		if (m_sku == sku)
			toReturn = true;

		return toReturn;
	}

	bool Item::operator==(const char* description)const
	{
		bool toReturn = false;

		char* pos = strstr(m_description, description);
		if (pos)
			toReturn = true;
		else
			toReturn = false;

		return toReturn;
	}

	ofstream& Item::save(ofstream& ofstr) const
	{
		if ((bool)this)
		{
			ofstr << '\n' << m_sku << '\t' << m_description << '\t' << m_qty << '\t' << m_qtyNeeded << '\t';
			ofstr.precision(2);
			ofstr << fixed << m_price;
		}

		return ofstr;
	}

	ifstream& Item::load(ifstream& ifstr)
	{
		string desc;
		//delete[] m_description;
		ifstr >> m_sku;
		ifstr.ignore();
		getline(ifstr, desc, '\t');
		ut.alocpy(m_description, desc.c_str());
		ifstr >> m_qty;
		ifstr.ignore();
		ifstr >> m_qtyNeeded;
		ifstr.ignore();
		ifstr >> m_price;

		if (ifstr.fail())
		{
			m_state = "Input file stream read failed!";
		}

		//cout << "sku " << m_sku <<"desc "<< m_description<< "qty " <<m_qty << "qtyn "<< m_qtyNeeded << "price "<< m_price << endl;

		return ifstr;
	}

	ostream& Item::display(ostream& ostr) const
	{
		if ((bool)this == false)
		{
			ostr << m_state;
		}
		else
		{
			if (linear())
			{
				ostr << m_sku << " | ";
				if (strlen(m_description) >= 35)
				{
					for (int i = 0; i < 35; i++)
					{
						cout << m_description[i];
					}
				}
				else if (strlen(m_description) < 35)
				{
					int len = strlen(m_description);
					//len -= 35;
					cout << m_description;
					for (int i = 0; i < (35 - len); i++)
					{
						cout << ' ';
					}
				}
				ostr << " | ";
				ostr.setf(ios::right);
				ostr << setfill(' ') << setw(4) << m_qty << " | ";
				ostr.setf(ios::right);
				ostr << setfill(' ') << setw(4) << m_qtyNeeded << " | ";
				ostr.setf(ios::right);
				ostr << setfill(' ') << setw(7) << m_price << " |";
				//ostr << m_sku << " | ";
			}
			else
			{
				double purchaseFund = 0;
				purchaseFund = m_price * ((double)m_qtyNeeded - (double)m_qty);
				ostr << "AMA Item:" << endl;
				ostr << m_sku << ": " << m_description << endl;
				ostr << "Quantity Needed: " << m_qtyNeeded << endl;
				ostr << "Quantity Available: " << m_qty << endl;
				ostr << "Unit Price: $" << m_price << endl;
				ostr.precision(2);
				ostr << "Needed Purchase Fund: $" << fixed << purchaseFund << endl;
			}
		}

		return ostr;
	}

	int Item::readSku(istream& istr)
	{

		cout << "SKU: ";
		m_sku = ut.getint(40000, 99999, nullptr, nullptr);

		return m_sku;
	}

	istream& Item::read(istream& istr)
	{
		string desc;
		//delete[] m_description;
		m_state.clear();

		cout << "AMA Item:" << endl;
		cout << "SKU: " << m_sku << endl;

		istr.clear();
		istr.ignore(1000, '\n');

		cout << "Description: ";
		getline(istr, desc);
		ut.alocpy(m_description, desc.c_str());

		cout << "Quantity Needed: ";
		m_qtyNeeded = ut.getint(1, 9999, nullptr, nullptr);

		cout << "Quantity On Hand: ";
		m_qty = ut.getint(0, m_qtyNeeded, nullptr, nullptr);

		cout << "Unit Price: $";
		m_price = ut.getDouble(0.0, 9999.0);

		if (istr.fail())
			m_state = "Console entry failed!";

		return istr;

	}

}