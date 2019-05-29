#include <iostream>
using namespace std;

void mergeSort(int arr[][2], int l, int m, int r){

    int n1=(m-l)+1, n2=r-m;
    int left[n1][2], right[n1][2];

    for(int i=0; i<n1; i++){
        left[i][0]=arr[l+i][0];
        left[i][1]=arr[l+i][1];
    }
    for(int i=0; i<n2; i++){
        right[i][0]=arr[m+1+i][0];
        right[i][1]=arr[m+1+i][1];
    }

    int L=0, R=0, K=l;

    while(L<n1 && R<n2){
        if(left[L][0]<=right[R][0]){
            arr[K][0]=left[L][0];
            arr[K][1]=left[L][1];
            L++;
            K++;
        }
        else{
            arr[K][0]=right[R][0];
            arr[K][1]=right[R][1];
            R++;
            K++;
        }
    }

    while(L<n1){
        arr[K][0]=left[L][0];
        arr[K][1]=left[L][1];
        L++;
        K++;
    }
    while(R<n2){
        arr[K][0]=right[R][0];
        arr[K][1]=right[R][1];
        R++;
        K++;
    }

}

void divide(int arr[][2], int l, int r){
    int m;
    if(l<r){
        m=(r+l)/2;
        divide(arr,l,m);
        divide(arr,m+1,r);
        mergeSort(arr,l,m,r);
    }
}

int main(){

int n;
cout<<"Enter size: ";
cin>>n;
int arr[n][2];
cout<<"Enter values: "<<endl;
for(int i=0; i<n; i++){
    cin>>arr[i][0];
    arr[i][1]=i+1;
}
divide(arr,0,n-1);
cout<<"Age:"<<endl;

for(int i=0; i<n; i++){
    int y = arr[i][0]/365;
    int m = (arr[i][0]%365)/30;
    int d = (arr[i][0]%365)%30;

    cout<<y<<" "<<m<<" "<<d<<" = "<<arr[i][1]<<endl;
}


return 0;

}
