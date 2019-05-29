#include <iostream>
using namespace std;
int main(){

    int arr[9] = {1, 2, 4, 6, 7, 10, 11, 14, 15};
    int key, low = 0, high = 8;

    cout <<"Search: "<<endl;
    cin >>key;
    int flag = 0;
    while(low<=high && key>=arr[low] && key<=arr[high]){
        int mid = low+(((double)((high-low)/(arr[high]-arr[low])))*(key-arr[low]));
        if(key == arr[mid]){
            cout <<"Found"<<endl;
            flag = 1;
            break;
        }
        else if(key<arr[mid]){
            high = mid-1;
        }
        else if(key>arr[mid]){
            low = mid+1;
        }
    }

    if(flag != 1){
        cout <<"Not found"<<endl;
    }

return 0;

}
