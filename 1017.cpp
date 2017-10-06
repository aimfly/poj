#include<iostream>
using namespace std;
int a[6];
int main(){
	int f,i,ans,t;
	while(1){
		ans=0;
		for(f=0,i=0;i<6;i++){
			cin>>a[i];
			f+=a[i];
		}
		if(!f)break;
		ans+=a[5];
		ans+=a[4];
		a[0]-=a[4]*11;
		if(a[0]<0)a[0]=0;
		ans+=a[3];
		a[1]-=a[3]*5;
		if(a[1]<0){
			a[0]+=a[1]*4;
			if(a[0]<0)a[0]=0;
			a[1]=0;
		}
		ans+=a[2]/4;
		if(t=a[2]%4){
			ans++;
			switch(t){
				case 1:
					a[1]-=5;
					if(a[1]<0){
						a[0]+=a[1]*4;
						if(a[0]<0)a[0]=0;
						a[1]=0;
					}
					a[0]-=7;
					if(a[0]<0)a[0]=0;
					break;
				case 2:
					a[1]-=3;
					if(a[1]<0){
						a[0]+=a[1]*4;
						if(a[0]<0)a[0]=0;
						a[1]=0;
					}
					a[0]-=6;
					if(a[0]<0)a[0]=0;
					break;
				case 3:
					a[1]-=1;
					if(a[1]<0){
						a[0]+=a[1]*4;
						if(a[0]<0)a[0]=0;
						a[1]=0;
					}
					a[0]-=5;
					if(a[0]<0)a[0]=0;
					break;
			}
			
		}
		ans+=a[1]/9;
		if(t=a[1]%9){
			ans++;
			a[0]-=36-t*4;
			if(a[0]<0)a[0]=0;
		}
		ans+=a[0]/36;
		if(a[0]%36)ans++;
		cout<<ans<<endl;
	}
	return 0;
}