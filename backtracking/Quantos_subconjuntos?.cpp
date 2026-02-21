#include <iostream>
#include <vector>

using namespace std;

int sumSubsets(vector<int>& path) {
    int sum = 0;
    for(int i = 0; i < path.size(); i++) {
        sum += path[i];
    }

    return sum;
}

void subsets(int start, vector<int>& nums, vector<int>& path, int& result, int k) {
    if(sumSubsets(path) == k) {
        result ++;
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

    int result = 0;
    vector<int> path(0);

    subsets(0, nums, path, result, k);

    cout << result;

    return 0;
}
