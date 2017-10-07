#include<iostream>
using namespace std;

int flag[101][101];


void cal_flag(int line)
{
	int i,j;
	memcpy(&flag[line][0],&flag[line-1][0],101*sizeof(int));
	i=1;
	j=line*i;
	while(j<101){
		flag[line][j]=!flag[line][j];
		i++;
		j=line*i;
	}
	flag[line][0]=0;
	for(i=1;i<line+1;++i){
		flag[line][0]+=flag[line][i];
	}
}

int main()
{
	int i;
	int n;
	for(i=1;i<101;++i){
		flag[1][i]=1;
	}
	for(i=2;i<101;++i){
		cal_flag(i);
	}
	cin>>n;
	while(n--){
		cin>>i;
		cout<<flag[i][0]<<endl;
	}
	return 0;
}