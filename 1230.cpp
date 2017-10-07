#include <iostream>
#include <vector>
using namespace std;

struct wall_t{
  int start;
  int end;
  bool removed;
};

int cmp ( const void *a , const void *b )
{ 
  return (*(wall_t *)a).end - (*(wall_t *)b).end; 
} 

int main(){
  int testCase;
  int t;
  int i,j,tmp1,tmp2,right;
  wall_t aWall;
  int result;
  int passCap,wallNum;
  wall_t wallList[101];
  vector<int> wallProcess; 

  cin>>testCase;
  while((testCase--)>0){
    cin>>wallNum>>passCap;
    right=0;
    for(i=0;i<wallNum;++i){
      cin>>aWall.start>>tmp1>>aWall.end>>tmp2;
      if(aWall.start>aWall.end){
        t=aWall.start;
        aWall.start=aWall.end;
        aWall.end=t;
      }
      aWall.removed=false;
      if(aWall.end>right){
        right=aWall.end;
      }
      wallList[i]=aWall;
    }
    //sort by right band
    qsort(wallList,wallNum,sizeof(wall_t),cmp);

    result=0;
    for(i=0;i<=right;++i){
      wallProcess.clear();
      for(j=0;j<wallNum;++j){
        if(!wallList[j].removed && wallList[j].start<=i && i<=wallList[j].end){
          wallProcess.push_back(j);
        }
      }
      for(j=passCap;j<wallProcess.size();++j){
        wallList[wallProcess[j]].removed=true;
        result++;
      }
    }
    cout<<result<<endl;
  }
  return 0;
}