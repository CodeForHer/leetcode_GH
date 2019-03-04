#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> freq;
        freq[n]++;
        int i=0;
        int sum = 0;
        while(i<=0){
            sum = countSum(n);
            if(sum==1){
                i=1;
            }
            else{
                if(freq[sum]==1){
                    i=2;
                }
                else{
                    n = sum;
                    freq[n]++;
                }
            }
        }
        if(i==1){
            return true;
        }
        else
            return false;
    }
    int countSum(int i){
        int sum=0;
        while(i){
            int item = i%10;
            sum+=item*item;
            i = i/10;
        }
        return sum;
    }
};

int main()
{
    cout << Solution().isHappy(19)<< endl;
    return 0;
}
