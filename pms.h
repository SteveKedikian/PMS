#ifndef PMS_H
#define PMS_H

#include <vector>

#include "user.h"
#include "project.h"
#include "task.h"

void check_projects_file();
void check_tasks_file();
void check_users_file();
void fill_projects(std::vector<skt::Project>&);
void fill_tasks(std::vector<skt::Task>&);
void fill_users(std::vector<skt::User>&);
void read_files(std::vector<skt::Project>&, std::vector<skt::Task>&, std::vector<skt::User>&);
void save_projects(std::vector<skt::Project>&);
void save_tasks(std::vector<skt::Task>&);
void save_users(std::vector<skt::User>&);
void save_files(std::vector<skt::Project>&, std::vector<skt::Task>&, std::vector<skt::User>&);
void pms();

#endif