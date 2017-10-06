#include<iostream>
#include<string>
using namespace std;
string haab[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
string tzolkin[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int main(){
	int n,i;
	char t;
	string mon;
	int day,year;
	long days;
	cin>>n;
	cout<<n<<endl;
	while(n--){
		cin>>day>>t>>mon>>year;
		days=0;
		days+=year*365;
		for(i=0;i<19;i++)if(haab[i]==mon)break;
		days+=i*20+day+1;
		year=days/260;
		days=days%260;
		if(days==0){year--;days=260;}
		day=days%13==0?13:days%13;
		mon=tzolkin[days%20==0?19:days%20-1];
		cout<<day<<' '<<mon<<' '<<year<<endl;
	}
	return 1;
}