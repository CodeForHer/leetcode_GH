#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> result;
        for(int i=0;i<nums1.size();++i){
            freq[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();++i){
            if(freq[nums2[i]]!=0){
                result.push_back(nums2[i]);
                --freq[nums2[i]];
            }
        }
        return result;
    }
    void show_vec(vector<int>& vec){
        for(int i=0;i<vec.size();++i){
            cout<<vec[i]<<" ";
        }
    }
};

int main()
{
    vector<int> vec1 = {1,2,2,1};
    vector<int> vec2 = {2,2};
    vector<int> result = Solution().intersect(vec1,vec2);
    Solution().show_vec(result);
    return 0;
}
