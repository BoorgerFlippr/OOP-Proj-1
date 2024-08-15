/*Final Project Milestone ms5
Module: Menu
Filename: Menu.h
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

using namespace std;
namespace sdds
{
	const int MAX_OPTIONS = 15;
	class Menu
	{
		char* mOptions = nullptr;
		unsigned int mNumOptions = 0;
	public:
		Menu();
		Menu(unsigned int, const char*);
		~Menu();
		void setMenu(unsigned int, const char*);
		unsigned int run() const;
	};
}
#endif // !SDDS_MENU_H
