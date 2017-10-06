#include <iostream>
#include<iomanip>
#include<map>
using namespace std;

int V[300];
int minDis[300][300];
inline int calculateDis(int v1,int v2){
    if(v1>v2)swap(v1,v2);
    return V[v2]-V[v1];
}

void calculateMin(int start, int end){
    for(int i=start;i<=end;i++){
        int sum=0;
        for(int j=0;i-j>=0 && i+j<=end;j++){
            sum+=calculateDis(i-j,i)+calculateDis(i,i+j);
            minDis[i-j][i+j]=sum;
            if(i+j+1<=end){
                minDis[i-j][i+j+1]=sum+calculateDis(i,i+j+1);
            }
        }
    }
}


int calculate(int v,int p)
{
    int result[p][v];
    for(int i=0;i<v;i++){
        result[0][i]=minDis[0][i];
    }
    for(int i=1;i<p;i++){
        for(int j=i;j<v;j++){
            result[i][j]=300*10000;
            for(int k=i-1;k<j;k++){
                int tmp= result[i-1][k] + minDis[k+1][j];
                if(tmp<result[i][j]) result[i][j]=tmp;
            }
        }
    }
    return result[p-1][v-1];
}

int main() {

	int v,p;
	cin>>v>>p;
	for(int i=0;i<v;i++){
	    cin>>V[i];
	}

	calculateMin(0,v-1);


    cout<<calculate(v,p)<<endl;

	return 0;
}