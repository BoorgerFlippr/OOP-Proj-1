/*Final Project Milestone ms2
Module: AidMan
Filename: AidMan.h
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
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"

using namespace std;
namespace sdds
{
	class AidMan
	{
		char* aFileName = nullptr;
		sdds::Menu aMenu;
		int menu() const;
	public:
		AidMan();
		~AidMan();
		void run();
	};
}
#endif // !SDDS_AIDMAN_H
