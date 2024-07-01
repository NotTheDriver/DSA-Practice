#include<iostream>
using namespace std;
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum=0;
	for(int i=0;i<n;i++){
		totalSum+=arr[i];
	}
	int k=totalSum;
    vector<bool>prev(k+1,0),curr(k+1,0);
    prev[0]=curr[0]=true;
    if(arr[0]<=k) prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool not_take=prev[target];
            bool take=false;
            if(arr[ind]<=target){
                take=prev[target-arr[ind]];
            }
            curr[target]=take|not_take;
        }
        prev=curr;
    }
    int mini=1e9;
	for(int s1=0;s1<=totalSum/2;s1++){
		if(prev[s1]==true){
			mini=min(mini,abs((totalSum-s1)-s1));
		}
	}
	return mini;
}

int main(){
    return 0;
}