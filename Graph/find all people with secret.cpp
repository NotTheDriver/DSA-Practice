#include<iostream>
using namespace std;
class Solution {
public:
    typedef pair<int,int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int,vector<P>> adj;
        for(vector<int>& meeting: meetings){
            int person1=meeting[0];
            int person2=meeting[1];
            int time=meeting[2];
            adj[person1].push_back({person2,time});
            adj[person2].push_back({person1,time});
        }
        queue<P> q; //{person,time when they came to know the secret}
        q.push({0,0});
        q.push({firstPerson,0});
        vector<int> time(n,INT_MAX);
        time[0]=0;
        time[firstPerson]=0;
        while(!q.empty()){
            auto [person,t]=q.front();
            q.pop();
            for(auto &ngbr:adj[person]){
                int nextPerson=ngbr.first;
                int meetTime=ngbr.second;
                if(meetTime>=t && time[nextPerson]>meetTime){
                    time[nextPerson]=meetTime;
                    q.push({nextPerson,meetTime});
                }
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(time[i]!=INT_MAX){
                res.push_back(i);
            }
        }
        return res;

    }
};
int main(){
    return 0;
}