#include<iostream>
using namespace std;
class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> hashMap;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        //if element is already in the set return false
        if(hashMap.find(val)!=hashMap.end()){
            return false;
        }
        //else add in the set and return true
        v.push_back(val);
        hashMap[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        //if element is not in the set return false
        if(hashMap.find(val)==hashMap.end()){
            return false;
        }
        auto it=hashMap.find(val);
        v[it->second]=v.back();
        v.pop_back();
        hashMap[v[it->second]]=it->second;
        hashMap.erase(val);
        // int index=hashMap[val];
        // if(index!=v.size()-1){
        //     int tail=v.back();
        //     int curr=v[index];
        //     v[index]=tail;
        //     v.erase(v.end());
        //     hashMap.erase(val);
        //     hashMap[tail]=index;
        // }
        // else{
        //     hashMap.erase(v.back());
        //     v.pop_back();
        // }
        return true;
    }
    int getRandom() {
        return v[rand()%v.size()];
    }
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main(){
    return 0;
}