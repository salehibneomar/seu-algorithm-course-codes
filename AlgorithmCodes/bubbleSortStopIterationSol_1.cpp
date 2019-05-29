#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int n;
    cout <<"Enter size: ";
    cin >>n;
    int arr[n];

    cout <<"Enter values: "<<endl;
    for(int i=0; i<n; i++){
        cin >>arr[i];
    }

    bool flag;

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }

        cout <<endl;
        cout <<"Iteration: "<<i+1<<endl;
        for(int i=0; i<n; i++){
            cout <<arr[i]<<" ";
        }
        cout <<endl;
    }


    cout <<endl;
    cout <<"After sorting values [ASC]: "<<endl;
    for(int i=0; i<n; i++){
        cout <<arr[i]<<" ";
    }
    cout <<endl;

return 0;

}
