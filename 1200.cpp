#include<stdio.h>
#include<iostream>
using namespace std;

short flag[256];
int flag_cnt;
struct node_t{
	int level;
	struct node_t **child;
};

struct node_t **CmpP;
int CmpCnt;
int ans;
int SubStrLen;
int nChar;

void cmpnext(struct node_t *cur,char c){
	int i;
	i=flag[c];
	if(cur->child[i]!=NULL){
		cur=cur->child[i];
		if(cur->level!=SubStrLen){
		    CmpP[CmpCnt++]=cur;
		}
	}
	else{
		cur->child[i]=(struct node_t *)malloc(sizeof(struct node_t));
		cur->child[i]->child=(struct node_t **)malloc(nChar*sizeof(struct node_t *));
		memset(cur->child[i]->child,0,nChar*sizeof(struct node_t *));
		cur->child[i]->level=cur->level+1;
		cur=cur->child[i];
		if(cur->level!=SubStrLen){
			CmpP[CmpCnt++]=cur;
		}
		else{
			ans++;
		}
	}
}

int main()
{
	struct node_t root;
	char   c;
	int i;
	int cnt;
    scanf("%d %d\n",&SubStrLen,&nChar);
	root.level=0;
	root.child=(struct node_t **)malloc(nChar*sizeof(struct node_t *));
	memset(root.child,0,nChar*sizeof(struct node_t *));
	memset(flag,-1,sizeof(flag));
	CmpP=(struct node_t **)malloc(SubStrLen*sizeof(struct node_t *));
	scanf("%c",&c);
	while(c!='\n'){
		if(-1 == flag[c]){
			flag[c]=flag_cnt++;
		}
		cnt=CmpCnt;
		CmpCnt=0;
		for(i=0;i<cnt;++i){
			cmpnext(CmpP[i],c);
		}
		cmpnext(&root,c);
		scanf("%c",&c);
	}
	cout<<ans<<endl;
	return 0;
}