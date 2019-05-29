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

void disp(int arr[], int n){
    for(int i=0; i<n; i++){
        cout <<arr[i]<<" ";
    }
}

void Insert(int arr[], int n){
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

void concat(int a[], int s, int e, int b[]){
    int j;
    for(int i=s, j=0; i<e; i++, j++){
        b[i]=a[j];
    }
}

int main(){
int n1, n2;
cout <<"Size for array 1 and 2: ";
cin>>n1>>n2;
int a1[n1], a2[n2], a3[n1+n2];

cout<<"Enter values for array 1: "<<endl;
Insert(a1, n1);
cout<<"Enter values for array 2: "<<endl;
Insert(a2, n2);

cout<<endl;
cout<<"Before sorting 1: "<<endl;
disp(a1,n1);
cout<<endl;
cout<<"Before sorting 2: "<<endl;
disp(a2,n2);
concat(a1, 0, n1, a3);
concat(a2, n1, n1+n2, a3);
cout<<endl;
cout<<"Before sorting 3: "<<endl;
disp(a3,n1+n2);
Partition(a3, 0, n1+n2);
cout<<endl;
cout<<"After sorting array 3: "<<endl;
disp(a3, n1+n2);
cout<<endl;

return 0;

}
