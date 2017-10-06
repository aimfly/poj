#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int T,sum;
    int sum_even;
    int sum_odd;
    int n;
    cin>>T;
    for(int i=0;i<T;i++){
       cin>>sum;
       sum_even=sum_odd=0;

       for(int j=0;j<sum;j++){
          cin>>n;
          if(j%2==1)sum_odd+=n;
          else sum_even+=n;
       }
       if(sum%2==1){
           cout<<"YES"<<endl;
       }
       else{
           if(abs(sum_even-sum_odd)>1)cout<<"NO"<<endl;
           else cout<<"YES"<<endl;
       }
    }
    return 0;
}