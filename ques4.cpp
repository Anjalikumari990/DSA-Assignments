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

class Tree{
public:
    Node* root;
    Tree(){
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

    bool check(Node* r, int min, int max){
        if(!r){
            return true;
        }
        if(r->data <= min || r->data >= max){
            return false;
        }
        return check(r->left, min, r->data) && check(r->right, r->data, max);
    }
};

int main(){
    Tree t;
    t.root = t.insert(t.root, 5);
    t.root = t.insert(t.root, 3);
    t.root = t.insert(t.root, 9);
    cout << t.check(t.root, -100000, 100000);
}
