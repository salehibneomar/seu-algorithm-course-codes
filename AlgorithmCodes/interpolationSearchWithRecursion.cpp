#include <iostream>
#include <math.h>
using namespace std;

bool intpolSrc(int arr[], int low, int high, int key){

    if(low<=high && key>=arr[low] && key<=arr[high]){

        int mid = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));

        if(key == arr[mid]){
            cout <<"Found"<<endl;
        }
        else if(key<arr[mid]){
            intpolSrc(arr, low, mid-1, key);
        }
        else if(key>arr[mid]){
            intpolSrc(arr, mid+1, high, key);
        }
    }
    else{
        cout <<"Not found"<<endl;
    }


}

int main(){

    int arr[9] = {1, 2, 4, 6, 7, 10, 11, 14, 15};
    int key, low = 0, high = 8;

    cout <<"Search: "<<endl;
    cin >>key;

    intpolSrc(arr, low, high, key);

return 0;

}
