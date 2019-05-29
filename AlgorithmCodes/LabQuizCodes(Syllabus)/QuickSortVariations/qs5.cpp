#include <bits/stdc++.h>
using namespace std;

int MergeSort(int arr[], int l, int r){
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
        p=MergeSort(arr, l, r);
        Partition(arr, l, p-1);
        Partition(arr, p+1, r);
    }
}

int main(){
int n;
cout<<"Size: ";
cin>>n;
cout<<endl;
cout<<"Enter values: "<<endl;
int arr[n];
for(int i=0; i<n; i++){
    cin>>arr[i];
}
Partition(arr,0,n-1);

cout<<"Result:"<<endl;
for(int i=0; i<n; i++){
    int y=arr[i]/365;
    int m=(arr[i]%365)/30;
    int d=(arr[i]%365)%30;

    cout<<y<<" "<<m<<" "<<d<<endl;
}


return 0;

}
