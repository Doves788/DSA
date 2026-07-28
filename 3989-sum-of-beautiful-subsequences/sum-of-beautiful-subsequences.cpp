const int mod = 1e9+7;
const int N = 7e4+5;
class BIT{
public:
    int n;
    vector<int> bits;
    BIT(int n){
        this->n = n;
        bits.assign(n+5, 0);
    }
    void update(int id, int val){
        id++;
        while(id <= n){
            bits[id] = (bits[id] + 0LL + val)%mod;
            id += (id & -id);
        }
    }
    int query(int id){
        id++;
        int ans = 0;
        while(id > 0){
            ans = (ans + 0LL + bits[id])%mod;
            id -= (id & -id);
        }
        return ans;
    }
};
vector<vector<int>> dvs = vector<vector<int>>(N);
bool pcd = 0;
void pc(){
    if(pcd)return;
    for(int i=1; i<N; i++){
        for(int j=i; j<N; j+=i){
            dvs[j].push_back(i);
        }
    }
    pcd = 1;
}
class Solution {
public:
    int totalBeauty(vector<int>& nums) {
        pc();
        map<int, int> mp;
        for(auto& i: nums)mp[i] = 1;
        int rank = 1;
        for(auto& [p, q]: mp){
            q = rank;
            rank++;
        }
        int ma = *max_element(nums.begin(), nums.end());
        vector<int>g[ma+1];
        for(auto& x: nums){
            rank = mp[x];
            for(auto& i: dvs[x])g[i].push_back(rank);
        }
        vector<int> cnt(ma+1, 0);
        BIT* fw = new BIT(ma+1);
        auto f = [&](int x){
            if(g[x].empty())return 0;
            int ans = 0;
            for(auto& i: g[x]){
                int curr = fw->query(i-1);
                fw->update(i, curr+1);
                ans = (ans + curr+1)%mod;
            }
            for(auto&i : g[x]){
                int curr = fw->query(i)-fw->query(i-1);
                fw->update(i, -curr);
            }
            return ans;
        };
        for(int i=1; i<=ma; i++){
            cnt[i] = f(i);
        }
        for(int i=ma; i>=1; i--){
            for(int j=i+i; j<=ma; j+=i){
                cnt[i] = (cnt[i] - cnt[j] + mod)%mod;
            }
        }
        int ans = 0;
        for(int i=0; i<= ma; i++){
            ans = (ans + i*1ll*cnt[i])%mod;
        }
        return ans;
    }
};