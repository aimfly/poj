#include <iostream>
#include <vector>
using namespace std;

vector<int> bigAdd(const vector<int> &l,const vector<int> &r){
    vector<int> result;
    int advance=0;
    int tmp;
    unsigned int i=0;
    for(i=0; i<l.size() && i<r.size();i++){
        tmp=l[i]+r[i]+advance;
        result.push_back(tmp%10);
        advance=tmp/10;
    }

    const vector<int> &left = (i==l.size()?r:l);

    for(;i<left.size();i++){
        tmp=left[i]+advance;
        result.push_back(tmp%10);
        advance=tmp/10;
    }

    if(advance)result.push_back(advance);

    return result;
}

void bigPrint(const vector<int> &number){
    for(int i=number.size()-1;i>=0;i--){
        cout<<number[i];
    }
}

int main() {
    vector<int> v[102],l[102];
    v[1].push_back(1);
    l[1].push_back(0);
	for(int i=2;i<=101;i++){
	    v[i]= bigAdd(bigAdd(v[i-1],v[i-1]),l[i-1]);
	    l[i]= bigAdd(v[i-1],l[i-1]);
	}
	int n;
	while(cin>>n){
	    bigPrint(bigAdd(v[n],l[n]));
	    cout<<endl;
	}
	return 0;
}