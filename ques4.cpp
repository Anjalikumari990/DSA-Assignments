//QUES 4(i)
int main(){
	int n;
	cout<<"Enter how many elements you want to add: ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter the elements: \n";
	for(int i=0;i<n;i++){
		cin>>arr[n-1-i];
	}
	cout<<"reversed array: ";
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
	
}

// QUES 4(ii)
int main() {
    int m, n;
    int i, j;

    cout << "Enter the rows and columns for the first matrix: ";
    cin >> m >> n;

    cout << "Enter the rows and columns for the second matrix: ";
    cin >> i >> j;

   
    if (n != i) {
        cout << "Multiplication cannot be performed.\n";
        return 1; 
    }

    int arr1[m][n];
    int arr2[i][j];
    int arr3[m][j]; 

    cout << "\nEnter elements for the first matrix:\n";
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            cin >> arr1[row][col];
        }
    }

    cout << "\nEnter elements for the second matrix:\n";
    for (int row = 0; row < i; row++) {
        for (int col = 0; col < j; col++) {
            cin >> arr2[row][col];
        }
    }

    for (int rowA = 0; rowA < m; rowA++) {
        for (int colB = 0; colB < j; colB++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += arr1[rowA][k] * arr2[k][colB];
            }
            arr3[rowA][colB] = sum;
        }
    }

    cout << "\nmatrix after multiplication:\n";
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < j; col++) {
            cout << arr3[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}

// QUES 4(iii)
int main(){
	int i,j;
	cout<<"Enter number rows and cols: \n";
	cin>>i>>j;
	cout<<"Enter the values: \n";
	int arr[i][j];
	for(int row=0;row<i;row++){
		for(int col=0;col<j;col++){
			cin>>arr[row][col];
		}
	}
	cout<<"Transpose of the matrix is: \n";
	for(int row=0;row<i;row++){
		for(int col=0;col<j;col++){
			cout<<arr[col][row]<< " ";
		}
		cout <<"\n";
	}
	return 0;
}
