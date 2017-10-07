#include<iostream>
using namespace std;
int a[26];
int main(){
	long n,m;
	char c;
	int i;
	int r;
	m=1;
	cin>>n;
	getchar();
	while(m<=n){
		memset(a,0,104);
		r=0;
		while((c=getchar())!='\n')a[c-'a']++;
		while((c=getchar())!='\n')a[c-'a']--;
		for(i=0;i<26;i++)r+=abs(a[i]);
		printf("Case #%d:  %d\n",m,r);
		m++;
	}
	return 0;
}