#include<iostream>
using namespace std;
int main(){
	double x,y,x1,y1,x2,y2,x3,y3,x4,y4;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4){
		if(x1==x3&&y1==y3){
			x=x4+x2-x1;
			y=y4+y2-y1;
		}else if(x1==x4&&y1==y4){
			x=x2+x3-x4;
			y=y2+y3-y4;
		}else if(x2==x3&&y2==y3){
			x=x1+x4-x2;
			y=y1+y4-y2;
		}else if(x2==x4&&y2==y4){
			x=x1+x3-x4;
			y=y1+y3-y4;
		}
		printf("%.3f %.3f\n",x,y);
	}
	return 0;
}