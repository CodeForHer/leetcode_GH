#include <iostream>
#include <vector>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /*int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        int n = A.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;++i){
            freq[D[i]]++;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                for(int k=0;k<n;++k){
                    int c = 0-A[i]-B[j]-C[k];
                    if(freq[c]>0){
                        res +=freq[c];
                    }
                }
            }
        }
        return res;
    }*/

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        int n = A.size();
        unordered_map<int,int> sum_freq;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int sum = A[i]+B[j];
                sum_freq[sum]++;
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int c = 0 - C[i]-D[j];
                if(sum_freq[c]>0){
                    res+=sum_freq[c];
                }
            }
        }
        return res;
    }
};


int main()
{
    vector<int> A = {1, 2};
    vector<int> B = {-2,-1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    cout<<Solution().fourSumCount(A,B,C,D);
    return 0;
}
