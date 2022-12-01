#ifndef USER_CPP
#define USER_CPP

#include <iostream>
#include <string>

namespace skt {

class User 
{
private:
    std::string m_name;
    int m_age;

public:
    User();
    User(const std::string&, const int);

    void info();
    void set_name(const std::string&);
    void set_age(const int);
    std::string get_name();
    int get_age();
};

} // skt

#endif