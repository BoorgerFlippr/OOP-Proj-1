/*Final Project Milestone ms5
Module: AidMan
Filename: AidMan.h
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
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
#include "iProduct.h"
#include "Item.h"
#include "Perishable.h"
const int sdds_max_num_items = 100;
using namespace std;
namespace sdds
{
	class AidMan
	{
		char* aFileName = nullptr;
		sdds::Menu aMenu;
		iProduct* iProdArr[sdds_max_num_items];
		int numItems = 0;
		int menu() const;
		//ms5.1 stuff
		void save();
		void deallocate();
		void load();
		int list(const char* sub_desc = nullptr);
		int search(int) const;
		void remove(int);
	public:
		AidMan();
		~AidMan();
		void run();
	};
}
#endif // !SDDS_AIDMAN_H
