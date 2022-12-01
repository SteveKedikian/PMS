#include <string>

#include "project.h"
#include "date.h"

skt::Project::Project(const std::string& title, const skt::Date& date) :
    m_title{title}, m_date{date} 
{}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

void skt::Project::info() {
    std::cout << m_title << "_ /-/ ";
    m_date.info();
}

void skt::Project::set_title(const std::string& title) {
    m_title = title;
}

void skt::Project::set_date(const std::string& date) {
    m_date = Date(date);
}

std::string skt::Project::get_title() {
    return m_title;
}

std::string skt::Project::get_date() {
    std::string date;
    date += std::to_string(m_date.get_day()) + "/";
    date += std::to_string(m_date.get_month()) + "/";
    date += std::to_string(m_date.get_year());
    return date;
}