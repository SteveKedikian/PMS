#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "project.h"
#include "task.h"
#include "user.h"
#include "date.h"

void check_projects_file() {
    std::ifstream fin;
    std::ofstream fout;

    fin.open("projects.txt");
    if (!fin.is_open()) {
        std::cout << "New file 'projects.txt' was created !\n";
        fout.open("projects.txt");
        fout << "0";
    }
    fin.close();
}

void check_tasks_file() {
    std::ifstream fin;
    std::ofstream fout;

    fin.open("tasks.txt");
    if (!fin.is_open()) {
        std::cout << "New file 'tasks.txt' was created !\n";
        fout.open("tasks.txt");
        fout << "0";
    }
    fin.close();
}

void check_users_file() {
    std::ifstream fin;
    std::ofstream fout;

    fin.open("users.txt");
    if (!fin.is_open()) {
        std::cout << "New file 'users.txt' was created !\n";
        fout.open("users.txt");
        fout << "0";
    }
    fin.close();
}

void fill_projects(std::vector<skt::Project>& projects) {
    std::ifstream fin;
    std::string token;
    std::string line = "";
    int i = 0; // index
    int count;

    check_projects_file();
    fin.open("projects.txt");

    fin >> token;
    if (token.compare("0") == 0) {
        return;
    }
    count = std::stoi(token); // First string shows how many projects
    
    projects.resize(count);
    while (!fin.eof()) {
        fin >> token;
        if (token.compare("/-/") == 0) {
            projects[i].set_title(line.substr(0, line.length() - 1));
            fin >> token;
            projects[i].set_date(token);
            line = "";
            fin >> token;
            ++i;
        }
        line += token + " ";
    }
    fin.close();
}

void fill_tasks(std::vector<skt::Task>& tasks) {
    std::ifstream fin;
    std::string token;
    std::string line = "";
    int i = 0; // index
    int count;

    check_tasks_file();
    fin.open("tasks.txt");

    fin >> token;
    if (token.compare("0") == 0) {
        return;
    }
    count = std::stoi(token); // First string shows how many projects

    tasks.resize(count);
    while (!fin.eof()) {
        fin >> token;
        if (token.compare("/-/") == 0) {
            tasks[i].set_title(line.substr(0, line.length() - 1));
            line = "";
            fin >> token;
            while (token.compare("/-/") != 0) {
                line += token + " ";
                fin >> token;
            }
            tasks[i].set_desc(line.substr(0, line.length() - 1));
            line = "";
            fin >> token;
            ++i;
        }
        line += token + " ";
    }
    fin.close();
}

void fill_users(std::vector<skt::User>& users) {
    std::ifstream fin;
    std::string token;
    std::string line = "";
    int i = 0; // index
    int count;

    check_users_file();
    fin.open("users.txt");

    fin >> token;
    if (token.compare("0") == 0) {
        return;
    }
    count = std::stoi(token); // First string shows how many projects
    
    users.resize(count);
    while (!fin.eof()) {
        fin >> token;
        if (token.compare("/-/") == 0) {
            users[i].set_name(line.substr(0, line.length() - 1));
            fin >> token;
            users[i].set_age(std::stoi(token));
            line = "";
            fin >> token;
            ++i;
        }
        line += token + " ";
    }
    fin.close();
}

void read_files(std::vector<skt::Project>& projects, std::vector<skt::Task>& tasks, std::vector<skt::User>& users) {
    fill_projects(projects);
    // fill_tasks(tasks);
    // fill_users(users);
}

void save_projects(std::vector<skt::Project>& projects) {
    std::ofstream fout;
    fout.open("projects.txt", std::ofstream::out | std::ofstream::trunc); // empty the file

    fout << projects.size() << "\n";

    for (int i = 0; i < projects.size(); ++i) {
        fout << projects[i].get_title() << " /-/ " << projects[i].get_date() << "\n";
    }
    fout.close();
}

void save_tasks(std::vector<skt::Task>& tasks) {
    std::ofstream fout;
    fout.open("tasks.txt", std::ofstream::out | std::ofstream::trunc); // empty the file

    fout << tasks.size() << "\n";

    for (int i = 0; i < tasks.size(); ++i) {
        fout << tasks[i].get_title() << " /-/\n" << tasks[i].get_desc() << " /-/\n";
    }
    fout.close();
}

void save_users(std::vector<skt::User>& users) {
    std::ofstream fout;
    fout.open("users.txt", std::ofstream::out | std::ofstream::trunc); // empty the file

    fout << users.size() << "\n";

    for (int i = 0; i < users.size(); ++i) {
        fout << users[i].get_name() << " /-/ " << users[i].get_age() << "\n";
    }
    fout.close();
}

void save_files(std::vector<skt::Project>& projects, std::vector<skt::Task>& tasks, std::vector<skt::User>& users) {
    save_projects(projects);
    // save_tasks(tasks);
    // save_users(users);
    std::cout << "\nFiles are saved, program is closed !\n";
}

bool check_update_tokens(std::string& command) { // MUST BE UPDATED !!!!
    // int token_count = 2; // 2, because first token 'update' is already checked
    // for (int i = 7; i < command.length(); ++i) {
    //     if (command[i] == ' ') {
    //         ++token_count;
    //     }
    // }

    // if (token_count == 6) {
    //     return true;
    // }
    return true;
}

bool check_update_rules(std::string& command) {
    if (command.length() < 20) { // Line length must be pretty long
        return false;
    }
    else if (command.substr(0, 6).compare("update") != 0) {
        return false;
    }
    else if (!check_update_tokens(command)) {
        return false;
    }

    return true;
}

std::string check_update_projects_action(std::string& command) { // MUST BE UPDATED !!!!
    if (command.substr(16, 3).compare("set") != 0) {
        std::cout << "\nWrong command for SET !\n";
        return "0";
    }
    else if (command.substr(20, 6).compare("title=") == 0) {
        return "title";
    }
    else if (command.substr(20, 5).compare("date=") == 0) {
        return "date";
    }
    
    return "0";
}

void update_project_title(std::vector<skt::Project>& projects, std::string& )
void update_action_projects(std::vector<skt::Project>& projects, std::string& action, std::string& command) {


    if ()
}

void update_action(std::vector<skt::Project>& projects, std::vector<skt::Task>& tasks, std::vector<skt::User>& users, std::string& command) {
    if(!check_update_rules(command)) {
        std::cout << "\nUnknown Command !\n";
        return;
    }
    std::string action;

    if (command.substr(7, 8).compare("projects") == 0) {
        action = check_update_projects_action(command);
        if (action.compare("0") == 0) {
            std::cout << "\nWrong Command for PROJECTS !\n";
            return;
        }
        update_action_projects(projects, action, command);
    }
    else if (command.substr(7, 5).compare("tasks") == 0) {
        // To do
    }
    else if (command.substr(7, 5).compare("users") == 0) {
        // To do
    }
    else {
        std::cout << "\nWrong Command for PROJECTS / TASKS / USERS !\n";
    }
}

void read_command(std::vector<skt::Project>& projects, std::vector<skt::Task>& tasks, std::vector<skt::User>& users, std::string& command) {
    if (command.length() == 4 && command.compare("exit") == 0) {
        return;
    }

    if (command[0] == 'u') { // Update Command
        update_action(projects, tasks, users, command);
    }
    else {
        std::cout << "\nUnknown Command !\n";
    }
    // TO DO Select
    // TO DO Delete
    // TO DO Else ?
}

void pms() {
    std::vector<skt::Project> projects;
    std::vector<skt::Task> tasks;
    std::vector<skt::User> users;
    std::string command = "";

    read_files(projects, tasks, users);

    // for (int i = 0; i < projects.size(); ++i) {
    //     projects[i].info();
    // }

    // for (int i = 0; i < tasks.size(); ++i) {
    //     tasks[i].info();
    // }

    // for (int i = 0; i < users.size(); ++i) {
    //     users[i].info();
    // }

    while (command.compare("exit") != 0) {
        std::getline(std::cin, command);
        read_command(projects, tasks, users, command);
    }

    save_files(projects, tasks, users);
}
