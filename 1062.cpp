#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _replace_thing{
    int id;
    int price;
} replace_thing;

typedef struct _thing{
    int price;
    int owner_level;
    vector<replace_thing> replace_things;
    int checking;
} thing;

vector<thing> things;
int m;
int get_min_price(int id,int max_level,int min_level){
    if(things[id].checking==1)return -1;
    if(things[id].owner_level<min_level){
        min_level=things[id].owner_level;
    }else if(things[id].owner_level>max_level){
        max_level=things[id].owner_level;
    }
    if(max_level-min_level>m)return -1;
    things[id].checking=1;
    int min_price=things[id].price;
    int total_price;
    int tmp_price=0;
    for(int i=0;i<things[id].replace_things.size();i++){
        if(min_price<things[id].replace_things[i].price)continue;
        tmp_price=get_min_price(things[id].replace_things[i].id,max_level,min_level);
        if(tmp_price==-1)continue;
        total_price=tmp_price+things[id].replace_things[i].price;
        if(min_price>total_price){
            min_price=total_price;
        }
    }
    things[id].checking=0;
    return min_price;
}

int main(){
    int n;
    int master_lever;
    int p,l,x,t,v;
    cin>>m>>n;
    thing tmp_thing;
    replace_thing tmp_replace;
    for(int i=0;i<n;i++){
        cin>>p>>l>>x;
        tmp_thing.price=p;
        tmp_thing.owner_level=l;
        tmp_thing.replace_things.clear();
        tmp_thing.checking=0;
        for(int j=0;j<x;j++){
            cin>>t>>v;
            tmp_replace.id=t-1;
            tmp_replace.price=v;
            tmp_thing.replace_things.push_back(tmp_replace);
        }
        things.push_back(tmp_thing);
    }
    int min_price=get_min_price(0,things[0].owner_level,things[0].owner_level);
    cout<<min_price<<endl;
    return 0;
}