#include <iostream>
using namespace std;


void data(int** arr, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << "Enter the number: ";
            cin >> arr[i][j];
        }
    }
    cout << "Data entered successfully" << endl;
}

void show(int** arr, int n, int m) {
    cout << "The matrix is: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;

    int** arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    data(arr, n, m);

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                count++;
            }
        }
    }

    if(count > (n * m) / 2) {
        cout << "The given matrix is a sparse matrix" << endl;
    } else {
        cout << "The given matrix is not a sparse matrix" << endl;
    }

    show(arr, n, m);

    for(int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
