#include <bits/stdc++.h>
using namespace std;

int MergeSort(int arr[][2], int l, int r){
    int p=l;
    while(l<r){
        while(arr[l][0]<=arr[p][0]){
            l++;
        }
        while(arr[r][0]>arr[p][0]){
            r--;
        }
        if(l<r){
            swap(arr[l][0],arr[r][0]);
            swap(arr[l][1],arr[r][1]);
        }
    }

    swap(arr[p][0],arr[r][0]);
    swap(arr[p][1],arr[r][1]);
    return r;
}

void Partition(int arr[][2], int l, int r){
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
int arr[n][2];
for(int i=0; i<n; i++){
    cin>>arr[i][0];
    arr[i][1]=i+1;
}
Partition(arr,0,n-1);

cout<<"Result:"<<endl;
for(int i=0; i<n; i++){
    int y=arr[i][0]/365;
    int m=(arr[i][0]%365)/30;
    int d=(arr[i][0]%365)%30;

    cout<<y<<" "<<m<<" "<<d<<" = "<<arr[i][1]<<endl;
}


return 0;

}
