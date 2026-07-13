class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            int num = i;
            int digit = i + 1;
            while (digit <= 9) {
                num = num * 10 + digit;
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
                if (num > high) {
                    break;
                }
                digit++;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};