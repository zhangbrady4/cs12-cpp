#include <iostream>
using namespace std;

struct node {
    node(int, node*, node*);
    int c;
    node* left;
    node* right;

    // bool operator<(conc node &rhs) conc{
    //  return ( c < rhs.c );
    // }
};

node::node(int x, node* l = 0, node* r = 0)
{
    c = x;
    left = l;
    right = r;
}

void prewalk(node* nd)
{
    if (nd != 0) {
        cout << nd->c;
        prewalk(nd->left);
        prewalk(nd->right);
    }
}

void postwalk(node* nd)
{
    if (nd != 0) {
        postwalk(nd->left);
        postwalk(nd->right);
        cout << nd->c;
    }
}
void inwalk(node* nd)
{
    if (nd != 0) {
        inwalk(nd->left);
        cout << nd->c;
        inwalk(nd->right);
    }
}

/*
node* NewNode(int c){
node* np = new node;
np->c = c;
np->left = 0;
np->right = 0;
return np;
}*/

/* must pass nd by ref since we may need to insert at the
root node and hence change the root addr */
void insert(node*& nd, int c)
{ // inserts with order
    if (nd == 0) { // or !nd
        nd = new node(c); // call new directly for defined struct ctor
        // cout<<c;
    } else {
        if (c < nd->c) {
            if (nd->left == 0) {
                nd->left = new node(c);
                // cout<<c;
            } else {
                insert(nd->left, c);
            }
        } else if (c > nd->c) {
            if (nd->right == 0) {
                nd->right = new node(c);
                // cout<<c;
            } else {
                insert(nd->right, c);
            }
        }
    }
}

void lfree(node* nd)
{ // which order should deleting be: (pre, in, post ) only one of them will work
    if (nd != 0) {
        lfree(nd->left);
        lfree(nd->right);
        delete nd;
        nd = 0;
    }

    /*if (nd == 0) return;
    lfree(nd->next); //recursion first
    cout<<"free node"<<endl;
    delete nd;
    nd = 0;*/
}

int main()
{
    const int iarray[7] = { 4, 2, 6, 1, 3, 5, 7 };
    node* root = 0;

    int x;
    for (x = 0; x < 7; x++) {
        insert(root, iarray[x]);
        // walk(root);
        // cout<<endl;
    }

    cout << "Pre" << endl;
    prewalk(root);
    cout << endl;

    cout << "Post" << endl;
    postwalk(root);
    cout << endl;

    cout << "In" << endl;
    inwalk(root);
    cout << endl;

    lfree(root);
    return (0);
}
