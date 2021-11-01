#include <iostream>

using namespace std;

struct Node {
    struct Node *next;
    struct Node *prev;
    int val;
};

void print_list(struct Node *node) {
    cout << node->val;

    if (node->next == NULL) {
        return;
    }

    cout << " -> ";

    print_list(node->next);
}

// recursivelry reverse list and return new start
struct Node *reverse_list(struct Node *node) {
    if (node->next == NULL) {
        node->next = node->prev;
        node->prev = NULL;

        return node;
    }

    struct Node *tmp_node = node->prev;
    node->prev = node->next;
    node->next = tmp_node;

    reverse_list(node->prev);
}

int main() {
    struct Node *start = new struct Node;

    start->prev = NULL;
    start->next = NULL;
    start->val = 0;

    struct Node *curr_node = start;

    for (int i = 1; i < 10; i++) {
        struct Node *new_node = new struct Node;
        new_node->val = i;
        new_node->prev = curr_node;
        new_node->next = NULL;

        curr_node->next = new_node;
        curr_node = new_node;
    }

    print_list(start);
    start = reverse_list(start);
    cout << "\nReversed:\n";
    print_list(start);
}