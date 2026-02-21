#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
int searchCloser(vector<int>& nums, int key) {
    int l = 0;
    int r = nums.size() - 1;
    int m;
    int closer;
 
    while(l <= r) {
        m = (l + r) / 2;
        if(nums[m] == key) {
            return nums[m];
        }
        else if(key < nums[m]) {
            r = m - 1;
            closer = r;
        }
        else {
            l = m + 1;
            closer = l;
        }
    }

    
    if(l >= nums.size()) {
        return nums[r];
    }
    if(r < 0) {
        return nums[l];
    }

    int left = nums[r];
    int right = nums[l];
    
    
    if(abs(left - key) < abs(right - key)) {
        return left;
    }
    if(abs(left - key) > abs(right - key)) {
        return right;
    }
    return min(left, right);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numOfinputs;
    cin >> numOfinputs;
 
    vector<int> nums(numOfinputs);
 
    for(int i = 0; i < numOfinputs; i++) {
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());

    int numOfAttempts;
    cin >> numOfAttempts;
 
    int attempt;
    for(int i = 0; i < numOfAttempts; i++) {
        cin >> attempt;
        cout << searchCloser(nums, attempt) << '\n';
    }
 
    return 0;
}