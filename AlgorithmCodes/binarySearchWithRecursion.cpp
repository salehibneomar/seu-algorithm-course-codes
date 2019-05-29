#include <iostream>
using namespace std;

bool binSrc(int arr[], int low, int high, int key){
    int mid;
    if(low<=high){
        mid = (high+low)/2;
        if(key == arr[mid]){
            cout <<"found"<<endl;
        }
        else if(key<arr[mid]){
            binSrc(arr, low, mid-1, key);
        }
        else if(key>arr[mid]){
            binSrc(arr, mid+1, high, key);
        }
    }
    else{
        cout <<"Not found"<<endl;
    }

}

int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    int key, low = 0, high = 4;

    cout <<"Search: "<<endl;
    cin >>key;

    binSrc(arr, low, high, key);

return 0;

}
