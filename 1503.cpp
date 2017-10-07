#include <stdio.h>
#include <string.h>

int ans[110];

void add(char a[101])
{
    int len;
    int ansi;
    int t;
    len=strlen(a)-1;
    for(ansi=0;len>-1;--len,++ansi){
        t=a[len]-'0';
        ans[ansi]+=t;
        if(ans[ansi]>=10){
            ans[ansi+1]+=ans[ansi]/10;
            ans[ansi]=ans[ansi]%10;
        }
    }
}

int main()
{
    char input[110];
    int i;
    int len;
    scanf("%s",input);
    len=strlen(input);
    while( !(1 == len && '0' == input[0])){
        add(input);
        scanf("%s",input);
        len=strlen(input);
    }
    for(i=0;i<103;++i){
        input[i]='0';
    }
    input[i]=0;
    add(input);
    for(i=109;ans[i] == 0;--i);
    for(;i>-1;--i){
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}