#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<int> removeDuplicates(const vector<int>& arr) {
    unordered_map<int, bool> seen;
    vector<int> result;

    for (int num : arr) {
        if (!seen[num]) {
            result.push_back(num);
            seen[num] = true;
        }
    }

    return result;
}


int main() {
    vector<int> arr = {43,0,3,67,99,101,20,11};
    int kth;

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout<<"Enter the kth position:";
    cin>>kth;

    vector<int> updatedArr = removeDuplicates(arr);
    sort(updatedArr.begin(), updatedArr.end());
    if(kth>0 && kth<=updatedArr.size()){
        int ans=updatedArr[kth-1];
        cout << kth<<"th smallest element is: " << ans << ": ";
    }
    else{
        cout<<-1;
    }
    
    return 0;
}