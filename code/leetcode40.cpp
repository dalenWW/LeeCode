#include <iostream>
#include<string>
#include<map>
#include <algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<numeric>
#include<iostream>
#include<vector>


using namespace std;
void dfs(vector<int> &candidates,vector<vector<int> > &result,int s,int res,vector<int> &ans);

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int> > result;
    if(candidates.empty() || target <= 0)
        return result;
    vector<int> ans;
    sort(candidates.begin(),candidates.end());
    dfs(candidates,result,0,target,ans);
    return result;
}


void dfs(vector<int> &candidates,vector<vector<int> > &result,int s,int res,vector<int> &ans) {
    if(res == 0)
    {
        result.push_back(ans);
        return;
    }
    for(int i=s;i<candidates.size();i++) {
        if(candidates[i] > res)
            break;
        if(i > s && candidates[i] == candidates[i-1])
            continue;
        ans.push_back(candidates[i]);
        dfs(candidates,result,i+1,res-candidates[i],ans);
        ans.pop_back();
    }
}

//void combination(vector<int> &v,int d,int n,vector<vector<int> >&result,vector<int> &ans,int s) {
//    if(d == n)
//    {
//        result.push_back(ans);
//        return;
//    }
//    for(int i=s;i<v.size();i++) {
//        ans.push_back(v[i]);
//        combination(v,d+1,n,result,ans,i+1);
//        ans.pop_back();
//    }
//}

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<vector<int> >result = combinationSum2(candidates,8);
    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[0].size();j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
    return 0;
}
