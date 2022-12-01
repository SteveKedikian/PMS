#include "task.h"

skt::Task::Task() : 
    m_title{}, m_desc{}  
{}

skt::Task::Task(const std::string& title, const std::string& desc) : 
    m_title{title}, m_desc{desc} 
{}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

void skt::Task::info() {
    std::cout << m_title << "_ /-/\n";
    std::cout << m_desc << "_ /-/" << std::endl;
}

void skt::Task::set_title(const std::string& title) {
    m_title = title;
}

void skt::Task::set_desc(const std::string& desc) {
    m_desc = desc;
}

std::string skt::Task::get_title() {
    return m_title;
}

std::string skt::Task::get_desc() {
    return m_desc;
}
