#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();++i){
            vec.push_back(make_pair(nums[i],i));
        }
        stable_sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i+1<vec.size();++i){
            if(vec[i].first==vec[i+1].first){
                if(abs(vec[i].second-vec[i+1].second)<=k){
                    return true;
                }
            }
        }
        return false;
    }
    static  bool cmp(const pair<int,int>& p1,const pair<int,int>& p2){
        return p1.first<p2.first;
    }
};

int main()
{
    vector<int> nums = {1,2,3,1,2,3};
    cout<<Solution().containsNearbyDuplicate(nums,3);
    return 0;
}
