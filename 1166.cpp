#include<iostream>
using namespace std;

struct move_t{
	int count;
	int num[5];
};

struct stat_t{
	unsigned int count;
	int nextidx;
	int usemove;
	int usecount;
};

struct stat_t status[300000];

struct move_t move[9]={{4,{8,7,5,4}},
	            {3,{8,7,6}},
	            {4,{7,6,4,3}},
	            {3,{8,5,2}},
	            {5,{7,5,4,3,1}},
	            {3,{6,3,0}},
	            {4,{5,4,2,1}},
	            {3,{2,1,0}},
	            {4,{4,3,1,0}}
	           };

int getstat(int level,int curstat,int count){
	int i;
	int res;
	int n;
	int fix;
	res=curstat;
	for(i=0;i<move[level].count;++i){
		n=move[level].num[i]<<1;
		fix=((curstat & (0x3<<n))-(count<<n)) & (0x3<<n);
		res= (res & ~(0x3<<n)) | fix;
	}
	return res;
}

void cal_stat(int level,int curstat){
	int i;
	int nextstat;
	if(-1 == level){
		return;
	}
	for(i=0;i<4;++i){
		if(0!=i){
		    nextstat=getstat(level,curstat,i);
		    if(status[curstat].count+i<status[nextstat].count){
			    status[nextstat].count=status[curstat].count+i;
			    status[nextstat].nextidx=curstat;
			    status[nextstat].usemove=level;
			    status[nextstat].usecount=i;
			   cal_stat(level-1,nextstat);
		    }
		}
		else{
			cal_stat(level-1,curstat);
		}
	}
}

int use[9];

int main()
{
	int i;
	int t;
	int clockstat;
	memset(status,0xff,sizeof(status));
	status[0].count=0;
	cal_stat(8,0);
	clockstat=0;
	for(i=0;i<9;i++){
		cin>>t;
		clockstat+= t<<((8-i)*2);
	}
	while(clockstat!=0){
		use[status[clockstat].usemove]=status[clockstat].usecount;
		clockstat=status[clockstat].nextidx;
	}
	for(i=0;i<9;++i){
		while(use[i]--){
			cout<<i+1<<" ";
		}
	}
	return 0;
}