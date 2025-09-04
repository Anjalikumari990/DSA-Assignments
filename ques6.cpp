#include <iostream>
using namespace std;

void readMatrix(int mat[][3], int &num) {
    cout << "Enter number of rows, columns and non-zero elements: ";
    cin >> mat[0][0] >> mat[0][1] >> num;
    mat[0][2] = num;

    cout << "Enter row, column, value for each non-zero element:\n";
    for (int i = 1; i <= num; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}

void display(int mat[][3]) {
    int n = mat[0][2];
    cout << "Row Col Val\n";
    for (int i = 0; i <= n; i++) {
        cout << mat[i][0] << "   "
             << mat[i][1] << "   "
             << mat[i][2] << endl;
    }
}

void transpose(int a[][3], int t[][3]) {
    int n = a[0][2];
    t[0][0] = a[0][1];
    t[0][1] = a[0][0];
    t[0][2] = n;

    int k = 1;
    for (int col = 0; col < a[0][1]; col++) {
        for (int i = 1; i <= n; i++) {
            if (a[i][1] == col) {
                t[k][0] = a[i][1];
                t[k][1] = a[i][0];
                t[k][2] = a[i][2];
                k++;
            }
        }
    }
}

void add(int a[][3], int b[][3], int sum[][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Matrices cannot be added!\n";
        sum[0][2] = 0;
        return;
    }

    int i = 1, j = 1, k = 1;
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2];
            i++; k++;
        } else if (b[j][0] < a[i][0] || (a[i][0] == b[j][0] && b[j][1] < a[i][1])) {
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            j++; k++;
        } else {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
    }
    while (i <= a[0][2]) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++; k++;
    }

    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];
    sum[0][2] = k - 1;
}

void multiply(int a[][3], int b[][3], int mul[][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Matrices cannot be multiplied!\n";
        mul[0][2] = 0;
        return;
    }

    int k = 1;
    mul[0][0] = a[0][0];
    mul[0][1] = b[0][1];

    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= b[0][2]; j++) {
            if (a[i][1] == b[j][0]) {
                int r = a[i][0];
                int c = b[j][1];
                int v = a[i][2] * b[j][2];

                // check if already exists
                int found = -1;
                for (int x = 1; x < k; x++) {
                    if (mul[x][0] == r && mul[x][1] == c) {
                        found = x;
                        break;
                    }
                }
                if (found != -1) mul[found][2] += v;
                else {
                    mul[k][0] = r;
                    mul[k][1] = c;
                    mul[k][2] = v;
                    k++;
                }
            }
        }
    }

    mul[0][2] = k - 1;
}

int main() {
    int A[50][3], B[50][3], T[50][3], S[100][3], M[100][3];
    int n1, n2;

    cout << "Enter first sparse matrix:\n";
    readMatrix(A, n1);
    cout << "Enter second sparse matrix:\n";
    readMatrix(B, n2);

    cout << "\nFirst Matrix:\n";
    display(A);
    cout << "\nSecond Matrix:\n";
    display(B);

    cout << "\nTranspose of first matrix:\n";
    transpose(A, T);
    display(T);

    cout << "\nAddition of matrices:\n";
    add(A, B, S);
    display(S);

    cout << "\nMultiplication of matrices:\n";
    multiply(A, B, M);
    display(M);

    return 0;
}
