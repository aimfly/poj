#include<iostream>
using namespace std;

typedef unsigned char BYTE;

BYTE *src;
BYTE *dest;
BYTE num[3]={5,2,1};

void cal_mi(int c,int n)
{
	int i,j,k;
	int t;
	memset(src,0,3*c*sizeof(BYTE));
	memset(dest,0,3*c*sizeof(BYTE));
	memcpy(dest,num,3*sizeof(BYTE));
	for(i=1;i<c;++i){
		memcpy(src,dest,i*3*sizeof(BYTE));
		memset(dest,0,i*3*sizeof(BYTE));
		for(j=0;j<3;++j){
			for(k=0;k<i*3;++k)
			{
			    t=num[j]*src[k];
			    dest[k+j]+=t;
			    if(dest[k+j]/10!=0){
			    	dest[k+j+1]+=dest[k+j]/10;
			    	dest[k+j]=dest[k+j]%10;
			    }
			}
		}
	}
	memcpy(src,dest,c*3*sizeof(BYTE));
	memset(dest,0,c*3*sizeof(BYTE));
	for(i=0;i<c*3;++i){
		t=n*src[i];
		dest[i]+=t;
		if(dest[i]/10!=0){
			dest[i+1]+=dest[i]/10;
			dest[i]=dest[i]%10;
		}
	}
}

int main()
{
	char octal[1000];
	int i,j,k;
	int num;
	int len;
	BYTE *decimal;
	while(cin>>octal){
		len=strlen(octal);
		while(octal[len-1]=='0'){
			octal[len-1]=0;
			len--;
		}
		decimal=(BYTE *)malloc((len-2)*3*sizeof(BYTE));
		memset(decimal,0,(len-2)*3*sizeof(BYTE));
		src=(BYTE *)malloc((len-2)*3*sizeof(BYTE));
		dest=(BYTE *)malloc((len-2)*3*sizeof(BYTE));
		for(i=0;i<len-2;++i){
			num=octal[i+2]-'0';
			cal_mi(i+1,num);
			for(j=(i+1)*3-1;j>=0;--j){
				k=(i+1)*3-1-j;
				decimal[j]+=dest[k];
				if(decimal[j]/10!=0){
					decimal[j-1]+=decimal[j]/10;
					decimal[j]=decimal[j]%10;
				}
			}
		}
		len=(len-2)*3;
		while(0==decimal[len-1]){
			len--;
		}
		cout<<octal<<" [8] = ";
		cout<<"0.";
		for(i=0;i<len;++i){
			cout<<(char)(decimal[i]+'0');
		}
		cout<<" [10]"<<endl;
		free(decimal);
		free(src);
		free(dest);
	}
	return 0;
}