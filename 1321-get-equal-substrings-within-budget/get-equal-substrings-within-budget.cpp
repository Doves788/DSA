class Solution {
public:
    int equalSubstring(string source_str, string target_str, int max_cost) {
        int str_length = source_str.length();
	int max_substring_length = 0 ;
	
	int current_window_cost =0 ;
	int left_ptr=0 ; 
	for(int right_ptr = 0 ; right_ptr < str_length ; right_ptr++){
	current_window_cost += abs(source_str[right_ptr] -  target_str[right_ptr]);
	while(current_window_cost > max_cost){
	current_window_cost -= abs(source_str[left_ptr] - target_str[left_ptr]);
left_ptr++; 
}
int current_length= right_ptr  -  left_ptr + 1 ;
max_substring_length = max(max_substring_length , current_length);
}
return max_substring_length;
    }
};