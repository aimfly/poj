#include <iostream>
using namespace std;

typedef struct _word_t{
	char contant[16];
	int  len;
}word_t;

int replace_check(char *check,char *word)
{
	int flag=0;
	while(*check){
		if(*check!=*word){
			flag++;
			if(2==flag){
			    break;
		    }
		}
		check++;
		word++;
	}
	return flag;
}

int insert_check(char *check,char *word)
{
	int flag=0;
	while(*check){
		if(*check!=*word){
			flag++;
			word++;
			if(2==flag){
			    break;
		    }
		    continue;
		}else{
		    check++;
		    word++;
		}
	}
	return flag;
}

int delete_check(char *check,char *word)
{
	int flag=0;
	while(*word){
		if(*check!=*word){
			flag++;
			check++;
			if(2==flag){
			    break;
		    }
		    continue;
		}else{
		    check++;
		    word++;
		}
	}
	return flag;
}

int main()
{
    word_t dic[10001];
    int    i;
    int    word_cnt=0;
    int    similar[10001];
    int    simi_cnt=0;
    char   check[16];
    int    check_len;
    cin>>dic[word_cnt].contant;
    while(dic[word_cnt].contant[0]!='#'){
    	dic[word_cnt].len=strlen(dic[word_cnt].contant);
    	word_cnt++;
    	cin>>dic[word_cnt].contant;
    }
    cin>>check;
    while(check[0]!='#'){
    	simi_cnt=0;
        check_len=strlen(check);
        for(i=0;i<word_cnt;i++){
        	switch(check_len-dic[i].len){
        		case 0:
        		    switch(replace_check(check,dic[i].contant)){
        		    	case 0:
        		    	    goto REPORT;
        		    	    break;
        		    	case 1:
        		    	    similar[simi_cnt++]=i;
        		    	    break;
        		    	default:
        		    	    break;
        		    }
        		    break;
        		case 1:
        		    switch(delete_check(check,dic[i].contant)){
        		    	case 0:
        		    	    similar[simi_cnt++]=i;
        		    	    break;
        		    	case 1:
        		    	    similar[simi_cnt++]=i;
        		    	    break;
        		    	default:
        		    	    break;
        		    }
        		    break;
        		case -1:
        		    switch(insert_check(check,dic[i].contant)){
        		    	case 0:
        		    	    similar[simi_cnt++]=i;
        		    	    break;
        		    	case 1:
        		    	    similar[simi_cnt++]=i;
        		    	    break;
        		    	default:
        		    	    break;
        		    }
        		    break;
        		default:
        		    break;
        	}
        }
REPORT:
        if(i!=word_cnt){
        	cout<<check<<" is correct"<<endl;
        }else{
        	cout<<check<<":";
        	for(i=0;i<simi_cnt;i++){
        		cout<<' '<<dic[similar[i]].contant;
        	}
        	cout<<endl;
        }
        cin>>check;
    }
	return 0;
}