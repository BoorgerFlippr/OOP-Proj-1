/*Final Project Milestone ms2
Module: AidMan
Filename: AidMan.cpp
Version 1.0
Author	Glenn Parreno 115814196
Revision History
-----------------------------------------------------------
Date      Reason
2020/03/15  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "AidMan.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
	int AidMan::menu() const
	{
		cout << "Aid Management System Version 0.1" << endl;
		//maybe change the line in the bottom to current year instead of test year :c
		cout << "Date: ";
		cout << sdds::sdds_testYear;
		cout << "/";
		cout << setfill('0') << setw(2) << sdds::sdds_testMon;
		cout << "/";
		cout << setfill('0') << setw(2) << sdds::sdds_testDay << endl;
		if (aFileName != nullptr)
			cout << "Data file: " << aFileName << endl;
		else
			cout << "Data file: No file" << endl;
		cout << "---------------------------------" << endl;

		return aMenu.run();
	}

	
	AidMan::AidMan()
	{
		aMenu.setMenu(7, "1- List Items\n"
						 "2- Add Item\n"
						 "3- Remove Item\n"
					     "4- Update Quantity\n"
						 "5- Sort\n"
						 "6- Ship Items\n"
						 "7- New/Open Aid Database\n"
                         "---------------------------------\n");
		aFileName = nullptr;
	}

	AidMan::~AidMan()
	{
		delete[] aFileName;
	}

	void AidMan::run()
	{
		int select = 0;

		aFileName = new char[20];
		strcpy(aFileName, "glenn.txt");

		do
		{
			select = menu();

			if (aFileName == nullptr)
			{
				if (select == 0)
				{
					select = 0;
				}
				else if (select != 7)
				{
					select = 7;
				}
			}

			if (select == 1)
				cout << "\n****List Items****\n\n";
			else if (select == 2)
				cout << "\n****Add Item****\n\n";
			else if (select == 3)
				cout << "\n****Remove Item****\n\n";
			else if (select == 4)
				cout << "\n****Update Quantity****\n\n";
			else if (select == 5)
				cout << "\n****Sort****\n\n";
			else if (select == 6)
				cout << "\n****Ship Items****\n\n";
			else if (select == 7)
				cout << "\n****New/Open Aid Database****\n\n";
			else if (select == 0)
				cout << "Exiting Program!\n";
		} while (select != 0);
	}
}

using namespace std;