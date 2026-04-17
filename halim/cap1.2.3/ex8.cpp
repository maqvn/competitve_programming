#include <bits/stdc++.h>
using namespace std;

int sumSubsets(vector<int>& path) {
    int sum = 0;
    for(int i = 0; i < path.size(); i++) {
        sum += path[i];
    }

    return sum;
}

void subsets(int start, vector<int>& nums, vector<int>& path, vector<vector<int>>& result, int k) {
    if(path.size() > 0) {
        result.push_back(path);
    }
    
    for (int i = start; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        subsets(i + 1, nums, path, result, k);
        path.pop_back();
    }
}

int main() {
    
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result;
    vector<int> path(0);

    subsets(0, nums, path, result, k);

    cout << '{'; 
    for(auto x : result) {
        for(auto y : x) {
            cout << y;
        }
        cout << ", ";
    }
    cout << "}\n";

    return 0;
}