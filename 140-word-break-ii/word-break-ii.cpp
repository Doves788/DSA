class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& d) {
        unordered_set<string> st(d.begin(), d.end());
        unordered_map<string, vector<string>> mp;
        return f(s, st, mp);
    }
    
    vector<string> f(string s, unordered_set<string>& st, unordered_map<string, vector<string>>& mp) {
        if(mp.count(s)) return mp[s];
        
        vector<string> r;
        
        if(s.empty()){
            r.push_back("");
            return r;
        }
        
        for(int i = 1; i <= s.size(); i++){
            string p = s.substr(0, i);
            
            if(st.count(p)){
                vector<string> t = f(s.substr(i), st, mp);
                
                for(auto &x : t){
                    if(x.empty()) r.push_back(p);
                    else r.push_back(p + " " + x);
                }
            }
        }
        
        return mp[s] = r;
    }
};