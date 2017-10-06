#include<iostream>
using namespace std;
int main(){
	int flag[10][5]={1,3,0,3,1,0,2,0,2,0,1,2,1,1,1,1,2,1,2,1,0,3,1,2,0,1,1,1,2,1,1,1,1,3,1,1,2,0,2,0,1,3,1,3,1,1,3,1,2,1};
	int m,i,j,k,t;
	char s[10];
	cin>>m>>s;
	while(m){
		for(t=0;t<5;t++){
			if(t==0||t==2||t==4){
				i=0;
				while(s[i]){
					cout<<' ';
					for(j=0;j<m;j++)if(flag[s[i]-'0'][t]==1)cout<<'-';else cout<<' ';
					cout<<' ';
					i++;
					if(s[i])cout<<' ';
				}
				cout<<endl;
			}else {
				for(j=0;j<m;j++){
					i=0;
					while(s[i]){
						if(flag[s[i]-'0'][t]%2==1)cout<<'|';else cout<<' ';
						for(k=0;k<m;k++)cout<<' ';
						if(flag[s[i]-'0'][t]>>1==1)cout<<'|';else cout<<' ';
						i++;
						if(s[i])cout<<' ';
					}
					cout<<endl;
				}
			}
		}
		cout<<' '<<endl;
		cin>>m>>s;
	}
	return 0;
}