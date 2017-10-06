#include <iostream>
using namespace std;
struct region_t{
	short count;
	short town[250];
}region[201];

short town[251][251][2];

short minroad[31][201];
int queue_work[300];
int queue_res[300];
int queue_cnt;
int region_cnt;
int town_cnt;
int member_cnt;
int member_town[30];

void cal_min(int ci)
{
	int i,j;
	int cur;
	int road;
	int town1;
	int town2;
	int tn;
	
	tn=member_town[ci];
	
	for(i=1;i<town_cnt+1;++i)
	{
		if(town[tn][i][0]!=0)
		{
			if(0==minroad[ci][town[tn][i][0]])
			{
				minroad[ci][town[tn][i][0]]=1;
				queue_res[queue_cnt++]=town[tn][i][0];
			}
			if(0==minroad[ci][town[tn][i][1]])
			{
				minroad[ci][town[tn][i][1]]=1;
				queue_res[queue_cnt++]=town[tn][i][1];
			}
		}
	}
	road=1;
	while(queue_cnt!=0)
	{
		road++;
		memcpy(queue_work,queue_res,sizeof(queue_res));
		i=queue_cnt-1;
		queue_cnt=0;
		for(;i>-1;--i)
		{
			cur=queue_work[i];
			for(j=0;j<region[cur].count;++j)
			{
				town1=region[cur].town[j];
				if(j>0){
					town2=region[cur].town[j-1];
				}
				else{
					town2=region[cur].town[region[cur].count-1];
				}
			    if(cur==town[town1][town2][0])
				{
					if(0==minroad[ci][town[town1][town2][1]])
					{
						minroad[ci][town[town1][town2][1]]=road;
						queue_res[queue_cnt++]=town[town1][town2][1];
					}
				}
				else{
					if(0==minroad[ci][town[town1][town2][0]])
					{
						minroad[ci][town[town1][town2][0]]=road;
						queue_res[queue_cnt++]=town[town1][town2][0];
					}
				}
			}
		}
	}
}
void filltown(int i,int j,int n)
{
	if(0 == town[i][j][0]){
		town[i][j][0]=n;
		town[j][i][0]=n;
	}
	else{
		town[i][j][1]=n;
		town[j][i][1]=n;
	}
}

int main()
{
	int i=0,j=0;
	short min=-1;
	short t;
	cin>>region_cnt;
	cin>>town_cnt;
	cin>>member_cnt;
	
	for(i=0;i<member_cnt;++i){
		cin>>member_town[i];
	}
	for(i=1;i<region_cnt+1;++i){
		cin>>region[i].count;
		for(j=0;j<region[i].count;++j){
			cin>>region[i].town[j];
			if(j>0){
				filltown(region[i].town[j],region[i].town[j-1],i);
			}
		}
		filltown(region[i].town[0],region[i].town[j-1],i);
	}
	for(i=0;i<member_cnt;++i){
		cal_min(i);
	}
	for(i=1;i<region_cnt+1;++i){
		t=0;
		for(j=0;j<member_cnt;j++){
			t+=minroad[j][i]-1;
		}
		if(-1 == min){
			min=t;
		}
		else if(t<min){
			min=t;
		}
	}
	cout<<min<<endl;
	return 0;
}