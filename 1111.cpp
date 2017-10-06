#include <iostream>
#include <list>
using namespace std;

int main() {
	char grid[20][20];
	list<int> coord;
	int rows,cols,x,y;
	while(cin>>rows>>cols>>x>>y){
	    if(rows==0)break;
	    x--;y--;
	    for(int i=0;i<rows;i++){
	        for(int j=0;j<cols;){
	            char x;
	            cin>>x;
	            if(x=='.'||x=='X'){grid[i][j]=x;j++;}
	        }
	    }
	    coord.clear();
	    coord.push_back((x<<8)+y);
	    grid[x][y]='V';
	    int perimeter=0;
	    while(!coord.empty()){
	        int cx = coord.front()>>8;
	        int cy = coord.front() - (cx<<8);
	        coord.pop_front();
	        for(int i=cx-1;i<=cx+1;i++){
	            for(int j=cy-1;j<=cy+1;j++){
	                if(i<0||j<0||i==rows||j==cols){
	                    if(i==cx||j==cy)perimeter++;
	                    continue;
	                }
	                if(grid[i][j]=='V')continue;
	                if(grid[i][j]=='X'){
	                    grid[i][j]='V';
	                    coord.push_back((i<<8)+j);
	                }
	                else if(i==cx||j==cy)perimeter++;
	            }
	        }
	    }

	    cout<<perimeter<<endl;


	}

	return 0;
}