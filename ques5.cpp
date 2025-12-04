#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i+1;

        if(left <= n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right <= n && arr[right] > arr[largest]){
             largest = right;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

void heapsort(int arr[], int n){
    int size = n;

    while(size > 1){
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    heapsort(a,n);
    for(int i=0;i<n;i++) cout << a[i] << " ";
}
