#include <iostream>
#include "treenode.h"

using namespace std;

int main()
{
    TreeNode tree;

    int numOfWords;
    char* word;


    cout << "How many words do you want to add to the dictionary? " << endl;
    cin >> numOfWords;

    for (int i=0; i < numOfWords; i++){
        cout << "Enter word to add to the dictionary: ";

        word = new char[255];

        cin >> word;

        tree.addWord(word);
    }

    cout << "--------PREORDER DISPLAY---------" << endl;
    tree.preOrderDisplay();

    cout << "--------POSTORDER DISPLAY--------" << endl;
    tree.postOrderDisplay();

    cout << "--------IN ORDER DISPLAY----------" << endl;
    tree.inOrderDisplay();

    return 0;
}

