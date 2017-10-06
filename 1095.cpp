#include<iostream>
using namespace std;

typedef struct{
	int mincode;
	int num;
	int a[50];
}node_t;

node_t node[51];
int node_cnt=0;

int printcode(int code)
{
	int i;
	int j;
	int l;
	int r;
	int lcode;
	int rcode;
    if(1==code)
	{
		cout<<'X';
		return 0;
	}
	for(i=2;i<node_cnt;i++)
	{
		if(code<node[i].mincode)
		{
			break;
		}
	}
	i--;
	code=code-node[i].mincode;
    for(j=0;code>=node[i].a[j];j++)
	{
		code=code-node[i].a[j];
	}
	l=j;
	r=i-j-1;
	lcode=code/node[r].num+node[l].mincode;
	rcode=code%node[r].num+node[r].mincode;
	if(lcode!=0)
	{
		cout<<'(';
		printcode(lcode);
		cout<<')';
	}
	cout<<'X';
	if(rcode!=0)
	{
		cout<<'(';
		printcode(rcode);
		cout<<')';
	}
	return 0;
}

int main()
{
	
	int i,j;
	int code;
	memset(node,0,sizeof(node));
    node[0].num=1;
	node[0].mincode=0;
	node[1].num=1;
	node[1].mincode=1;
    node_cnt=2;
    for(i=2;node[i-1].mincode<500000000;i++)
	{
		node[i].mincode=node[i-1].mincode+node[i-1].num;
		for(j=0;j<i;j++)
		{
			node[i].a[j]=node[j].num*node[i-j-1].num;
			node[i].num+=node[i].a[j];
		}
		node_cnt++;
	}
	cin>>code;
	while(0!=code)
	{
		printcode(code);
		cout<<endl;
		cin>>code;
	}

	return 0;
}