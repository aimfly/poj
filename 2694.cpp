#include<iostream>
using namespace std;
int rank[14];
int hs[4];
int main(){
	int n;
	char t1,t2;
	int i;
	char hs;
	int s;
	int th;
	cin>>n;
	while(n){
		memset(rank,0,56);
		th=1;
		hs=0;
		s=0;
		int ci;
		for(i=0;i<5;i++){
			cin>>t1>>t2;
			if(hs==0)hs=t1;
			if(hs!=t1)th=0;
			if(t2<='9'&&t2>='2'){
				rank[t2-'0']++;
				ci=t2-'0';
			}
			switch(t2){
				case 'A':rank[1]++;ci=1;break;
				case 'X':rank[10]++;ci=10;break;
				case 'J':rank[11]++;ci=11;break;
				case 'Q':rank[12]++;ci=12;break;
				case 'K':rank[13]++;ci=13;
			}
			switch(rank[ci]){
				case 2:switch(s){
						case 1:s=2;break;
						case 0:s=1;break;
						case 3:s=4;
					   }
					   break;
				case 3:switch(s){
						case 2:s=4;break;
						case 1:s=3;break;
					   }
					   break;
				case 4:s=5;
			}
		}
		if(s==0){
				i=1;
				while(rank[i++]==0);
				i--;
				if(rank[i+1]&&rank[i+2]&&rank[i+3]&&rank[i+4])s=6;
				if(i==1&&rank[10]&&rank[11]&&rank[12]&&rank[13])s=6;
		}
		switch(s){
			case 0:if(th)cout<<350<<endl;
				   else  cout<<0<<endl;
				   break;
			case 1:cout<<50<<endl;break;
			case 2:cout<<100<<endl;break;
			case 3:cout<<200<<endl;break;
			case 4:cout<<500<<endl;break;
			case 5:cout<<750<<endl;break;
			case 6:if(th)cout<<1000<<endl;
				   else cout<<250<<endl;break;
		}
		n--;
	}
	return 0;
}