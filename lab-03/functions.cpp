#include "functions.h"

struct node createNode(string name, char node_type, struct node* root) {
    struct node newNode;
    newNode.name = name;
    newNode.node_type = node_type;
    if (root == nullptr) { newNode.parent = name; } else { newNode.parent = root->parent + "/" + name; }
    return newNode;
}

struct node* insert(struct node* root, string name, char node_type) {
    if (!isSameName(root, name, node_type)) {
        root->next.push_back(createNode(name, node_type, root));
    }
    return root;
}

void list(struct node* root, int spaces) {
    if (root == NULL) return;
    if (spaces > 0) {
        for (int i = 0; i < spaces; ++i) {
            printf("   ");
        }
    }
    printf("%s (%c)\r\n", root->name.c_str(), root->node_type);

    if (root->next.empty()) return;
    for (int i = 0; i < root->next.size(); ++i) {
        list(&root->next[i], spaces + 1);
    }
}

size_t split(const string& txt, vector<string>& strings, char splitter) {
    size_t pos = txt.find(splitter);
    size_t i = 0;
    strings.clear();
    while (pos != string::npos) {
        strings.push_back(txt.substr(i, pos - i));
        i = pos + 1;
        pos = txt.find(splitter, i);
    }
    strings.push_back(txt.substr(i, min(pos, txt.size() - i + 1)));
    return strings.size();
}

struct node* main_directory(struct node* root, string name, char node_type) {
    struct node* desiredNode;
    for (int i = 0; i < root->next.size(); i++) {
        desiredNode = &root->next[i];
        if (desiredNode->name == name && desiredNode->node_type == node_type)
            return desiredNode;
    }
    return nullptr;
}

bool isSameName(struct node* root, string name, char node_type) {
    if (root->next.empty()) { return false; }

    for (int i = 0; i < root->next.size(); ++i) {
        if (root->next[i].name == name && root->next[i].node_type == node_type) { return true; }
    }
    return false;
}

int deleted_file(struct node* root, string name) {
    for (int i = 0; i < root->next.size(); ++i) {
        if (root->next[i].name == name && root->next[i].node_type == 'f') {
            root->next.erase(root->next.cbegin() + i);
            return 0;
        }
    }
    return -1;
}

int deleted_directory(struct node* root, string name) {
    for (int i = 0; i < root->next.size(); ++i) {
        if (root->next[i].name == name && root->next[i].node_type == 'd') {
            root->next.erase(root->next.cbegin() + i);
            return 0;
        }
    }
    return -1;
}

struct node* findNode(struct node* root, string name, char node_type) {
    if (root->name == name && root->node_type == node_type) { return root; }
    else {
        for (int i = 0; i < root->next.size(); i++) {
            struct node* desiredNode = &root->next[i];
            if (desiredNode->name == name && desiredNode->node_type == node_type)
                return desiredNode;
        }
        for (int i = 0; i < root->next.size(); i++) {
            struct node* desiredNode = findNode(&root->next[i], name, node_type);
            if (desiredNode != nullptr)
                return desiredNode;
        }
        return nullptr;
    }
}
