#include <iostream>
using namespace std;

int sorting(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int t= arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
    cout<<"sorting done"<<endl;
    return 0;
}

int data(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<"enter the number: ";
        cin>>arr[i];
    }
    cout<<"data entered sucessfully"<<endl;
    return 0;
}

int main(){
    int n;
    cout<<"enter the length of array: ";
    cin>>n;
    int arr[n];
    data(arr, n);
    sorting(arr, n);

    int c;
    cout<<"enter the number to be checked: ";
    cin>>c;

    int s = 0;
    int e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==c){
            cout<<"the number was found at index: "<<mid<<endl;
            return 0;
        }
        else if(arr[mid]>c){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    return 0;
}