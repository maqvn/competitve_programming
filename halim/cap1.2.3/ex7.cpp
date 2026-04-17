#include <bits/stdc++.h>
using namespace std;


int permutation(vector<int>& nums, int pos, int total) {
    if(pos == nums.size()-1) {
        return total + 1;
    }
    else {
        for(int i = pos; i < nums.size(); ++i) {
            swap(nums[pos], nums[i]);
            total = permutation(nums, pos + 1, total);
            swap(nums[pos], nums[i]);
        }
        return total;
    }
}

int main() {
    int a;
    cin >> a;

    vector<vector<int>> result;
    vector<int> nums(a);
    

    for(int i = 0; i < a; ++i) {
        cin >> nums[i];
    }

    if(nums.empty()){
        cout << 0 << '\n';
    } 
    else {
        cout << permutation(nums, 0, 0) << '\n';
    } 

    return 0;
}