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

    Node* search(Node* r, int x){
        if(!r || r -> data == x){
            return r;
        }
        if(x < r -> data){
            return search(r -> left, x);
        }
        return search( r -> right, x);
    }

    int minimum(){
        Node* p = root;
        while(p -> left){
            p = p -> left;
        }
        return p -> data;
    }

    int maximum(){
        Node* p = root;
        while(p -> right){
            p = p -> right;
        }
        return p -> data;
    }

    Node* successor(int x){
        Node* p = root;
        Node* succ = nullptr;

        while(p){
            if(x < p-> data){
                succ = p;
                p = p -> left;
            }
            else{
                p = p -> right;
            }
        }
        return succ;
    }

    Node* predecessor(int x){
        Node* p = root;
        Node* pred = nullptr;

        while(p){
            if(x > p-> data){
                pred = p;
                p = p -> right;
            }
            else{
                p = p -> left;
            }
        }
        return pred;
    }
};

int main(){
    bst t;
    int n;
    cin >> n;

    for(int i = 0; i< n; i++){
        t.create();
    }

    Node* ans = t.search(t.root, 40);
    if(ans){
        cout << ans-> data;
    }else{
        cout << "not found";
    }

    cout << t.minimum() << endl;
    cout << t.maximum() << endl;
    cout << t.successor(40)->data << endl;
    cout << t.predecessor(40)->data << endl;

    return 0;
}