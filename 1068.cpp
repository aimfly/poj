#include<iostream>
using namespace std;

int main()
{
	int i;
	int j;
	int testcnt;
	int numcnt;
	int P[20];
	int last_code;
	int code;
	int W[20];
	int t1[20];
	int t2[20];
	cin>>testcnt;
	while(testcnt--)
	{
		cin>>numcnt;
		for(i=0;i<numcnt;i++)
		{
			cin>>P[i];
		}
		last_code=0;
		for(i=0;i<numcnt;i++)
		{
			t1[i]=P[i]-last_code;
			t2[i]=t1[i];

			code=0;
			j=i;
			while(t2[j]==0)
			{
				code+=t1[j];
				j--;
			}
			t2[j]--;
			code+=(t1[j]-t2[j]);
			W[i]=code;
			last_code=P[i];
		}
		for(i=0;i<numcnt;i++)
		{
			cout<<W[i]<<" ";
		}
		cout<<endl;
	}
    return 0;
}