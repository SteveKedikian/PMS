#include "date.h"

skt::Date::Date(const Date& date) :
    m_day{date.m_day}, m_month{date.m_month}, m_year{date.m_year} 
{}
    
skt::Date::Date(const int day, const int month, const int year) : 
    m_day{day}, m_month{month}, m_year{year} 
{}

skt::Date::Date(const std::string& date) :
    m_day{std::stoi(date.substr(0, 2))},
    m_month{std::stoi(date.substr(3, 2))},
    m_year{std::stoi(date.substr(6, date.length() - 6))} 
{}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

skt::Date& skt::Date::operator=(const Date& date) {
    m_day = date.m_day;
    m_month = date.m_month;
    m_year = date.m_year;
    return *this;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

void skt::Date::info() {
    std::cout << m_day << "/" << m_month << "/" << m_year << "_" << std::endl; 
}

void  skt::Date::set_day(const int day) {
    m_day = day;
}

void  skt::Date::set_month(const int month) {
    m_month = month;
}

void  skt::Date::set_year(const int year) {
    m_year = year;
}

int skt::Date::get_day() {
    return m_day;
}

int skt::Date::get_month() {
    return m_month;
}

int skt::Date::get_year() {
    return m_year;
}