#ifndef TREENODE_H
#define TREENODE_H

using namespace std;

class TreeNode
{
private:
    char *item;
    TreeNode *left;
    TreeNode *right;
    int strcmp(char *, char *);
public:
    TreeNode();
    ~TreeNode();
    void addWord(char* word);
    void preOrderDisplay();
    void postOrderDisplay();
    void inOrderDisplay();
};

#endif // TREENODE_H
