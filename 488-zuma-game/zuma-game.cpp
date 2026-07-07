#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, int> memo_cache;
    string collapse_board(string current_board) {
        bool has_collapsed = true;
        while(has_collapsed) {
            has_collapsed = false;
            int end_idx = 0;
            for(int start_idx = 0; start_idx <= current_board.length(); start_idx++) {
                if(start_idx == current_board.length() || current_board[start_idx] != current_board[end_idx]) {
                    if(start_idx - end_idx >= 3) {
                        current_board = current_board.substr(0, end_idx) + current_board.substr(start_idx);
                        has_collapsed = true;
                        break;
                    }
                    end_idx = start_idx;
                }
            }
        }
        return current_board;
    }

    int dfs(string current_board, string current_hand) {
        if(current_board.empty()) return 0;
        if(current_hand.empty()) return -1;
        sort(current_hand.begin(), current_hand.end());
        string state_key = current_board + "#" + current_hand;
        if(memo_cache.count(state_key)) {
            return memo_cache[state_key];
        }

        int min_balls_used = 1e9;

        for(int board_idx = 0; board_idx <= current_board.length(); board_idx++) {
            for(int hand_idx = 0; hand_idx < current_hand.length(); hand_idx++) {
                if(hand_idx > 0 && current_hand[hand_idx] == current_hand[hand_idx - 1]) {
                    continue;
                }

                bool matches_current =
                    (board_idx < current_board.length() &&
                     current_board[board_idx] == current_hand[hand_idx]);
                bool splits_matching_pair =
                    (board_idx > 0 &&
                     board_idx < current_board.length() &&
                     current_board[board_idx - 1] == current_board[board_idx] &&
                     current_board[board_idx] != current_hand[hand_idx]);

                if(matches_current || splits_matching_pair) {

                    string next_board =
                        current_board.substr(0, board_idx) +
                        current_hand[hand_idx] +
                        current_board.substr(board_idx);
                    next_board = collapse_board(next_board);
                    string next_hand =
                        current_hand.substr(0, hand_idx) +
                        current_hand.substr(hand_idx + 1);

                    int result = dfs(next_board, next_hand);
                    if(result != -1) {
                        min_balls_used = min(min_balls_used, result + 1);
                    }
                }
            }
        }

        memo_cache[state_key] = (min_balls_used == 1e9) ? -1 : min_balls_used;
        return memo_cache[state_key];
    }

    int findMinStep(string board, string hand) {
        memo_cache.clear();
        return dfs(board, hand);
    }
};