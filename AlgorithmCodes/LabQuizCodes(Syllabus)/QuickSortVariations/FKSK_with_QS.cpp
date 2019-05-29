#include <bits/stdc++.h>
using namespace std;

int QuickSort(double arr[][3], int l, int r){
    int p=l;
    while(l<r){
        while(arr[l][2]>=arr[p][2]){
            l++;
        }
        while(arr[r][2]<arr[p][2]){
            r--;
        }
        if(l<r){
            swap(arr[l][0],arr[r][0]);
            swap(arr[l][1],arr[r][1]);
            swap(arr[l][2],arr[r][2]);
        }
    }
    swap(arr[p][2],arr[r][2]);
    swap(arr[p][1],arr[r][1]);
    swap(arr[p][0],arr[r][0]);

    return r;
}

void Partition(double arr[][3], int l, int r){
    int p;
    if(l<r){
        p=QuickSort(arr,l,r);
        Partition(arr,l,p-1);
        Partition(arr,p+1,r);
    }
}

int main(){

int n,W;
cout<<"How many?:"<<endl;
cin>>n;
cout<<"Max weight:"<<endl;
cin>>W;

double arr[n][3], p=0;

for(int i=0; i<n; i++){
    for(int j=0; j<2; j++){
        cin>>arr[i][j];
    }
    arr[i][2]=arr[i][0]/arr[i][1];
}
cout<<endl;
cout<<"Values: "<<endl;
Partition(arr,0,n-1);
for(int i=0; i<n; i++){
    for(int j=0; j<3; j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}

for(int i=0; i<n; i++){
    if(arr[i][1]<W){
        p=p+arr[i][0];
        W=W-arr[i][1];
    }
    else{
        p=p+(arr[i][2]*W);
        W=0;
    }
}

cout<<endl;
cout<<"Profit = "<<p<<endl;

return 0;

}
