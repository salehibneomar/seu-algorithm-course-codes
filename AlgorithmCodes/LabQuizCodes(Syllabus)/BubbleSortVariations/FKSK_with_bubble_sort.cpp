#include <bits/stdc++.h>
using namespace std;


void BubbleSort(double arr[][3], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j+1][2]>arr[j][2]){
                swap(arr[j+1][0],arr[j][0]);
                swap(arr[j+1][1],arr[j][1]);
                swap(arr[j+1][2],arr[j][2]);
            }
        }
    }
}

int main(){
int n, W;
cout<<"How many?:"<<endl;;
cin>>n;
cout<<"Max weight:"<<endl;
cin>>W;
double arr[n][3], p=0;
for(int i=0; i<n; i++){
    cout<<"Enter profit for: "<<i+1<<endl;
    cin>>arr[i][0];
    cout<<"Enter weight for: "<<i+1<<endl;
    cin>>arr[i][1];
    arr[i][2]=arr[i][0]/arr[i][1];
}
BubbleSort(arr, n);
cout<<"After sorting:"<<endl;
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
cout<<"Profit = "<<p;
cout<<endl;

return 0;

}
