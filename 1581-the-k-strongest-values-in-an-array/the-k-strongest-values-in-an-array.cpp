class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin() , arr.end());
	int total_elements = arr.size();
	int median_value = arr[(total_elements -1)/2];
	vector<int>strongest_values;
	strongest_values.reserve(k);
	int left_ptr=0;
	int right_ptr = total_elements -1;
	for(int i=0 ; i<k; i++){
	int left_distance = abs(arr[left_ptr] -  median_value) ;
	int right_distance = abs(arr[right_ptr] - median_value);
	if(right_distance  >= left_distance){
	strongest_values.push_back(arr[right_ptr]) ;
	right_ptr--;
}
else{
	strongest_values.push_back(arr[left_ptr]);
	left_ptr++; 
}
}
return strongest_values;

    }
};