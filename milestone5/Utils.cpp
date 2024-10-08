/*Final Project Milestone ms5
Module: Utils
Filename: Utils.cpp
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
#include <ctime>
#include <cstring>
#include <string.h>
#include "Utils.h"
using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    void Utils::alocpy(char*& destination, const char* source)
    {
        delete[] destination;
        destination = nullptr;

        if (source != nullptr)
        {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }
    int Utils::getint(const char* prompt = nullptr)
    {
        int i = 0;
        int input;

        if (prompt != nullptr)
            cout << prompt;

        do
        {
            cin >> input;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Integer, retry: ";
            }
            else
                i = 1;
        } while (i == 0);

        return input;
    }
    int Utils::getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr)
    {
        int i = 0;
        int input;

        if (prompt != nullptr)
            cout << prompt;

        do
        {
            cin >> input;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Integer, retry: ";
            }
            else if (input > max || input < min)
            {
                if (errMes != nullptr)
                    cout << errMes << ", retry: ";
                else
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
            }
            else
                i = 1;
        } while (i == 0);

        return input;
    }

    double Utils::getDouble(double min, double max)
    {
        int i = 0;
        double input;

        do
        {
            cin >> input;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid number, retry: ";
            }
            else if (input > max || input < min)
            {
                cout.precision(2);
                cout << "Value out of range [" << fixed << min << "<=val<=" << fixed << max << "]: ";
            }
            else
                i = 1;
        } while (i == 0);

        return input;
    }
}