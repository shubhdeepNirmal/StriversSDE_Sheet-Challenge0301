//using map
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s) {
    vector<vector<int>> ans;
    unordered_map<int, int> mapp;

    for (int i = 0; i < arr.size(); i++) {
        int a = s - arr[i];
        if (mapp.find(a) != mapp.end()) {
            vector<int> aa;
            aa.push_back(a);
            aa.push_back(arr[i]);
            sort(aa.begin(), aa.end());

            int count = mapp[a];
            while (count--) {
                ans.push_back(aa);
            }
        }
        mapp[arr[i]]++;
    }

    sort(ans.begin(), ans.end());
    return ans;
}
