#include <bits/stdc++.h>
using namespace std;

void bubleSort(int arr[], int n){

    for(int i=0; i<n-1; i++){
        bool flag = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1], arr[j]);
                flag = true;
            }
        }
        if(flag!=true){
            break;
        }
    }

}

void disp(int a2d[][5], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            cout <<a2d[i][j]<<" ";
        }
        cout <<"= "<<a2d[i][4];
        cout<<endl;
    }
}

void OneD_To_TwoD(int arr[], int n, int a2d[][5]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp=((a2d[j][0]*365*24)+(a2d[j][1]*30*24)+(a2d[j][2]*24)+a2d[j][3]);
            if(arr[i]==temp){
                int k=0;
                while(k<5){
                    swap(a2d[i][k], a2d[j][k]);
                    k++;
                }
            }
        }
    }
}

int main(){

int n;
cout <<"How many entries?: ";
cin>>n;
int a2d[n][5], arr[n];
for(int i=0; i<n; i++){
    int temp=0;
    for(int j=0; j<4; j++){
        cin>>a2d[i][j];
        a2d[i][4]=i+1;
    }
    temp=((a2d[i][0]*365*24)+(a2d[i][1]*30*24)+(a2d[i][2]*24)+a2d[i][3]);
    arr[i]=temp;
}

cout<<endl;
cout<<"Before sorting: "<<endl;
disp(a2d, n);
bubleSort(arr, n);
OneD_To_TwoD(arr, n, a2d);
cout<<endl;
cout <<"After sorting: "<<endl;
disp(a2d, n);

return 0;
}

