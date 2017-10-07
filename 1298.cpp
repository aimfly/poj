#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	char table[128];
	char str[256];
	bool conv=false;
	for(int i=int('A');i<=int('Z');i++){
	    table[i]=char((i-5)<int('A')?(i-5+26):(i-5));
	}
	while(1){
	    gets(str);
        if(strcmp(str,"ENDOFINPUT")==0)break;
        else if(strcmp(str,"START")==0){conv=true;continue;}
        else if(strcmp(str,"END")==0){conv=false;continue;}
	    if(conv){
	        char *cur=str;
	        while(*cur){
	            if(*cur<='Z'&&*cur>='A')cout<<table[int(*cur)];
	            else cout<<*cur;
	            cur++;
	        }
	        cout<<endl;
	    }

	}
	return 0;
}