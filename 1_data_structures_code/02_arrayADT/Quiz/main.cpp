#include <iostream>
using namespace std;

void accept(int *arr, int n) { for(int i=0; i<n; i++) cin >> arr[i]; }
int sum(int *arr, int n) { int s=0; for(int i=0; i<n; i++) s+=arr[i]; return s; }
int minEl(int *arr, int n) { int m=arr[0]; for(int i=1; i<n; i++) if(arr[i]<m) m=arr[i]; return m; }
int maxEl(int *arr, int n) { int m=arr[0]; for(int i=1; i<n; i++) if(arr[i]>m) m=arr[i]; return m; }
void display(int *arr, int n) { 
    cout << "Sum: " << sum(arr,n) << ", Min: " << minEl(arr,n) << ", Max: " << maxEl(arr,n) << endl; 
}

int main() {
    int n; 
    cout << "Enter n: ";
    cin >> n;
    int *arr = new int[n];
    
    cout << "Enter elements: ";
    accept(arr, n);
    display(arr, n);
    
    delete[] arr;
    return 0;
}
