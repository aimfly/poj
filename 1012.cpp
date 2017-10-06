#include <iostream>
using namespace std;
int ansa[14]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
int main()
{
	int n=0;
	int ans=0;
	int ansfix=0;
	int remain=0;
	int killed=0;
	cin>>n;
	while(n)
	{
/*
		ans=0;
		while(1)
		{
			ans++;
			ansfix=ans;
			remain=n;
			while(1)
			{
				killed=ansfix%(n+remain);
				if(0 == killed)killed=n+remain;
				if(killed<=n)break;
				ansfix=ans-(remain-(killed-n));
				remain--;
				if(0 == remain)break;
			}
			if(0==remain)break;
		}
*/
		cout<<ansa[n]<<endl;
		cin>>n;
	}
	return 0;
}