#include "user.h"

skt::User::User() :
    m_name{}, m_age{}
{}

skt::User::User(const std::string& name, const int age) :
    m_name{name}, m_age{age} 
{}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

void skt::User::info() {
    std::cout << m_name << "_ : " << m_age << "_" << std::endl;
}

void skt::User::set_name(const std::string& name) {
    m_name = name;
}

void skt::User::set_age(const int age) {
    m_age = age;
}

std::string skt::User::get_name() {
    return m_name;
}

int skt::User::get_age() {
    return m_age;
}