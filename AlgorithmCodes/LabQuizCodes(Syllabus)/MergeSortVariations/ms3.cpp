#include <bits/stdc++.h>
using namespace std;

void mergeSort(int arr[], int l, int m, int r){

    int n1=(m-l)+1, n2=r-m;
    int left[n1], right[n2];

    for(int i=0; i<n1; i++){
        left[i]=arr[l+i];
    }
    for(int i=0; i<n2; i++){
        right[i]=arr[m+i+1];
    }

    int L=0, R=0, K=l;

    while(L<n1 && R<n2){
        if(left[L]<=right[R]){
            arr[K]=left[L];
            L++;
            K++;
        }
        else{
            arr[K]=right[R];
            R++;
            K++;
        }
    }

    while(L<n1){
        arr[K]=left[L];
        L++;
        K++;
    }
    while(R<n2){
        arr[K]=right[R];
        R++;
        K++;
    }

}

void divide(int arr[], int l, int r){
    int m;
    if(l<r){
        m=(r+l)/2;
        divide(arr,l,m);
        divide(arr,m+1,r);
        mergeSort(arr, l, m, r);
    }
}

void disp(int a2d[][4], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cout<<a2d[i][j]<<" ";
        }
        cout<<"= "<<a2d[i][3];
        cout<<endl;
    }
}

void convert(int a2d[][4], int arr[], int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp = ((a2d[j][0]*365)+(a2d[j][1]*30)+a2d[j][2]);
            if(arr[i]==temp){
                int k=0;
                while(k<4){
                    swap(a2d[i][k], a2d[j][k]);
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

for(int i=0; i<n; i++){
    cout<<"Enter for person "<<i+1<<endl;
    for(int j=0; j<3; j++){
        cin>>a2d[i][j];
    }
    a2d[i][3]=i+1;
    temp = ((a2d[i][0]*365)+(a2d[i][1]*30)+a2d[i][2]);
    arr[i]=temp;
}

cout<<endl;
cout<<"Values: "<<endl;
disp(a2d, n);

divide(arr,0,n-1);
convert(a2d, arr, n);

cout<<endl;
cout<<"Values: [Sorted]"<<endl;
disp(a2d, n);

return 0;

}
