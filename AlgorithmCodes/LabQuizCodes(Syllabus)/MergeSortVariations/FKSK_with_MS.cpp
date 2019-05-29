#include <bits/stdc++.h>
using namespace std;

void MergeSort(double arr[][3], int l, int m, int r){
    int n1=(m-l)+1, n2=r-m;
    double left[n1][3], right[n2][3];

    for(int i=0; i<n1; i++){
        for(int j=0; j<3; j++){
            left[i][j]=arr[l+i][j];
        }
    }
    for(int i=0; i<n2; i++){
        for(int j=0; j<3; j++){
            right[i][j]=arr[m+1+i][j];
        }
    }

    int L=0,R=0,K=l;
    while(L<n1 && R<n2){
        if(left[L][2]>=right[R][2]){
            int y=0;
            while(y<3){
                arr[K][y]=left[L][y];
                y++;
            }
            L++;
            K++;
        }
        else{
            int y=0;
            while(y<3){
                arr[K][y]=right[R][y];
                y++;
            }
            R++;
            K++;
        }
    }

    while(L<n1){
        int y=0;
        while(y<3){
            arr[K][y]=left[L][y];
            y++;
        }
        L++;
        K++;
    }
    while(R<n2){
        int y=0;
        while(y<3){
            arr[K][y]=right[R][y];
            y++;
        }
        R++;
        K++;
    }
}

void Divide(double arr[][3], int l, int r){
    int m;
    if(l<r){
        m=(r+l)/2;
        Divide(arr,l,m);
        Divide(arr,m+1,r);
        MergeSort(arr,l,m,r);
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
Divide(arr,0,n-1);
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
