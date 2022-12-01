#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

namespace skt {

class Date 
{
public:
    Date() = default;
    Date(const Date&);
    Date(const int, const int, const int);
    Date(const std::string&);

    Date& operator=(const Date&);

    void info();
    void set_day(const int);
    void set_month(const int);
    void set_year(const int);
    int get_day();
    int get_month();
    int get_year();

private:
    int m_day;
    int m_month;
    int m_year;
};

} // skt

#endif