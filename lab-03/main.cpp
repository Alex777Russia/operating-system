#include "functions.h"

int main() {
    node root = createNode("/", 'd', nullptr);
    node* current = &root;

    while (true) {
        string value;
        getline(cin, value);
        vector<string> token;
        split(value, token, ' ');

        if (token.size() >= 1) {
            if (token[0] == "mkdir") {
                if (!isSameName(current, token[1], 'd')) {}
                else { cout << "The directory with the same name already exists\n"; }
                insert(current, token[1], 'd');
            } else if (token[0] == "create") {
                if (!isSameName(current, token[1], 'f')) {}
                else { cout << "The file with the same name already exists\n"; }
                insert(current, token[1], 'f');
            } else if (token[0] == "list") {
                list(current, 0);
            } else if (token[0] == "cd") {
                if (main_directory(current, token[1], 'd') != nullptr) {
                    current = main_directory(current, token[1], 'd');
                } else { cout << "Directory " << token[1] << " does not exist\n"; }
            } else if (token[0] == "cd..") {
                current = &root;
            } else if (token[0] == "del") {
                for (int i = 1; i < token.size(); ++i) {
                    if (!deleted_file(current, token[i])) {}
                    else { cout << "File " << token[i] << " does not exist" << "\n"; }
                }
            } else if (token[0] == "rmdir") {
                for (int i = 1; i < token.size(); ++i) {
                    if (!deleted_directory(current, token[i])) {}
                    else { cout << "Directory " << token[i] << " does not exist\n"; }
                }
            } else if (token[0] == "find" && token.size() == 3) {
                node* first = findNode(&root, token[2], 'd');
                node* second = findNode(first, token[1], 'f');
                if (first != nullptr && second != nullptr) {
                    cout << second->parent << endl;
                } else { cout << "Incorrect request (No such file or directory)" << endl; }
            } else if (token[0] == "help") {
                cout << documentation_1 << documentation_2 << documentation_3;
                cout << endl;
            } else if (token[0] == "exit") {
                return 0;
            } else {
                cout << "\"" << token[0] << "\"" << " is not an internal or external\n"
                                                    "command, an executable program, or a batch file."
                                                    "\nUse " << "\"" << "help" << "\""
                     << " for read the documentation\n";
            }
        }
    }
}
