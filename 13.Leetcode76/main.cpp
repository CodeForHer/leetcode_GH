#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> aim;
        unordered_map<char,int> result;
        string res = s+t;
        for(int i=0;i<t.size();++i){
            aim[t[i]]++;
        }
        int l=0,r=-1;
        while(l<s.size()){

            if(r+1<s.size()&&(!satisfy(aim,result))){

                r++;
                if(aim[s[r]]!=0){
                    result[s[r]]++;

                }
            }
            else{

                if(result[s[l]]>0){
                    result[s[l]]--;
                }
                l++;
            }
            if(satisfy(aim,result)){
                if(r-l+1<res.size()){

                    res = "";
                    for(int i=l;i<=r;++i){

                        res.push_back(s[i]);
                    }

                }
            }
        }
        if(res.size()==s.size()+t.size()){

            res = "";
        }
        return res;
    }
    bool satisfy(unordered_map<char,int> &aim,unordered_map<char,int> &result){
        for(unordered_map<char,int>::iterator p=aim.begin();p!=aim.end();++p){
            if(p->second!=0){
                if(result[p->first]<p->second){
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    /*map<char,int> Aim;
    string s = "cabcccdfg";
    for(int i=0;i<s.size();++i){
        Aim[s[i]]++;
    }
    for(map<char,int>::iterator p=Aim.begin();p!=Aim.end();++p){
        cout<<p->first<<" "<<p->second<<" ";
    }
    string res="abc";
    cout<<res+"def";*/
    string S = "aaaaaaaaaaaabbbbbcdd";
    string T = "abcdd";
    cout<<Solution().minWindow(S,T);
    return 0;
}
