//
//  main.cpp
//  final_exam
//
//  Created by Leo  Innocenzi on 08/06/2021.
//

#include <iostream>

struct Node {
    char val;
    int index;
    Node* left;
    Node* right;
};

class BST {
public:
    BST();
    ~BST();
    
    Node* insert(Node* p);
    void traversal(Node* root);
    Node* deleteLeaf(Node* p);

private:
    Node* root;
};

BST::BST()
:root(0)
{}

BST::~BST()
{}


Node* BST::insert(Node *p) {
    
    if(root == 0) {
        root = p;
    }
    else if (p->index > root->index) {
        root->left = insert(root->left);
    }
    else if(p->index < root->index) {
        root->right = insert(root->right);
    }
    
    return(root);
}

void BST::traversal(Node *root) {
    if (root != NULL) {
        traversal(root->left);
        std::cout << root->val;
        traversal(root->right);
    }
}


Node* BST::deleteLeaf(Node* p) {
    if(root == NULL) {
        return NULL;
    }
    if ((root->left == NULL) && (root->right == NULL)){
        free(root);
        return NULL;
    }
    root->right = deleteLeaf(root->right);
    root->left = deleteLeaf(root->left);
    
    return(root);
}



int main(int argc, const char * argv[]) {
    
    BST Tree;
    Node p;
    char cmd;
    char data[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    do{
        std::cout << "command :";
        std::cin >> cmd;
        
        int indexData = 0;
        for(int i = 0; i < 27; i++){
            if(cmd == data[i])
                indexData = i;
        }
        p.val = cmd;
        p.index = indexData;
        Tree.insert(&p);
        
    }while(cmd != '$');
    

        
    
    return 0;
}
