#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    char in[60];
    int count[26];
    for(int i=0;i<26;i++)
            count[i]=0;
    scanf("%s",in);
    while(in[0]!='#'){
        int e;
        for(int i=0;i<60;i++){
            if(in[i]>'z'||in[i]<'a'){
                e=i-1;
                break;
            }
        }

        for(int i=0;i<26;i++)
                count[i]=0;

        char pre;
        int i;
        for(i=e;i>=0;i--){
            count[in[i]-'a']++;
            if(i==e)pre=in[i];
            else{
                if(in[i]<pre)break;
                pre=in[i];
            }

        }


        if(i>=0){
            char c=in[i];
            in[i]=0;
            printf("%s",in);
            for(int j=c-'a'+1;j<26;j++){
                if(count[j]){
                    cout<<char(j+'a');
                    count[j]--;
                    break;
                }
            }
            for(int j=0;j<26;j++){
                while(count[j]){
                    cout<<char(j+'a');
                    count[j]--;
                }
            }
            cout<<endl;
        }
        else{
            cout<<"No Successor"<<endl;
        }

        scanf("%s",in);
    }
	return 0;
}