#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minVal = a[left], maxVal = a[left];
        int minPos = left, maxPos = left;

        for (int i = left; i <= right; i++) {
            if (a[i] < minVal) {
                minVal = a[i];
                minPos = i;
            }
            if (a[i] > maxVal) {
                maxVal = a[i];
                maxPos = i;
            }
        }

        swap(a[left], a[minPos]);

        if (maxPos == left)
            maxPos = minPos;

        swap(a[right], a[maxPos]);

        left++;
        right--;
    }
}

int main() {
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    improvedSelectionSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
