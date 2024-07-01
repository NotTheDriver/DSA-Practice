#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> names;
    pair<string,int> p1=make_pair("yems",1);
    pair<string,int> p2("chemlo",2);
    names.insert(p1,p2);
    names["shemlo"]=4;
    unordered_map<string,int>::iterator it=names.begin();
    while(it !=names.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}
//map based on bst hence 0(logN)
//unordered_map 0(1) but stores data in random order