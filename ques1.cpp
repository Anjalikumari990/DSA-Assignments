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

class bst{
    public: 
    Node* root;
    bst(){
        root = nullptr;
    }

    void preorder(Node* root){
        if(!root){
            return;
        }
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }

    void inorder(Node* root){
        if(!root){
            return;
        }
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }

    void postorder(Node* root){
        if(!root){
            return;
        }
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }

    void create(){
        int x;
        cin >> x;
        Node* p = root;
        Node* q;

        if(root == nullptr){
            root = new Node(x);
            return;
        }
        else{
            q = new Node(x);
            p = root;
            while(true){
                if(q -> data < p -> data){
                    if(p -> left == nullptr){
                        p -> left = q;
                        break;
                    }else{
                        p = p -> left;
                    }
                }
                else if(q -> data > p -> data){
                    if(p -> right == nullptr){
                        p -> right = q;
                        break;
                    }else{
                        p = p -> right;
                    }
                }
            }
        }
    }
};

int main(){
    bst t;
    int n;
    cin >> n;

    for(int i = 0; i< n; i++){
        t.create();
    }

    t.preorder(t.root);
    cout << endl;

    t.inorder(t.root);
    cout << endl;

    t.postorder(t.root);
    cout << endl;

    return 0;
}