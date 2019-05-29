#include <bits/stdc++.h>
using namespace std;

int QuickSort(int arr[], int l, int r){
    int p=l;

    while(l<r){
        while(arr[l]<=arr[p]){
            l++;
        }
        while(arr[r]>arr[p]){
            r--;
        }
        if(l<r){
            swap(arr[l],arr[r]);
        }
    }

    swap(arr[p],arr[r]);

    return r;
}


void Partition(int arr[], int l, int r){
    int p;
    if(l<r){
        p = QuickSort(arr,l,r);
        Partition(arr,l,p-1);
        Partition(arr,p+1,r);
    }
}

void disp(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
int n;
cout<<"Size: ";
cin>>n;

int arr[n];
cout<<"Enter values:"<<endl;
for(int i=0; i<n; i++){
    cin>>arr[i];
}

cout<<"Before sorting: "<<endl;
disp(arr, n);
Partition(arr, 0, n-1);
cout<<endl;
cout<<"After sorting: "<<endl;
disp(arr, n);


return 0;

}
