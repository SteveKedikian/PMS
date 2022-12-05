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

void keyword_separater(std::string* ,std::string& ,int& ,int& );
void component_separator(std::string& ,int& ,std::string& );
void token_separator(std::string* ,std::string& ,std::string& ,std::string&);
void read_command(std::vector<skt::Project>& ,std::vector<skt::Task>& ,std::vector<skt::User>& ,std::string&);

void update_project_title_by_title(std::vector<skt::Project>& ,std::string& ,std::string&);
void update_project_title_by_date(std::vector<skt::Project>& ,std::string& ,std::string&);
void update_project_date_by_title(std::vector<skt::Project>& ,std::string& , std::string&);
void update_project_date_by_date(std::vector<skt::Project>& ,std::string& , std::string&);
void update_project_title(std::vector<skt::Project>& ,std::string* ,std::string& ,std::string&);
void update_project_date(std::vector<skt::Project>& ,std::string* ,std::string& ,std::string&);
void update_for_projects(std::vector<skt::Project>& ,std::string* ,std::string& ,std::string&);

void update_task_title_by_title(std::vector<skt::Task>& ,std::string& ,std::string&);
void update_task_title_by_description(std::vector<skt::Task>& ,std::string& ,std::string&);
void update_task_description_by_title(std::vector<skt::Task>& ,std::string& ,std::string&);
void update_task_description_by_description(std::vector<skt::Task>& ,std::string& ,std::string&);
void update_task_title(std::vector<skt::Task>& ,std::string* ,std::string& ,std::string&);
void update_task_description(std::vector<skt::Task>& ,std::string* ,std::string& ,std::string&);
void update_for_tasks(std::vector<skt::Task>& , std::string* ,std::string& ,std::string&);

void update_user_name_by_name(std::vector<skt::User>& ,std::string& ,std::string&);
void update_user_name_by_age(std::vector<skt::User>& ,std::string& ,std::string&);
void update_user_age_by_name(std::vector<skt::User>& ,std::string& ,std::string&);
void update_user_age_by_age(std::vector<skt::User>& ,std::string& ,std::string&);
void update_user_name(std::vector<skt::User>& ,std::string* ,std::string& ,std::string&);
void update_user_age(std::vector<skt::User>& ,std::string* ,std::string& ,std::string&);
void update_for_users(std::vector<skt::User>& ,std::string* ,std::string& ,std::string&);

void pms();

#endif