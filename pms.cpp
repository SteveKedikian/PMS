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

    check_projects_file(); // Create new .txt file, if none exist
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

    check_tasks_file(); // Create new .txt file, if none exist
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

    check_users_file(); // Create new .txt file, if none exist
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
    fill_tasks(tasks);
    fill_users(users);
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
    save_tasks(tasks);
    save_users(users);
    std::cout << "\nFiles are saved, program is closed !\n";
}

void keyword_separater(std::string *com_tokens, std::string& command, int& i, int& token_count) {
    std::string line = "";
    while (command[i] != '=') {
        if (command[i] == ' ') {
            com_tokens[token_count] = line;
            line = "";
            ++token_count;
            ++i;
            continue;
        }
        line += command[i];
        ++i;
    }
    com_tokens[token_count] = line;
    token_count++;
}

void component_separator(std::string& command, int& i, std::string& component) {
    std::string line = "";
    while (command[i] != '"') {
        line += command[i];
        ++i;
    }
    component = line;
}

void token_separator(std::string *com_tokens, std::string& command, std::string& component_1, std::string& component_2) {
    int i = 0;
    int token_count = 0;

    keyword_separater(com_tokens, command, i, token_count);
    i += 2; // skip ", like "hello world", starting from 'h'

    component_separator(command, i, component_1);
    i += 2; // skip to condition token

    keyword_separater(com_tokens, command, i, token_count);
    i += 2; // skip ", like "hello world", starting from 'h'

    component_separator(command, i, component_2);
}

void update_project_title_by_title(std::vector<skt::Project>& projects, std::string& component_1, std::string& component_2) {
    for (int i = 0; i < projects.size(); ++i) {
        if (projects[i].get_title().compare(component_2) == 0) {
            projects[i].set_title(component_1);
        }
    }
}

void update_project_title_by_date(std::vector<skt::Project>& projects, std::string& component_1, std::string& component_2) {
    for (int i = 0; i < projects.size(); ++i) {
        if (projects[i].get_date().compare(component_2) == 0) {
            projects[i].set_title(component_1);
        }
    }
}

void update_project_date_by_title(std::vector<skt::Project>& projects, std::string& component_1, std::string& component_2) {
    for (int i = 0; i < projects.size(); ++i) {
        if (projects[i].get_title().compare(component_2) == 0) {
            projects[i].set_date(component_1);
        }
    }
}

void update_project_date_by_date(std::vector<skt::Project>& projects, std::string& component_1, std::string& component_2) {
    for (int i = 0; i < projects.size(); ++i) {
        if (projects[i].get_date().compare(component_2) == 0) {
            projects[i].set_date(component_1);
        }
    }
}

void update_project_title(std::vector<skt::Project>& projects, std::string *com_tokens, std::string& component_1, std::string& component_2) {
    if (com_tokens[5].compare("title") == 0) {
        update_project_title_by_title(projects, component_1, component_2);
    }
    else if (com_tokens[5].compare("date") == 0) {
        update_project_title_by_date(projects, component_1, component_2);
    }
    else {
        // other option
    }
}

void update_project_date(std::vector<skt::Project>& projects, std::string *com_tokens, std::string& component_1, std::string& component_2) {
    if (com_tokens[5].compare("title") == 0) {
        update_project_date_by_title(projects, component_1, component_2);
    }
    else if (com_tokens[5].compare("date") == 0) {
        update_project_date_by_date(projects, component_1, component_2);
    }
    else {
        // other option
    }
}

void update_for_projects(std::vector<skt::Project>& projects, std::string *com_tokens, std::string& component_1, std::string& component_2) {
    if (com_tokens[3].compare("title") == 0) {
        update_project_title(projects, com_tokens, component_1, component_2);
    }
    else if (com_tokens[3].compare("date") == 0) {
        update_project_date(projects, com_tokens, component_1, component_2);
    }
    else {
        // other option
    }
}

void update_task_title_by_title(std::vector<skt::Task>& tasks, std::string& component_1, std::string& component_2) {
    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i].get_title().compare(component_2) == 0) {
            tasks[i].set_title(component_1);
        }
    }
}

void update_task_title_by_description(std::vector<skt::Task>& tasks, std::string& component_1, std::string& component_2) {
    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i].get_desc().compare(component_2) == 0) {
            tasks[i].set_title(component_1);
        }
    }
}

void update_task_description_by_title(std::vector<skt::Task>& tasks, std::string& component_1, std::string& component_2) {
    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i].get_title().compare(component_2) == 0) {
            tasks[i].set_desc(component_1);
        }
    }
}

void update_task_description_by_description(std::vector<skt::Task>& tasks, std::string& component_1, std::string& component_2) {
    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i].get_desc().compare(component_2) == 0) {
            tasks[i].set_desc(component_1);
        }
    }
}

void update_task_title(std::vector<skt::Task>& tasks, std::string *com_tokens, std::string& component_1, std::string& component_2) {
    if (com_tokens[5].compare("title") == 0) {
        update_task_title_by_title(tasks, component_1, component_2);
    }
    else if (com_tokens[5].compare("description") == 0) {
        update_task_title_by_description(tasks, component_1, component_2);
    }
    else {
        // other option
    }
}

void update_task_description(std::vector<skt::Task>& tasks, std::string *com_tokens, std::string& component_1, std::string& component_2) {
    if (com_tokens[5].compare("title") == 0) {
        update_task_description_by_title(tasks, component_1, component_2);
    }
    else if (com_tokens[5].compare("description") == 0) {
        update_task_description_by_description(tasks, component_1, component_2);
    }
    else {
        // other option
    }
}

void update_for_tasks(std::vector<skt::Task>& tasks, std::string *com_tokens, std::string& component_1, std::string& component_2) {
    if (com_tokens[3].compare("title") == 0) {
        update_task_title(tasks, com_tokens, component_1, component_2);
    }
    else if (com_tokens[3].compare("description") == 0) {
        update_task_description(tasks, com_tokens, component_1, component_2);
    }
    else {
        // other option
    }
}

void update_user_name_by_name(std::vector<skt::User>& users, std::string& component_1, std::string& component_2) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].get_name().compare(component_2) == 0) {
            users[i].set_name(component_1);
        }
    }
}

void update_user_name_by_age(std::vector<skt::User>& users, std::string& component_1, std::string& component_2) {
    for (int i = 0; i < users.size(); ++i) {
        if (std::to_string(users[i].get_age()).compare(component_2) == 0) {
            users[i].set_name(component_1);
        }
    }
}

void update_user_age_by_name(std::vector<skt::User>& users, std::string& component_1, std::string& component_2) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].get_name().compare(component_2) == 0) {
            users[i].set_age(std::stoi(component_1));
        }
    }
}

void update_user_age_by_age(std::vector<skt::User>& users, std::string& component_1, std::string& component_2) {
    for (int i = 0; i < users.size(); ++i) {
        if (std::to_string(users[i].get_age()).compare(component_2) == 0) {
            users[i].set_age(std::stoi(component_1));
        }
    }
}

void update_user_name(std::vector<skt::User>& users, std::string *com_tokens, std::string& component_1, std::string& component_2) {
    if (com_tokens[5].compare("name") == 0) {
        update_user_name_by_name(users, component_1, component_2);
    }
    else if (com_tokens[5].compare("age") == 0) {
        update_user_name_by_age(users, component_1, component_2);
    }
    else {
        // other option
    }
}

void update_user_age(std::vector<skt::User>& users, std::string *com_tokens, std::string& component_1, std::string& component_2) {
    if (com_tokens[5].compare("name") == 0) {
        update_user_age_by_name(users, component_1, component_2);
    }
    else if (com_tokens[5].compare("age") == 0) {
        update_user_age_by_age(users, component_1, component_2);
    }
    else {
        // other option
    }
}

void update_for_users(std::vector<skt::User>& users, std::string *com_tokens, std::string& component_1, std::string& component_2) {
    if (com_tokens[3].compare("name") == 0) {
        update_user_name(users, com_tokens, component_1, component_2);
    }
    else if (com_tokens[3].compare("age") == 0) {
        update_user_age(users, com_tokens, component_1, component_2);
    }
    else {
        // other option
    }
}

void update_action(std::vector<skt::Project>& projects, std::vector<skt::Task>& tasks, std::vector<skt::User>& users, std::string *com_tokens, std::string& component_1, std::string& component_2) {
    if (com_tokens[1].compare("projects") == 0) {
        update_for_projects(projects, com_tokens, component_1, component_2);
    }
    else if (com_tokens[1].compare("tasks") == 0) {
        update_for_tasks(tasks, com_tokens, component_1, component_2);
    }
    else if (com_tokens[1].compare("users") == 0) {
        update_for_users(users, com_tokens, component_1, component_2);
    }
    else {
        // other option
    }
}

void read_command(std::vector<skt::Project>& projects, std::vector<skt::Task>& tasks, std::vector<skt::User>& users, std::string& command) {
    std::string com_tokens[6];
    std::string component_1;
    std::string component_2;
    token_separator(com_tokens, command, component_1, component_2);
    
    // std::cout << "\n_" << com_tokens[0] << "_" << com_tokens[1] << "_" << com_tokens[2] << "_" << com_tokens[3] << "_" << com_tokens[4] << "_" << com_tokens[5] << "_\n";
    // std::cout << "_" << component_1 << "_" << component_2 << "_\n";

    if (com_tokens[0].compare("select") == 0) {
        // TO DO
    }
    else if (com_tokens[0].compare("update") == 0) {
        update_action(projects, tasks, users, com_tokens, component_1, component_2);
    }
    else if (com_tokens[0].compare("create") == 0) {
        // TO DO
    }
    else if (com_tokens[0].compare("delete") == 0) {
        // TO DO
    }
    else {
        // other option
    }
}

void pms() {
    std::vector<skt::Project> projects;
    std::vector<skt::Task> tasks;
    std::vector<skt::User> users;
    std::string command;

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

    while (true) {
        std::getline(std::cin, command);
        if (command.compare("exit") == 0) {
            break;
        }
        read_command(projects, tasks, users, command);
    }

    save_files(projects, tasks, users);
}