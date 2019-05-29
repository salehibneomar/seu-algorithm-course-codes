
#include <bits/stdc++.h>
using namespace std;

void buubleSort(int a1[][2], int n){

    for(int i=0; i<n-1; i++){
        bool flag = false;
        for(int j=0; j<n-i-1; j++){
            if(a1[j+1][0]<a1[j][0]){
                swap(a1[j+1][0], a1[j][0]);
                swap(a1[j+1][1], a1[j][1]);
                flag = true;
            }
        }
        if(flag!=true){
            break;
        }
    }

}

void disp(int a2[][4], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cout<<a2[i][j]<<" ";
        }
        cout<<a2[i][3]<<"= ";
        cout<<endl;
    }
}

int main(){

int n;
cout <<"Enter size: ";
cin>>n;
int a1[n][2], a2[n][4], a3[3];
for(int i=0; i<n; i++){
    cin>>a1[i][0];
    a1[i][1]=i+1;
}

buubleSort(a1, n);

for(int i=0; i<n; i++){
    int y=a1[i][0]/365;
    int m=a1[i][0]%365/30;
    int d=a1[i][0]%365%30;

        a2[i][0] = y;
        a2[i][1] = m;
        a2[i][2] = d;
        a2[i][3] = a1[i][1];
}
cout <<endl;
disp(a2, n);

return 0;
}

