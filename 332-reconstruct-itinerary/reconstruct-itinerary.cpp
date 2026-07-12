class Solution {
public:
    void run_dfs(string cur_air,
                 map<string, vector<string>>& flt_map,
                 vector<string>& ans_arr) {
        while (!flt_map[cur_air].empty()) {
            string nxt_air = flt_map[cur_air].back();
            flt_map[cur_air].pop_back();

            run_dfs(nxt_air, flt_map, ans_arr);
        }
        ans_arr.push_back(cur_air);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> flt_map;
        int num_tkt = tickets.size();
        for (int idx = 0; idx < num_tkt; idx++) {
            string dep_air = tickets[idx][0];
            string arr_air = tickets[idx][1];
            flt_map[dep_air].push_back(arr_air);
        }
        for (auto& pair_it : flt_map) {
            sort(pair_it.second.begin(),
                 pair_it.second.end(),
                 greater<string>());
        }
        vector<string> ans_arr;
        run_dfs("JFK", flt_map, ans_arr);
        reverse(ans_arr.begin(), ans_arr.end());
        return ans_arr;
    }
};