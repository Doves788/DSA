class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long>vec(n);
        int p=0;
        for(int i=0;i<n;i++){
            p=max(p,nums[i]);
            vec[i]=gcd(nums[i],p);
        }
        sort(vec.begin(), vec.end());
        int l=0;
        int r=n-1;
        long long s=0 ;
        while(l<=r-1){
            s=s+gcd(vec[l],vec[r]);
            l++;
            r--;
        }
        return s;
    }
};