#include<iostream>
using namespace std;

int value_table[5][5]={5,-1,-2,-1,-3,
                       -1,5,-3,-2,-4,
					   -2,-3,5,-2,-2,
					   -1,-2,-2,5,-1,
                       -3,-4,-2,-1,0};
int a[101][101];
int gene1[101];
int gene2[101];

int getgene(int *gene,int cnt)
{
	int i;
	char tchr;
    for(i=1;i<=cnt;)
	{
		cin>>tchr;
		switch(tchr)
		{
			case 'A':gene[i++]=0;
					     break;
			case 'C':gene[i++]=1;
					     break;
			case 'G':gene[i++]=2;
					     break;
			case 'T':gene[i++]=3;
					     break;
			default :  ;
		}
	}
	return 0;
}

int main()
{
	int test_num;
	int g1_len;
	int g2_len;
	int i,j;
	int t,max;
    cin>>test_num;
	while(test_num--)
	{
		memset(gene1,0,sizeof(gene1));
		memset(gene2,0,sizeof(gene2));
		memset(a,0,sizeof(a));
        gene1[0]=4;
		gene2[0]=4;
		cin>>g1_len;
		getgene(gene1,g1_len);
		cin>>g2_len;
		getgene(gene2,g2_len);
        a[0][0]=0;
        for(i=1;i<=g1_len;i++)
		{
			a[0][i]=a[0][i-1]+value_table[gene2[0]][gene1[i]];
		}
		for(i=1;i<=g2_len;i++)
		{
			a[i][0]=a[i-1][0]+value_table[gene2[i]][gene1[0]];
		}
        for(i=1;i<=g2_len;i++)
		{
			for(j=1;j<=g1_len;j++)
			{
				max=a[i-1][j-1]+value_table[gene2[i]][gene1[j]];
                t=a[i-1][j]+value_table[gene2[i]][4];
				if(max<t)max=t;
				t=a[i][j-1]+value_table[gene1[j]][4];
				if(max<t)max=t;
				a[i][j]=max;
			}
		}
		cout<<a[g2_len][g1_len]<<endl;
	}
    return 0;
}