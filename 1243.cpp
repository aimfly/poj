#include <iostream>
using namespace std;

int result[31][31]={0};

int main() {
    result[1][0]=1;
    result[1][1]=1;
    for(int i=2;i<=30;i++){
        result[i][0]=i;
        for(int j=1;j<i;j++){
            int tmp=result[i][0];
            for(int k=1;k<i;k++)tmp+=result[k][((j-1)>k?k:(j-1))];
            result[i][j]=tmp;
        }
        result[i][i]=result[i][i-1];
    }

    int G,L;
    int number=1;

    while(cin>>G>>L){
        if(G==0&&L==0)break;
        cout<<"Case "<<number++<<": "<<result[G][L]<<endl;
    }

	return 0;
}