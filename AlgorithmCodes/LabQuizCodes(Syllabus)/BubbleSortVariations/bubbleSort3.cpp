
#include <bits/stdc++.h>
using namespace std;

void buubleSort(int arr[], int n){

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

void disp(int a2d[][3], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cout<<a2d[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

int n;
cout <<"Enter size: ";
cin>>n;
int arr[n], a2d[n][3];
for(int i=0; i<n; i++){
    cin>>arr[i];
}

buubleSort(arr, n);

for(int i=0; i<n; i++){
    int y=arr[i]/365;
    int m=arr[i]%365/30;
    int d=arr[i]%365%30;

        a2d[i][0] = y;
        a2d[i][1] = m;
        a2d[i][2] = d;
}
cout <<endl;
disp(a2d, n);

return 0;
}
