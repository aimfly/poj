#include <iostream>
using namespace std;

struct node_t{
	int value;
	int count;
	struct node_t *child[20];
};
int m;
char pre[26];
char post[26];

void create_tree(struct node_t *root,char *pre,char *post,int len)
{
	int i,j;
	char c;
	memset(root->child,0,sizeof(root->child));
	root->count=0;
	root->value=0;
	for(i=0,j=0;i<len;){
		c=pre[i];
		while(c!=post[j]){
			j++;
		}
		if(i!=j){
			root->child[root->count]=(struct node_t *)malloc(sizeof(struct node_t));
			create_tree(root->child[root->count],&pre[i+1],&post[i],j-i);
		}
		root->count++;
		j++;
		i=j;
	}
}

int cmn(int m,int n)
{
	int ans=1;
	int i;
	for(i=0;i<n;++i){
		ans*=m;
		m--;
	}
	for(;n>1;--n){
		ans/=n;
	}
	return ans;
}

void cal_value(struct node_t *root)
{
	int value=1;
	int i;
	for(i=0;i<root->count;++i){
		if(root->child[i]!=NULL){
			if(root->child[i]->value==0){
				cal_value(root->child[i]);
			}
		    value*=root->child[i]->value;
		    free(root->child[i]);
		}
	}
	value*=cmn(m,root->count);
	root->value=value;
}


int main()
{
	struct node_t root;
    cin>>m;
    while(m){
    	cin>>pre;
    	cin>>post;
    	create_tree(&root,&pre[1],&post[0],strlen(pre)-1);
    	cal_value(&root);
    	cout<<root.value<<endl;
    	cin>>m;
    }
	return 0;
}