#include<iostream>
using namespace std;

struct list_t{
	int height;
	int i;
	int j;
};

int maxlen=0;

int heigth[101][101];
int ans[101][101];
int row;
int colume;


int calculate(int i,int j)
{
	int local_max=1;
	int t;
    if(ans[i][j]!=0){
        return ans[i][j];
    }
    if(i>0&&heigth[i-1][j]>heigth[i][j]){
        t=calculate(i-1,j)+1;
        if(t>local_max)local_max=t;
    }
    if(j>0&&heigth[i][j-1]>heigth[i][j]){
        t=calculate(i,j-1)+1;
        if(t>local_max)local_max=t;
    }
    if(i<row-1&&heigth[i+1][j]>heigth[i][j]){
        t=calculate(i+1,j)+1;
        if(t>local_max)local_max=t;
    }
    if(j<colume-1&&heigth[i][j+1]>heigth[i][j]){
        t=calculate(i,j+1)+1;
        if(t>local_max)local_max=t;
    }
    ans[i][j]=local_max;
    if(ans[i][j]>maxlen)maxlen=ans[i][j];
    return ans[i][j];
}

int main()
{
	int i,j;
	
    memset(heigth,0,sizeof(heigth));
    memset(ans,0,sizeof(ans));
	cin>>row>>colume;
	
	for(i=0;i<row;i++){
		for(j=0;j<colume;j++){
			cin>>heigth[i][j];
		}
	}
	
	for(i=0;i<row;i++){
		for(j=0;j<colume;j++){
			if(0==ans[i][j]){
				calculate(i,j);
			}
		}
	}
	
    cout<<maxlen<<endl;
    
	return 0;
}