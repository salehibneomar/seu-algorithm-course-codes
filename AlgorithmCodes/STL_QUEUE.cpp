#include <iostream>
#include <queue>
using namespace std;

queue <int> Q;

void disp(queue <int> Q){
    cout<<"Queue: "<<endl;
    while(!(Q.empty())){
        cout<<Q.front()<<" ";
        Q.pop();
    }

}

int main(){

    bool exit = false;
    int choice;

    while(exit!=true){
        cout<<"1. Insert 2.Delete 3.Display 4.Exit"<<endl;
        cin>>choice;

        switch(choice){

            case 1:
                int val;
                cin>>val;
                Q.push(val);
                break;
            case 2:
                Q.pop();
                break;
            case 3:
                disp(Q);
                cout<<endl;
                break;
            case 4:
                exit = true;
                break;
            default:
                cout<<"Invalid choice!"<<endl;

        }
    }

}
