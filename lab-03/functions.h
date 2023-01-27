#ifndef LABARATORY_3_FUNCTIONS_H
#define LABARATORY_3_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string documentation_1 = {"Information about a specific command\n"
                                "mkdir <name>                      Create a directory with the specified name\n"
                                "create <name>                     Create a file with the specified name\n"
                                "rmdir <name1> <name2>             Delete the specified directory and all subsequent files, if any\n"
};

const string documentation_2 = {"del <name1> <name2>               Delete the specified file if such a thing exists\n"
                                "list                              Show the tree of directories and files\n"
                                "cd..                              Go to the directory containing this\n"
                                "cd <name>                         Go to directory wth the specified name, if such a thing exists\n"};

const string documentation_3 = {
        "find <directory> <file>           Searches for and outputs the full path to the file in the specified directory, if any\n"
        "help                              Output a list of commands and instructions for their use\n"
        "exit                              Exit the command line\n"};

struct node {
    string name;
    char node_type;  // d - directory , f - file
    vector<struct node> next;
    string parent;
};

struct node createNode(string name, char node_type, struct node* root);

struct node* insert(struct node* root, string name, char node_type);

void list(struct node* root, int spaces);

size_t split(const string& txt, vector<string>& strings, char splitter);

struct node* main_directory(struct node* root, string name, char node_type);

bool isSameName(struct node* root, string name, char node_type);

int deleted_file(struct node* root, string name);

int deleted_directory(struct node* root, string name);

struct node* findNode(struct node* root, string name, char node_type);

#endif //LABARATORY_3_FUNCTIONS_H