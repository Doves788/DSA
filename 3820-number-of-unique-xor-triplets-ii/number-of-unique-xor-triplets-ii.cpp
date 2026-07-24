class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                st1.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> st2;
        for (int x : st1) {
            for (int k = 0; k < n; k++) {
                st2.insert(x ^ nums[k]);
            }
        }
        return st2.size();
    }
};