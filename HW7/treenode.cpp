#include <iostream>
#include "treenode.h"
#include <string.h>

using namespace std;

/*** Constructor ***/
TreeNode::TreeNode()
{
    this->left = NULL;
    this->right = NULL;
    this->item = NULL;
}

/*** Destructor ***/
TreeNode::~TreeNode()
{
    //destruct left nodes
    if (this->left != NULL){
        delete this->left;
    }

    //destruct right nodes
    if (this->right != NULL){
        delete this->right;
    }

    //release memory
    delete[] this->item;
}

void TreeNode::addWord(char *word){
    //initialize value of node
    if (this->item == NULL){
        this->item = word;
    }else{
        //decide where new word will go, to the left or right subnode
        if (strcmp(this->item, word) > 0){
            //add new word to left subnode
            if (this->left == NULL) this->left = new TreeNode();
            this->left->addWord(word);
        }else if (strcmp(this->item, word) < 0){
            //add new word to right subnode
            if (this->right == NULL) this->right = new TreeNode();
            this->right->addWord(word);
        }
    }
}

void TreeNode::inOrderDisplay(){
    //first display left values
    if (this->left != NULL){
        this->left->inOrderDisplay();
    }
    //display root value
    cout << "word=" << this->item << endl;

    //display right values
    if (this->right != NULL){
        this->right->inOrderDisplay();
    }
}

void TreeNode::postOrderDisplay(){
    //display left values
    if (this->left != NULL){
        this->left->postOrderDisplay();
    }

    //display right values
    if (this->right != NULL){
        this->right->postOrderDisplay();
    }

    //display root value
    cout << "word=" << this->item << endl;
}

void TreeNode::preOrderDisplay(){
    //display root value
    cout << "word=" << this->item << endl;

    //display left values
    if (this->left != NULL){
        this->left->preOrderDisplay();
    }

    //display right values
    if (this->right != NULL){
        this->right->preOrderDisplay();
    }
}

int TreeNode::strcmp(char* stringA, char* stringB){
    int lenA = strlen(stringA);
    int lenB = strlen(stringB);

    int len = (lenA > lenB ? lenB : lenA);

    for (int i=0; i<len; i++){
        if (int(stringA[i]) > int(stringB[i])) return 1;
        else if(int(stringA[i]) < int(stringB[i])) return -1;
    }

    return 0;
}
