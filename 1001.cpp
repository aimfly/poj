#include <iostream>
using namespace std;
void js(char *t1,char *t2,int a);
int main(){
	char t1[125];
	char t2[125];
	char s[7];
	int n;
	int a;
	int i,m,xs,j;
	char c;
	while(cin>>s>>n){
		a=0;
		xs=j=0;
		memset(t1,-1,125);
		for(i=5;s[i]=='0';i--);
		m=i;
		int t=0;
		while(i>=0){			
			if(s[i]!='.')t1[t++]=s[i]-'0';
			else xs=j;
			if(s[m-i]!='.')a=a*10+s[m-i]-'0';
			i--;j++;
		}
		m=n;
		for(;m>1;m--){
			js(t1,t2,a);
			memcpy(t1,t2,125);
		}
		for(i=124;t1[i]==-1;i--);
		if(i+1<=n*xs){
			cout<<'.';
			for(j=1;j<=n*xs-i-1;j++)cout<<0;
		}else {
			while(i>=n*xs){
				c=t1[i--]+'0';
				cout<<c;
			}
			if(n*xs!=0)cout<<'.';
		}
		while(i>=0){
			c=t1[i--]+'0';
			cout<<c;
		}
		cout<<endl;
	}
	return 0;
}
void js(char *t1,char *t2,int a){
	int i,j;
	long t;
	int m,c;
	memset(t2,0,125);
	i=j=0;
	while(t1[i]!=-1){
		t=t1[i]*a;
		c=j;
		while(t!=0){
			m=t%10;
			t=t/10;
			t2[c++]+=m;
		}
		j++;i++;
	}
	i=0;
	while(i<124){
		t2[i+1]+=t2[i]/10;
		t2[i]=t2[i]%10;
		i++;
	}
	for(i=124;t2[i]==0;i--)t2[i]=-1;
}