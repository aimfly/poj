#include<stdio.h>


int animal[50001];
int relate[50001];
int cal_count;
int check_eat[3][3]={1,0,1,1,1,0,0,1,1};
int fix_rela[3][3]={2,0,1,0,1,2,1,2,0};
int fix_rela1[3][3]={1,2,0,0,1,2,2,0,1};
int cal_rale1[3][3]={1,2,0,0,1,2,2,0,1};
int cal_rale2[3][3]={0,1,2,2,0,1,1,2,0};
int n;
int k;

void conect(int a,int b,int r)
{
	if(animal[a]>animal[b]){
		animal[b]=animal[a]+animal[b];
		animal[a]=b;
		relate[a]=r;
	}
	else{
		animal[a]=animal[a]+animal[b];
		animal[b]=a;
		relate[b]=2-r;
	}
}

int getroot(int c,int &ro,int &re)
{
	int r;
	int t;
	int next;
	int root;
	root=c;
	r=relate[root];
	while(animal[root]>0){
		cal_count++;
		root=animal[root];
		r=fix_rela[r][relate[root]];
	}
	re=r;ro=root;
	while(root!=c){
		cal_count++;
		next=animal[c];
		animal[c]=root;
		t=relate[c];
		relate[c]=r;
		r=fix_rela1[t][r];
		c=next;
	}
	return 0;
}

/*int main(){
	int root;
	int rel;
	animal[1]=2;
	animal[2]=3;
	animal[3]=4;
	animal[4]=5;
	animal[5]=-1;
	relate[1]=0;
	relate[2]=0;
	relate[3]=0;
	relate[4]=0;
	relate[5]=1;
	getroot(1,root,rel);
}*/

int main()
{
    int type;
    int no1;
    int no2;
    int a,b;
    int r1;
    int r2;
    int i;
    int ans=0;
    for(i=0;i<50001;i++){
    	relate[i]=1;
    	animal[i]=-1;
    }
    scanf("%d%d",&n,&k);
    while(k--){
    	scanf("%d%d%d",&type,&no1,&no2);
        if(no1>n||no2>n){
        	ans++;
        	continue;
        }
        getroot(no1,a,r1);
        getroot(no2,b,r2);
        if(a==b){
        	if(1==type){
        		if(r1!=r2)ans++;
        	}
        	else{
        		ans+=check_eat[r1][r2];
        	}
        }
        else{
        	if(1==type){
        		conect(a,b,cal_rale1[r1][r2]);
        	}
        	else{
        		conect(a,b,cal_rale2[r1][r2]);
        	}
        }
    }
    printf("%d\n",ans);
    return 0;
}