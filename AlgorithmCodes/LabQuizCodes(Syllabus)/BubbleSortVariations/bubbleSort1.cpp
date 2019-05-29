#include <bits/stdc++.h>
using namespace std;

void buubleSort(int arr[], int n){

    for(int i=0; i<n-1; i++){
        bool flag = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1], arr[j]);
                flag = true;
            }
        }
        if(flag!=true){
            break;
        }
    }

}

void disp(int arr[], int n){
    for(int i=0; i<n; i++){
        cout <<arr[i]<<" ";
    }
}

int main(){

int n;
cout <<"Enter size: ";
cin>>n;
int arr[n];
for(int i=0; i<n; i++){
    cin>>arr[i];
}

cout<<"Before sorting: "<<endl;
disp(arr, n);
buubleSort(arr, n);
cout<<endl;
cout<<"After sorting: "<<endl;
disp(arr, n);

return 0;
}
