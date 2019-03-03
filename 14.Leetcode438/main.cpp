#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> aim_freq;
        unordered_map<char,int> real_freq;
        vector<int> res;
        for(int i=0;i<p.size();++i){
            aim_freq[p[i]]++;

        }
        int l=0,r=-1;
        while(l<s.size()){
            if(r+1<s.size()&&(!may_satisfy(aim_freq,real_freq))){
                r++;
                if(aim_freq[s[r]]!=0){
                    real_freq[s[r]]++;
                }
            }
            else{
                if(aim_freq[s[l]]!=0){
                    real_freq[s[l]]--;
                }
                l++;
            }
            if(satisfy(aim_freq,real_freq)&&(r-l+1==p.size())){
                res.push_back(l);
            }
        }
        return res;
    }

    bool may_satisfy(unordered_map<char,int>& aim,unordered_map<char,int>& real){
        for(unordered_map<char,int>::iterator p = aim.begin();p!=aim.end();++p){
            if(real[p->first]<p->second){
                return false;
            }
        }
        return true;
    }
    bool satisfy(unordered_map<char,int>& aim,unordered_map<char,int>& real){
        for(unordered_map<char,int>::iterator p = aim.begin();p!=aim.end();++p){
            if(real[p->first]!=p->second){
                return false;
            }
        }
        return true;
    }
    void show_vec(vector<int> res){
        for(int i=0;i<res.size();++i){
            cout<<res[i]<<" ";
        }
    }
};
int main()
{
    string s="baa";
    string p= "aa";
    vector<int> res = Solution().findAnagrams(s,p);
    Solution().show_vec(res);
    return 0;
}
