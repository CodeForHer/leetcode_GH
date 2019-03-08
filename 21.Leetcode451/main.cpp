#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        string res;
        for(int i=0;i<s.size();++i){
            freq[s[i]]++;
        }
        vector<pair<char,int>> vec(freq.begin(),freq.end());
        sort(vec.begin(),vec.end(),cmp);
        //使用lamda函数也可以
        //sort(vec.begin(),vec.end(),[=](std::pair<char, int>& a, std::pair<char, int>& b) { return a.second > b.second; });
        for(int i=0;i<vec.size();++i){
            pair<char,int> tmp = vec[i];
            while(tmp.second!=0){
                res.push_back(tmp.first);
                --tmp.second;
            }
        }
        return res;
        }
        static bool cmp(pair<char, int>& p1,pair<char, int>& p2) {
            return p1.second > p2.second;
        }

};

int main()
{
    string s;
    s = Solution().frequencySort("tree");
    cout<<s;
    return 0;
}
