#include<iostream>
using namespace std;
class Solution {
    private:
    void solve(vector<string> &ans,int index, string mapping[],string output,string digit){
        if(index>=digit.length()){
            ans.push_back(output);
            return;
        }
        int number=digit[index]-'0';
        string value=mapping[number];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(ans,index+1,mapping,output,digit);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length()==0){
            return ans;
        }
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output="";
        solve(ans,index,mapping,output,digits);
        return ans;

    }
};

int main(){
    return 0;
}