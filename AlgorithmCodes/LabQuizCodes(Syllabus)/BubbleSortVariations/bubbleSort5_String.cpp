#include <bits/stdc++.h>
using namespace std;

void BubbleSort(string str[], int n){
    for(int i=0; i<n-1; i++){
        bool flag = false;
        for(int j=0; j<n-i-1; j++){
            if(str[j+1][0]<str[j][0]){
                swap(str[j+1],str[j]);
                flag = true;
            }
        }
        if(flag==false){
            break;
        }
    }
}

void disp(string str[], int n){
    for(int i=0; i<n; i++){
        cout<<str[i]<<endl;
    }
}

int main(){
int n;
cout<<"Enter size: ";
cin>>n;
string str[n];
cout<<endl;
cout<<"Enter names:"<<endl;
for(int i=0; i<n; i++){
    cin>>str[i];
}
cout<<endl;
cout<<"Before sorting:"<<endl;
disp(str, n);
BubbleSort(str, n);
cout<<endl;
cout<<"After sorting:"<<endl;
disp(str, n);
cout<<endl;

return 0;

}
