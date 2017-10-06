#include<iostream>
#include<string>
using namespace std;
struct dna{
	char *a;
	int res;
}* dnas;
int a[4],b[4];
int main(){
	int size,num;
	int i,j;
	int min,imin;
	cin>>size;
	cin>>num;
	dnas=(struct dna *)malloc(num*sizeof(struct dna));
	for(i=0;i<num;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		dnas[i].a=(char *)malloc(size*sizeof(char));
		dnas[i].res=0;
		cin>>dnas[i].a;
		for(j=0;j<size;j++){
			switch(dnas[i].a[j]){
				case 'A':a[0]++;dnas[i].res+=a[1]+a[2]+a[3];break;
				case 'C':a[1]++;dnas[i].res+=a[2]+a[3];break;
				case 'G':a[2]++;dnas[i].res+=a[3];break;
				case 'T':a[3]++;
			}
		}
	}
	for(i=0;i<num;i++){
		for(j=1,min=dnas[0].res,imin=0;j<num;j++){
			if(dnas[j].res<min){min=dnas[j].res,imin=j;}
		}
		dnas[imin].res=1000;
		cout<<dnas[imin].a<<endl;;
	}
	return 1;
}