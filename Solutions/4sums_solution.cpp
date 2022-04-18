class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // create two n*n sized arrays that contains all possible sums.
        vector<long long> nums1_2, nums3_4;
        for(long long n1 : nums1) {
            for(long long n2 : nums2) {
                nums1_2.push_back(n1 + n2);
            }
        }
        
        for(long long n3 : nums3) {
            for(long long n4 : nums4) {
                nums3_4.push_back(n3 + n4);
            }
        }
        
        // sort one n*n sized array for binary searching using the other array
        sort(nums3_4.begin(), nums3_4.end());
              
        long long numberOfTuples = 0;
        for(long long n : nums1_2) {
            // lookup all duplicate negatives of the 1st array sums in the 2nd array.
            auto r = equal_range(nums3_4.begin(), nums3_4.end(), -n);
            numberOfTuples += (r.second - r.first);
        }
        
        return numberOfTuples;
    }
};
