/*Final Project Milestone ms5
Module: Menu
Filename: Menu.cpp
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
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	Menu::Menu()
	{
		mNumOptions = 0;
		mOptions = nullptr;
	}

	Menu::Menu(unsigned int numOptions, const char* options)
	{
		if (!(numOptions > MAX_OPTIONS) || options != nullptr)
		{
			ut.alocpy(mOptions, options);
			mNumOptions = numOptions;
		}
	}

	Menu::~Menu()
	{
		delete[] mOptions;
		mOptions = nullptr;
	}

	void Menu::setMenu(unsigned int numOptions, const char* options)
	{
		if (!(numOptions > MAX_OPTIONS) || options != nullptr)
		{
			ut.alocpy(mOptions, options);
			mNumOptions = numOptions;
		}
	}

	unsigned int Menu::run() const
	{
		unsigned int select;
		cout << mOptions << "0- Exit\n" << "> ";
		select = ut.getint(0, mNumOptions, nullptr, nullptr);

		return select;
	}
}