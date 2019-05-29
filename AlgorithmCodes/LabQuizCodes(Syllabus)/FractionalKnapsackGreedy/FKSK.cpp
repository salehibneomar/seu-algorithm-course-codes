#include <bits/stdc++.h>
using namespace std;

struct List{
    double profit, weight, unitPrice;
};

bool compare(List a, List b){
    return a.unitPrice > b.unitPrice;
}

int main(){
int n, W;
double totalProfit=0;
cout<<"How many?: ";
cin>>n;
List space[n];
cout <<"Max weight?: ";
cin>>W;

for(int i=0; i<n; i++){
    cout <<"Profit of item: "<<i+1<<endl;
    cin>>space[i].profit;
    cout <<"Weight of item: "<<i+1<<endl;
    cin>>space[i].weight;
    space[i].unitPrice = space[i].profit/space[i].weight;
}

cout<<endl;
cout <<"Before sorting: "<<endl;
for(int i=0; i<n; i++){
    cout <<"Profit = "<<space[i].profit
         <<", Weight = "<<space[i].weight
         <<", Unit price = "<<space[i].unitPrice
         <<endl;
}

sort(space, space+n, compare);

cout<<endl;
cout <<"After sorting: "<<endl;
for(int i=0; i<n; i++){
    cout <<"Profit = "<<space[i].profit
         <<", Weight = "<<space[i].weight
         <<", Unit price = "<<fixed<<setprecision(2)<<space[i].unitPrice
         <<endl;
}

for(int i=0; i<n; i++){
    if(space[i].weight<W){
        totalProfit = totalProfit+space[i].profit;
        W = W-space[i].weight;
    }
    else{
        totalProfit = totalProfit+(W*space[i].unitPrice);
        W=0;
    }
}
cout<<endl;
cout<<"Total profit = "<<fixed<<setprecision(2)<<totalProfit<<endl;

return 0;

}
