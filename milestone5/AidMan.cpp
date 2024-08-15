/*Final Project Milestone ms5
Module: AidMan
Filename: AidMan.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "AidMan.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
	int AidMan::menu() const
	{
		cout << "Aid Management System" << endl;
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
		deallocate();
	}

	void AidMan::run()
	{
		int select = 0;

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
			{
				int prompt, option;
				char c;
				cout << "\n****List Items****\n";
				prompt = list();
				if (prompt > 0)
				{
					cout << "Enter row number to display details or <ENTER> to continue:\n> ";
					cin.ignore();
					c = cin.peek();
					if (c != '\n')
					{
						option = ut.getint(1, prompt, nullptr, nullptr);
						iProdArr[option - 1]->linear(false);
						iProdArr[option - 1]->display(cout);
						cout << '\n';

					}
					cout << '\n';

				}
				else
				{
					cout << "The list is empty!" << endl;
				}
			}

			else if (select == 2)
			{
				if (numItems > sdds_max_num_items)
				{
					cout << "Database full!";
				}
				else
				{
					int opt;
					cout << "\n****Add Item****\n";
					cout << "1- Perishable\n2- Non-Perishable" << endl;
					cout << "-----------------\n0- Exit\n> ";
					cin >> opt;
					if (opt == 1)
					{
						int tempSku;
						iProdArr[numItems] = new Perishable;
						tempSku = iProdArr[numItems]->readSku(cin);

						if (search(tempSku) == -1)
						{
							iProdArr[numItems]->read(cin);
							if (iProdArr[numItems])
							{
								numItems++;
							}
							cout << '\n';
						}
						else
						{
							delete iProdArr[numItems];
							cout << "Sku: " << tempSku << " is already in the system, try updating quantity instead.\n" << endl;
						}
					}
					else if (opt == 2)
					{
						int tempSku;
						iProdArr[numItems] = new Item;
						tempSku = iProdArr[numItems]->readSku(cin);

						if (search(tempSku) == -1)
						{
							iProdArr[numItems]->read(cin);
							if (iProdArr[numItems])
							{
								numItems++;
							}
							cout << '\n';
						}
						else
						{
							delete iProdArr[numItems];
							cout << "Sku: " << tempSku << " is already in the system, try updating quantity instead.\n" << endl;
						}
					}
					else
					{
						cout << "Aborted\n";
					}
				}
			}

			else if (select == 3)
			{
				char desc[20];
				int tempSku, index, opt;
				cout << "\n****Remove Item****\n";
				cout << "Item description: ";
				cin >> desc;
				cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
				cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
				for (int i = 0; i < numItems; i++)
				{
					if (iProdArr[i]->operator==(desc) == true)
					{
						cout << "   " << i + 1 << " | ";
						iProdArr[i]->linear(true);
						iProdArr[i]->display(cout);
						cout << "\n";
					}
				}
				cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
				cout << "Enter SKU: ";
				tempSku = ut.getint(10000, 99999, nullptr, nullptr);
				index = search(tempSku);
				if (index > -1)
				{
					cout << "Following item will be removed: " << endl;
					iProdArr[index]->linear(false);
					iProdArr[index]->display(cout);
					cout << '\n';
					cout << "Are you sure?\n1- Yes!\n0- Exit\n> ";
					cin >> opt;
					if (opt == 1)
					{
						remove(index);
						cout << "Item removed!" << endl;
					}
					else
					{
						cout << "Aborted!" << endl;
					}
				}
				else
				{
					cout << "SKU not found\n";
				}
				cout << endl;
			}

			else if (select == 4)
			{
				char desc[20];
				int tempSku, index, opt, addSub = 0;
				cout << "\n****Update Quantity****\n";
				cout << "Item description: ";
				cin >> desc;
				cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
				cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
				for (int i = 0; i < numItems; i++)
				{
					if (iProdArr[i]->operator==(desc) == true)
					{
						cout << "   " << i + 1 << " | ";
						iProdArr[i]->linear(true);
						iProdArr[i]->display(cout);
						cout << "\n";
					}
				}
				cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
				cout << "Enter SKU: ";
				tempSku = ut.getint(10000, 99999, nullptr, nullptr);
				index = search(tempSku);
				if (index != -1)
				{
					cout << "1- Add\n2- Reduce\n0- Exit\n> ";
					cin >> opt;
					if (opt == 1)
					{
						if (iProdArr[index]->qty() == iProdArr[index]->qtyNeeded())
						{
							cout << "Quantity Needed already fulfilled!\n";
						}
						else
						{
							cout << "Quantity to add: ";
							addSub = ut.getint(1, iProdArr[index]->qtyNeeded(), nullptr, nullptr);
							iProdArr[index]->operator+=(addSub);
							cout << addSub << " items added!\n";
						}
					}
					else if (opt == 2)
					{
						if (iProdArr[index]->qty() == 0)
						{
							cout << "Quantity on hand is zero!\n";
						}
						else
						{
							cout << "Quantity to reduce: ";
							addSub = ut.getint(1, iProdArr[index]->qtyNeeded(), nullptr, nullptr);
							iProdArr[index]->operator-=(addSub);
							cout << addSub << " items removed!\n";
						}
					}
					else
					{
						cout << "Aborted!\n";
					}
				}
				else
				{
					cout << "SKU not found!\n";
				}
				cout << endl;
			}

			else if (select == 5)
			{
				int i, j;
				iProduct* temp;
				cout << "\n****Sort****\n";

				for (i = 0; i < numItems; i++)
				{
					for (j = i + 1; j < numItems; j++)
					{
						int left = iProdArr[i]->qtyNeeded() - iProdArr[i]->qty();
						int right = iProdArr[j]->qtyNeeded() - iProdArr[j]->qty();
						if (left < right)
						{
							temp = iProdArr[i];
							iProdArr[i] = iProdArr[j];
							iProdArr[j] = temp;
						}

					}
				}

				cout << "Sort completed!\n" << endl;
			}

			else if (select == 6)
			{
				cout << "\n****Ship Items****\n";
				int shipped = 0;
				ofstream file("shippingOrder.txt");
				file << "Shipping Order, Date: ";
				file << sdds::sdds_testYear << "/";
				file << setfill('0') << setw(2) << sdds::sdds_testMon << "/";
				file << setfill('0') << setw(2) << sdds::sdds_testDay << endl;
				file << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
				file << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
				for (int i = 0; i < numItems; i++)
				{
					if (iProdArr[i]->qty() == iProdArr[i]->qtyNeeded())
					{
						shipped++;
						if(i == 3)
							file << "   " << i << " | ";
						else
							file << "   " << i + 1 << " | ";
						iProdArr[i]->linear(true);
						iProdArr[i]->display(file);
						file << "\n";
						remove(i);
					}
				}
				file << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
				cout << "Shipping Order for " << shipped << " times saved!\n" << endl;
			}

			else if (select == 7)
			{
				cout << "\n****New/Open Aid Database****\n";
				load();
			}

			else if (select == 0)
			{
				cout << "Exiting Program!\n";
				save();
			}
		} while (select != 0);
	}

	void AidMan::save()
	{
		if (aFileName != nullptr)
		{
			ofstream file(aFileName);
			for (int i = 0; i < numItems; i++)
			{
				iProdArr[i]->save(file);
				file << '\n';
			}
		}
	}

	void AidMan::deallocate()
	{
		for (int i = 0; i < numItems; i++)
		{
			delete iProdArr[i];
		}

		delete[] aFileName;
		aFileName = nullptr;
		numItems = 0;
	}

	void AidMan::load()
	{
		char fName[20];
		save();
		deallocate();

		cout << "Enter file name: ";
		cin >> fName;
		ut.alocpy(aFileName, fName);

		ifstream file(aFileName);

		if (file.is_open() == false)
		{
			int input;
			cout << "Failed to open " << aFileName << " for reading!" << endl;
			cout << "Would you like to create a new data file?\n1- Yes!\n0- Exit\n> ";
			cin >> input;
			if (input == 1)
			{
				ofstream newFile(aFileName);
				newFile.close();
				cout << "new data file: " << aFileName << endl;
			}
			else
			{
				aFileName = nullptr;
			}
		}
		else
		{
			char ch;
			int i = 0;
			while (file.good())
			{
				ch = file.peek();
				if (ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') //(int)ch >= 4 && (int)ch <= '9'
				{
					iProdArr[i] = new Item;
					iProdArr[i]->load(file);
					if (iProdArr[i])
					{
						numItems++;
						file.ignore(1000, '\n');
					}
				}
				else if (ch == '1' || ch == '2' || ch == '3') //(int)ch >='1' && (int)ch <= '3'
				{
					iProdArr[i] = new Perishable;
					iProdArr[i]->load(file);
					if (iProdArr[i])
					{
						numItems++;
					}
					
				}
				i++;
				//file.ignore(1000, '\n');
			}
			cout << numItems << " records loaded!\n" << endl;
		}
	}

	int AidMan::list(const char* sub_desc)
	{
		if (sub_desc == nullptr)
		{
			cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			for (int i = 0; i < numItems; i++)
			{
				cout << "   " << i + 1 << " | ";
				iProdArr[i]->linear(true);
				iProdArr[i]->display(cout);
				cout << "\n";
			}
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		}

		return numItems;
	}

	int AidMan::search(int toSearch) const
	{
		int i = -1, j;

		for (j = 0; j < numItems; j++)
		{
			if (iProdArr[j]->operator==(toSearch) == true)
			{
				i = j;
				break;
			}
		}

		return i;
	}

	void AidMan::remove(int index)
	{
		delete iProdArr[index];

		for (int i = index; i < numItems; ++i)
		{
			iProdArr[i] = iProdArr[i + 1];
		}

		numItems--;
	}
}