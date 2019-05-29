#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

void mergesort(int a[], int low, int middle, int high){

    int s1, s2;
    s1 = (middle-low)+1;
    s2 = (high-middle);
    int left[s1], right[s2];

        for(int i=0; i<s1; i++){
            left[i] = a[low+i];
        }
        for(int i=0; i<s1; i++){
            right[i] = a[middle+i+1];
        }

    int l=0, r=0, k=low;

        while(l<s1 && r<s2){
            if(left[l]<=right[r]){
                a[k] = left[l];
                    l++;
                        k++;
            }
            else{
                a[k] = right[r];
                    r++;
                        k++;
            }
        }


        while(l<s1){
            a[k] = left[l];
                l++;
                    k++;
        }
        while(r<s1){
            a[k] = right[r];
                r++;
                    k++;
        }

}


void divide(int a[], int low, int high){
    int mid;
    if(low<high){
         mid = floor((high+low)/2);
            divide(a, low, mid);
                divide(a, mid+1, high);
                    mergesort(a, low, mid, high);
    }

}


void change(int a2d[][4], int a[], int high){
    int x=0, y, temp = 0;
    for(int i=0; i<high; i++){
        for(int j=0; j<high; j++){
            temp = ((a2d[j][x]*365) + (a2d[j][x+1]*30) + a2d[j][x+2]);
            if(a[i] == temp && a2d[i][3]<a2d[j][3]){
               y=0;
                while(y<4){
                    swap(a2d[i][y], a2d[j][y]);
                    y++;
                }

                break;
            }
        }
    }

}

void print(int a2d[][4], int high){
    for(int i=0; i<high; i++){
            for(int j=0; j<3; j++){
                cout<<a2d[i][j]<<" ";
        }
        cout <<" = "<<a2d[i][3];
        cout <<endl;
    }

}


int main(){

    int row;
    cout <<"How many record do you want?: ";
    cin >>row;
    int arr2d[row][4];

    cout <<endl;
    cout <<"Enter full age [Years/Months/Days]: "<<endl;

    for(int i=0; i<row; i++){
        cout <<"For person: "<<i+1<<endl;
            for(int j=0; j<3; j++){
                cin >>arr2d[i][j];
                    arr2d[i][3] = i+1;
        }
    }

    cout <<endl;
    cout <<"Here are the data before sorting:"<<endl;
    print(arr2d, row);


    int arr1d[row], temp1 = 0;

    for(int i=0; i<row; i++){
        for(int j=0; j<1; j++){
            temp1 = ((arr2d[i][j]*365) + (arr2d[i][j+1]*30) + arr2d[i][j+2]);
        }
            arr1d[i] = temp1;
    }


    divide(arr1d, 0, row-1);
    change(arr2d, arr1d, row);
    cout <<endl;
    cout <<"Here are the data after sorting:"<<endl;
    print(arr2d, row);


return 0;

}
