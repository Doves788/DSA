class SegmentTree {
    int n;
    vector<int> tree, vec;

    void buildTree(int idx, int st, int en) {
        if (st == en) {
            tree[idx] = vec[st];
            return;
        }
        int mid = (st + en) / 2;
        buildTree(idx * 2, st, mid);
        buildTree(idx * 2 + 1, mid + 1, en);
        tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
    }
    int getMax(int idx, int st, int en, int l, int r) {
        if (l <= st && en <= r) {
            return tree[idx];
        }
        int mid = (st + en) / 2;
        int ans = 0;
        if (l <= mid) {
            ans = max(ans, getMax(idx * 2, st, mid, l, r));
        }
        if (r > mid) {
            ans = max(ans, getMax(idx * 2 + 1, mid + 1, en, l, r));
        }
        return ans;
    }

public:
    SegmentTree(vector<int> &a) {
        vec = a;
        n = a.size();
        tree.assign(4 * n, 0);

        if (n) {
            buildTree(1, 0, n - 1);
        }
    }
    int query(int l, int r) {
        if (l > r) {
            return 0;
        }

        return getMax(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');
        vector<int> len;
        vector<int> leftPos;
        vector<int> rightPos;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            if (s[i] == '0') {
                len.push_back(j - i);
                leftPos.push_back(i);
                rightPos.push_back(j - 1);
            }
            i = j;
        }
        int m = len.size();
        if (m < 2) {
            return vector<int>(queries.size(), ones);
        }
        vector<int> merge(m - 1);
        for (int i = 0; i < m - 1; i++) {
            merge[i] = len[i] + len[i + 1];
        }
        SegmentTree st(merge);
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int first = lower_bound(rightPos.begin(), rightPos.end(), l) - rightPos.begin();
            int last = upper_bound(leftPos.begin(), leftPos.end(), r) - leftPos.begin() - 1;
            if (first >= m || last < 0 || first >= last) {
                ans.push_back(ones);
                continue;
            }

            int leftLen = rightPos[first] - max(leftPos[first], l) + 1;
            int rightLen = min(rightPos[last], r) - leftPos[last] + 1;

            if (first + 1 == last) {
                ans.push_back(ones + leftLen + rightLen);
                continue;
            }

            int a = leftLen + len[first + 1];
            int b = len[last - 1] + rightLen;
            int c = st.query(first + 1, last - 2);

            ans.push_back(ones + max({a, b, c}));
        }

        return ans;
    }
};