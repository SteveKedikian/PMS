#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>

namespace skt {

class Task 
{
public:
    Task();
    Task(const std::string&, const std::string&);

    void info();
    void set_title(const std::string&);
    void set_desc(const std::string&);
    std::string get_title();
    std::string get_desc();

private:
    std::string m_title;
    std::string m_desc;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

} // skt

#endif