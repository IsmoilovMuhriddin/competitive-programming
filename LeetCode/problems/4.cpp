// Excel Sheet Column Number

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged_nums;
        int len = nums1.end() - nums1.begin();
        len += nums2.end() - nums2.begin();
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(merged_nums));

        if (len&1==1){
            return merged_nums[len/2];
        }
        else
        {
            return double(merged_nums[len/2]+merged_nums[len/2-1])/2;
        }
        
        return len;
    }
};

int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> b = { 4, 5, 6};

    cout << Solution().findMedianSortedArrays(a, b);

    return 0;
}