#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> pos;
        vector<int> res;
        for(int i=0;i<nums.size();++i){
            if(pos.find(target-nums[i])==pos.end()){
                pos[nums[i]]=i;
            }
            else{
                res.push_back(i);
                res.push_back(pos[target-nums[i]]);
                break;
            }
        }
        return res;
    }


    vector<int> twoSum2(vector<int>& nums, int target) {
        multimap<int,int> pos;
        vector<int> res;
        for(int i=0;i<nums.size();++i){

            pos.insert(make_pair(nums[i],i));
        }
        vector<pair<int,int>> vec(pos.begin(),pos.end());
        sort(vec.begin(),vec.end(),cmp);
        int i=0,j=vec.size()-1;
        while(i<j){
            if(vec[i].first+vec[j].first<target)
                ++i;
            else
            {
                if(vec[i].first+vec[j].first>target)
                {
                    --j;
                }
                else
                {
                    res.push_back(vec[i].second);
                    res.push_back(vec[i].second);
                    break;
                }
            }
        }
        return res;
    }

    static bool cmp(pair<int,int>& p1, pair<int,int>& p2){

        return p1.first < p2.first;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
