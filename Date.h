#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>

class Date
{
    friend std::istream &operator>>(std::istream &, Date &);

public:
    Date(unsigned int = 1970, unsigned int = 1, unsigned int = 1);
    Date(const Date &);
    Date(int);

    static const std::string monthName[13];
    static const unsigned int daysPerMonth[13];

    void setYear(unsigned int);
    unsigned int getYear() const;
    void setMonth(unsigned int);
    unsigned int getMonth() const;
    void setDay(unsigned int);
    unsigned int getDay() const;
    static bool leap(unsigned int);
    bool endOfMonth(unsigned int);

    Date &operator++();
    Date operator++(int);
    Date &operator+=(unsigned int);
    void print() const;

    explicit operator int() const;
    // operator std::string() const;
    operator const char *() const;
    std::string to_str() const;
    void operator()(int = 1900, int = 1, int = 1);

    ~Date();

private:
    unsigned int year;
    unsigned int month;
    unsigned int day;

    void increament();

    bool checkDay(unsigned int) const;
};

#endif // DATE_H_INCLUDED
