#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

class BST{
public:
    Node* root;
    BST(){
        root = nullptr;
    }

    Node* insert(Node* r, int x){
        if(!r){
            return new Node(x);
        }
        if(x < r->data){
            r->left = insert(r->left, x);
        }else{
            r->right = insert(r->right, x);
        }
        return r;
    }

    Node* minNode(Node* r){
        while(r->left){
            r = r->left;
        }
        return r;
    }

    Node* deleteNode(Node* r, int x){
        if(!r){
            return r;
        }
        if(x < r->data){
            r->left = deleteNode(r->left, x);
        }
        else if{
            (x > r->data) r->right = deleteNode(r->right, x);
        }else{
            if(!r->left) return r->right;
            if(!r->right) return r->left;
            Node* t = minNode(r->right);
            r->data = t->data;
            r->right = deleteNode(r->right, t->data);
        }
        return r;
    }

    int maxDepth(Node* r){
        if(!r){
            return 0;
        }
        int l = maxDepth(r->left);
        int r1 = maxDepth(r->right);
        return (l > r1 ? l : r1) + 1;
    }

    int minDepth(Node* r){
        if(!r){
            return 0;
        }
        int l = minDepth(r->left);
        int r1 = minDepth(r->right);
        return (l < r1 ? l : r1) + 1;
    }
};

int main(){
    BST t;
    t.root = t.insert(t.root, 50);
    t.root = t.insert(t.root, 30);
    t.root = t.insert(t.root, 70);

    t.root = t.deleteNode(t.root, 30);

    cout << t.maxDepth(t.root) << endl;
    cout << t.minDepth(t.root) << endl;
}
