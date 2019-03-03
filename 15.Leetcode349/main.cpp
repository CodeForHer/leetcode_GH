#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record;
        for(int i=0;i<nums1.size();++i){
            record.insert(nums1[i]);
        }
        set<int> res;
        for(int i=0;i<nums2.size();++i){
            if(record.find(nums2[i])!=record.end()){
                res.insert(nums2[2]);
            }
        }
        vector<int> result;
        for(set<int>::iterator iter = res.begin();iter!=res.end();++iter){
            result.push_back(*iter);
        }
        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
