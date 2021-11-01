#include <iostream>

using namespace std;

struct Node {
    struct Node *left = NULL;
    struct Node *right = NULL;
    int val;
};

int fill_node(struct Node *node, int left_val, int right_val) {
    struct Node *left = new struct Node;
    struct Node *right = new struct Node;
    left->val = left_val;
    right->val = right_val;

    node->left = left;
    node->right = right;
}

void print_tree(struct Node *start_node, int level = 0) {
    for (int i = 0 ; i < level; i++) {
        cout << '-';
    } 

    cout << start_node->val << "\n";

    if (start_node->left != NULL) {
        print_tree(start_node->left, level + 1);
    }
    
    if (start_node->right != NULL) {
        print_tree(start_node->right, level + 1);
    }
} 

void reverse_tree(struct Node *node) {
    struct Node *tmp = node->left;
    
    node->left = node->right;
    node->right = tmp;

    if (node->left != NULL) {
        reverse_tree(node->left);
    }
    
    if (node->right != NULL) {
        reverse_tree(node->right);
    }
}

int main() {
    struct Node *root = new struct Node;
    root->val = 0;

    fill_node(root, 1, 2);
    fill_node(root->left, 3, 4);
    fill_node(root->right, 5, 6);

    print_tree(root, 0);
    reverse_tree(root);
    cout << "\nReversed:\n";
    print_tree(root, 0);
}