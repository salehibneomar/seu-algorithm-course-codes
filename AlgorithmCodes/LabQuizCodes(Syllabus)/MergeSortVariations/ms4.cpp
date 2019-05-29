#include <iostream>
using namespace std;

void mergeSort(int arr[], int l, int m, int r){

    int n1=(m-l)+1, n2=r-m;
    int left[n1], right[n1];

    for(int i=0; i<n1; i++){
        left[i]=arr[l+i];
    }
    for(int i=0; i<n2; i++){
        right[i]=arr[m+1+i];
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
        mergeSort(arr,l,m,r);
    }
}

int main(){

int n;
cout<<"Enter size: ";
cin>>n;
int arr[n];
cout<<"Enter values: "<<endl;
for(int i=0; i<n; i++){
    cin>>arr[i];
}
divide(arr,0,n-1);
cout<<"Age:"<<endl;

for(int i=0; i<n; i++){
    int y = arr[i]/365;
    int m = (arr[i]%365)/30;
    int d = (arr[i]%365)%30;

    cout<<y<<" "<<m<<" "<<d<<endl;
}


return 0;

}
