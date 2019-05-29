#include <bits/stdc++.h>
using namespace std;

void mergeSort(int arr[], int l, int m, int r){
    int n1 = (m-l)+1;
    int n2 = r-m;
    int left[n1], right[n2];

    for(int i=0; i<n1; i++){
        left[i] = arr[l+i];
    }
    for(int i=0; i<n1; i++){
        right[i] = arr[m+i+1];
    }

    int L=0, R=0, K=l;

    while(L<n1 && R<n2){
        if(left[L]<=right[R]){
            arr[K]=left[L];
            K++;
            L++;
        }
        else{
            arr[K]=right[R];
            K++;
            R++;
        }
    }

    while(L<n1){
        arr[K]=left[L];
        K++;
        L++;
    }
    while(R<n2){
        arr[K]=right[R];
        K++;
        R++;
    }

}

void divide(int arr[], int l, int r){
    int m;
    if(l<r){
        m = (r+l)/2;
        divide(arr,l,m);
        divide(arr,m+1,r);
        mergeSort(arr,l,m,r);
    }
}

void disp(int arr[], int n){
    for(int i=0; i<n; i++){
        cout <<arr[i]<<" ";
    }
}

int main(){
int n;
cout<<"Size: ";
cin>>n;
int arr[n];
cout<<"Enter array values:"<<endl;
for(int i=0; i<n; i++){
    cin>>arr[i];
}

cout<<endl;
cout<<"Before sorting:"<<endl;
disp(arr, n);
cout<<endl;
divide(arr,0, n-1);
cout<<"After sorting:"<<endl;
disp(arr, n);

return 0;

}
