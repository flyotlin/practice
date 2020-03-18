#include <iostream>
#define endl '\n'
using namespace std;
struct node {
    int data;
    struct node *left = NULL;
    struct node *right = NULL;
};
void traversal(struct node *ptr, int idata) {
    if(idata < ptr->data) {
        if(ptr->left == NULL) {
            struct node *newnode = new struct node;
            newnode->data = idata;
            ptr->left = newnode;
            return;
        }
        else {
            traversal(ptr->left, idata);
        }
    }
    else if(idata > ptr->data) {
        if(ptr->right == NULL) {
            struct node *newnode = new struct node;
            newnode->data = idata;
            ptr->right = newnode;
            return;
        }
        else {
            traversal(ptr->right, idata);
        }
    }
};
void postorder_traversal(struct node* p) {
    if(p != NULL) {
        postorder_traversal(p->left);
        postorder_traversal(p->right);
        cout << p->data << endl;
    }
}
int main() {
    int c;
    cin >> c;
    struct node *root = new struct node;
    root->data = c;
    while(cin >> c) {
        traversal(root, c);
    }
    postorder_traversal(root);

    return 0;
}
