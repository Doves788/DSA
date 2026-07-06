class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& firstEnvelope, const vector<int>& secondEnvelope) {
                 if (firstEnvelope[0] == secondEnvelope[0]) {
                     return firstEnvelope[1] > secondEnvelope[1];
                 }
                 return firstEnvelope[0] < secondEnvelope[0];
             });
        vector<int> increasingHeights;
        for (const auto& envelope : envelopes) {
            int currentHeight = envelope[1];
            auto position = lower_bound(increasingHeights.begin(),
                                        increasingHeights.end(),
                                        currentHeight);

            if (position == increasingHeights.end()) {
                increasingHeights.push_back(currentHeight);
            } 
            else{
                *position = currentHeight;
            }
        }
        return increasingHeights.size();
    }
};