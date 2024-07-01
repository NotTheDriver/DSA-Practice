#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkForPos(vector<int>& position, int mid, int m) {
        int prev = position[0];
        int count = 1;
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - prev >= mid) {
                count++;
                prev = position[i];
            }
            if (count == m) {
                break;
            }
        }
        return count == m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int start = 1;
        int ans = -1;
        int end = position[n - 1] - position[0];
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (checkForPos(position, mid, m)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}