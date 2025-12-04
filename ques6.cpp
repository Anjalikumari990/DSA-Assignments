#include<iostream>
using namespace std;

class PQ{
public:
    int a[100];
    int n;

    PQ(){ n = 0; }

    void push(int x){
        a[n] = x;
        int i = n;
        n++;
        while(i>0 && a[(i-1)/2] < a[i]){
            swap(a[i], a[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int pop(){
        int x = a[0];
        a[0] = a[n-1];
        n--;

        int i = 0;
        while(true){
            int l = 2*i+1, r = 2*i+2;
            int mx = i;

            if(l < n && a[l] > a[mx]) mx = l;
            if(r < n && a[r] > a[mx]) mx = r;

            if(mx == i) break;

            swap(a[i], a[mx]);
            i = mx;
        }
        return x;
    }
};

int main(){
    PQ p;
    p.push(20);
    p.push(5);
    p.push(100);
    p.push(50);

    cout << p.pop() << endl;
    cout << p.pop() << endl;
}
