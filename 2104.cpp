#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct _number{
    int num;
    int pos;
}Number;
int comp(const void* num1,const void *num2){
    return ((Number*)num1)->num-((Number*)num2)->num;
}
int main() {    //poj2104
    int n,m;
    scanf("%d %d",&n,&m);
    Number *numbers=new Number[n];
    for(int i=0;i<n;i++){
        scanf("%d",&numbers[i].num);
        numbers[i].pos=i+1;
    }

    qsort(numbers,n,sizeof(Number),comp);

    for(int i=0;i<m;i++){
        //process case
        int start,end,k;
        scanf("%d %d %d",&start,&end,&k);
        //TODO:
        for(int j=0,cur=0;j<n;j++){
            if(numbers[j].pos>=start&&numbers[j].pos<=end) cur++;
            if(cur==k){
                printf("%d\n",numbers[j].num);
                break;
            }
        }
    }
    delete[] numbers;
	return 0;
}