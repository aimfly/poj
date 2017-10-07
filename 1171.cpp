#include <iostream>
#include <map>
using namespace std;

int a[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};

int main(){
  int count[26]={0};
  int count_proc[26]={0};
  int letters[7]={0};
  int letterCnt=0;
  map<int,bool> validWords;
  int i=0;
  int err;
  char letter=0;
  int tmp;
  int value;
  int result=0;
  scanf("%c",&letter);
  while(letter!='\n'){
    count[letter-'a']++;
    scanf("%c",&letter);
  }
  //computer letter
  for(i=0;i<26;++i){
    if(count[i]!=0){
      letters[letterCnt++]=i;
    }
  }

  scanf("%c",&letter);
  while(letter!='.'){
    tmp=0;
    err=0;
    memset(count_proc,0,sizeof(count_proc));
    while(letter!='\n'){
      if(err==0){
        if(count_proc[letter-'a']<count[letter-'a']){
          count_proc[letter-'a']++;
        }
        else{
          err=1;
        }
      }
      scanf("%c",&letter);
    }
    if(err!=1){
      tmp=0;
      value=0;
      for(i=0;i<letterCnt;++i){
        tmp=tmp<<3;
        value+=count_proc[letters[i]]*a[letters[i]];
        tmp+=count_proc[letters[i]];
      }
      if(value>result)result=value;
      validWords[tmp]=true;
    }
    scanf("%c",&letter);
  }
  int t1,t2,t3;
  for(map<int,bool>::iterator it1=validWords.begin();
      it1 != validWords.end();
      ++it1){
    for(map<int,bool>::iterator it2=validWords.begin();
      it2 != validWords.end();
      ++it2){
        t1=it1->first;
        t2=it2->first;
        value=0;
        for(i=letterCnt-1;i>-1;--i){
          t3=t1%8+t2%8;
          t1/=8;
          t2/=8;
          if(t3<=count[letters[i]])
            value+=t3*a[letters[i]];
          else
            break;
        }
        if(i==-1){
          if(value>result)result=value;
        }
    }
  }

  printf("%d\n",result);
  return 0;
}