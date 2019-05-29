#include <bits/stdc++.h>
using namespace std;

void mergeSort(int a1[], int a2[], int n1, int n2, int a3[]){
    int l=0, r=0, k=0;
    while(l<n1 && r<n2){
        if(a1[l]<=a2[r]){
            a3[k]=a1[l];
            l++;
            k++;
        }
        else{
            a3[k]=a2[r];
            r++;
            k++;
        }
    }

    while(l<n1){
        a3[k]=a1[l];
        l++;
        k++;
    }
    while(r<n2){
        a3[k]=a2[r];
        r++;
        k++;
    }

}

void disp(int a[], int n){
    for(int i=0; i<n; i++){
        cout <<a[i]<<" ";
    }
}

int main(){
int n1, n2;
cout<<"Enter size for Array 1: ";
cin>>n1;
cout<<"Enter size for Array 2: ";
cin>>n2;
int a1[n1], a2[n2], a3[n1+n2];
cout<<"Enter values for Array 1 [Sorted]:"<<endl;
for(int i=0; i<n1; i++){
    cin>>a1[i];
}
cout<<"Enter values for Array 2 [Sorted]:"<<endl;
for(int i=0; i<n2; i++){
    cin>>a2[i];
}

cout<<"Values of Array 1:"<<endl;
disp(a1, n1);
cout<<endl;
cout<<"Values of Array 1:"<<endl;
disp(a2, n2);
mergeSort(a1, a2, n1, n2, a3);
cout<<endl;
cout<<"After merging two sorted arrays:"<<endl;
disp(a3, n1+n2);
cout<<endl;

return 0;

}
