#ifndef PROJECT_H
#define PROJECT_H

#include <string>

#include "date.h"

namespace skt {

class Project 
{
public:
    Project() = default;
    Project(const std::string&, const Date&);

    void info();
    void set_title(const std::string&);
    void set_date(const std::string&);
    std::string get_title();
    std::string get_date();

private:
    std::string m_title;
    Date m_date;
};



} // skt

#endif