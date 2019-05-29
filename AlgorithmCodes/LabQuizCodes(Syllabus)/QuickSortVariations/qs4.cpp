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
        p=MergeSort(arr,l,r);
        Partition(arr,l,p-1);
        Partition(arr,p+1,r);
    }
}

void convert(int a2d[][4], int arr[], int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp=((a2d[j][0]*365)+(a2d[j][1]*30)+a2d[j][2]);
            if(arr[i]==temp){
                int k=0;
                while(k<4){
                    swap(a2d[i][k],a2d[j][k]);
                    k++;
                }
            }
        }
    }
}

int main(){
int n;
cout<<"How many?: ";
cin>>n;
int a2d[n][4], arr[n], temp;
cout<<"Enter values: "<<endl;
for(int i=0; i<n; i++){
    for(int j=0; j<3; j++){
        cin>>a2d[i][j];
    }
    a2d[i][3]=i+1;
    temp=((a2d[i][0]*365)+(a2d[i][1]*30)+a2d[i][2]);
    arr[i]=temp;
}

Partition(arr, 0, n-1);
convert(a2d, arr, n);
cout<<endl;
cout<<"Values: "<<endl;
for(int i=0; i<n; i++){
    for(int j=0; j<3; j++){
        cout <<a2d[i][j]<<" ";
    }
    cout<<"= "<<a2d[i][3];
    cout<<endl;
}

return 0;

}
