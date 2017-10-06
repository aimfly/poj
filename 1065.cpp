#include<iostream>
using namespace std;
typedef struct{
	int lenth;
	int weight;
}Stick_t;

int loc(int *a,int sidx,int eidx,int num)
{
	int idx;
	if(sidx>eidx)
	{
		return -1;
	}
	idx=(sidx+eidx)/2;
	if(num>=a[idx])
	{
		if(0==idx)
		{
			return idx;
		}
		else if(num<a[idx-1])
		{
			return idx;
		}
		else
		{
			return loc(a,sidx,idx-1,num);
		}
	}
	else
	{
		return loc(a,idx+1,eidx,num);
	}
}

int cmp(void const *a, void const *b)
{
	if((*((Stick_t *)a)).lenth==(*((Stick_t *)b)).lenth)
	{
		return (*((Stick_t *)a)).weight-(*((Stick_t *)b)).weight;
	}
	else
	{
		return (*((Stick_t *)a)).lenth-(*((Stick_t *)b)).lenth;
	}
}

int main()
{
	int i;
	int idx;
	int testcnt;
	int stickcnt;
	Stick_t stick[5000];
    int val[5000]={0};
	int valcnt;
	cin>>testcnt;
	while(testcnt--)
	{
		cin>>stickcnt;
		memset(val,0,5000);
		valcnt=0;
		for(i=0;i<stickcnt;i++)
		{
			cin>>stick[i].lenth>>stick[i].weight;
		}
		qsort(stick,stickcnt,sizeof(Stick_t),cmp);
		for(i=0;i<stickcnt;i++)
		{
			idx=loc(val,0,valcnt-1,stick[i].weight);
			if(-1 == idx)
			{
				val[valcnt]=stick[i].weight;
				valcnt++;
			}
			else
			{
				val[idx]=stick[i].weight;
			}
		}
		cout<<valcnt<<endl;
	}
#if 0
	stickcnt=5000;
	for(i=0;i<stickcnt;i++)
	{
		stick[i].lenth=5000-i;
		stick[i].weight=i+1;
	}
	qsort(stick,stickcnt,sizeof(Stick_t),cmp);
	valcnt=0;
	for(i=0;i<stickcnt;i++)
	{
		idx=loc(val,0,valcnt-1,stick[i].weight);
		if(-1 == idx)
		{
			val[valcnt]=stick[i].weight;
			valcnt++;
		}
		else
		{
			val[idx]=stick[i].weight;
		}
	}
	cout<<valcnt<<endl;
#endif
	return 0;
}