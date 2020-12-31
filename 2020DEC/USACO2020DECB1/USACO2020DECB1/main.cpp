#include"bits/stdc++.h"
using namespace std;
int main(){
    int o[8];
    for(int i = 1;i <= 7;i++){
        cin>>o[i];
    }
    sort(o+1,o+7);
    int a=o[1],b=o[2],c=0,he=o[7];
    for(int i=3;i<=4;i++){
        int zanshi = he - a -b;
        if(o[i]==zanshi){
            c=o[i];
        }
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
    return 0;
}

