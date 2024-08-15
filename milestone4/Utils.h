/*Final Project Milestone ms1
Module: Utils
Filename: Utils.h
Version 1.0
Author	Glenn Parreno, 115814196
Revision History
-----------------------------------------------------------
Date      Reason
2020/03/11  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
    const int sdds_testYear = 2022;
    const int sdds_testMon = 03;
    const int sdds_testDay = 31;
    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);
        void alocpy(char*&, const char*);
        int getint(const char*);
        int getint(int, int, const char*, const char*);
        double getDouble(double, double);
    };
    extern Utils ut;
}

#endif
