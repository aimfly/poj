#include<iostream>
using namespace std;
typedef struct _code_t{
	char c[5];
	int len;
}code_t;

code_t code[26]={"01",2,"1000",4,"1010",4,"100",3,"0",1,"0010",4,"110",3,
                 "0000",4,"00",2,"0111",4,"101",3,"0100",4,"11",2,"10",2,
                 "111",3,"0110",4,"1101",4,"010",3,"000",3,"1",1,"001",3,
                 "0001",4,"011",3,"1001",4,"1011",4,"1100",4};
code_t underscore={"0011",4};
code_t period={"1110",4};
code_t comma={"0101",4};
code_t question={"1111",4};

char getletter(char *s,int len)
{
	int i;
	for(i=0;i<26;i++){
		if(code[i].len==len){
			if(0==memcmp(s,code[i].c,len)){
				return i+'A';
			}
		}
	}
	if(0==memcmp(s,underscore.c,len)){
		return '_';
	}
	if(0==memcmp(s,period.c,len)){
		return '.';
	}
	if(0==memcmp(s,comma.c,len)){
		return ',';
	}
	if(0==memcmp(s,question.c,len)){
		return '?';
	}
}
int main()
{
	int i;
	int idx;
	int n;
	int no=0;
	char tmp[500];
	int  tmp_cnt;
	char in[101];
	int num[101];
	int num_cnt;
	char out[101];
	int  out_cnt;
	cin>>n;
	while(n--){
		no++;
		tmp_cnt=0;
		num_cnt=0;
		cin>>in;
		for(i=0;i<strlen(in);i++){
			switch(in[i]){
				case '_':
				    num[num_cnt]=underscore.len;
				    num_cnt++;
				    memcpy(&tmp[tmp_cnt],underscore.c,underscore.len);
				    tmp_cnt+=underscore.len;
				    break;
				case '?':
				    num[num_cnt]=question.len;
				    num_cnt++;
				    memcpy(&tmp[tmp_cnt],question.c,question.len);
				    tmp_cnt+=question.len;
				    break;
				case ',':
				    num[num_cnt]=comma.len;
				    num_cnt++;
				    memcpy(&tmp[tmp_cnt],comma.c,comma.len);
				    tmp_cnt+=comma.len;
				    break;
				case '.':
				    num[num_cnt]=period.len;
				    num_cnt++;
				    memcpy(&tmp[tmp_cnt],period.c,period.len);
				    tmp_cnt+=period.len;
				    break;
				default:
				    idx=in[i]-'A';
				    num[num_cnt]=code[idx].len;
				    num_cnt++;
				    memcpy(&tmp[tmp_cnt],code[idx].c,code[idx].len);
				    tmp_cnt+=code[idx].len;
				    break;
			}
		}
		out_cnt=0;
		memset(out,0,sizeof(out));
		num_cnt--;
		for(i=0;i<tmp_cnt;){
			out[out_cnt++]=getletter(&tmp[i],num[num_cnt]);
			i+=num[num_cnt];
			num_cnt--;
		}
		cout<<no<<": "<<out<<endl;
	}
	return 0;
}