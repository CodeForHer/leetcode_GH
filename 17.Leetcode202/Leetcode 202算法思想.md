# Leetcode 202(Happy Number)

## 题目链接
[Happy Number](https://leetcode-cn.com/problems/happy-number/description/)

## 算法思想

### 方法1：

- 这个问题可以通过观察发现：如果一个数不是happy number的话，那么在循环过程中计算它每一位的平方和，这个和会重复出现。
- 利用上面的思想，设置一个哈希表，用来存储每个位置上的数字的平方和。如果是happy number，一定会有和为1的时候；否则和一定会重复出现。

### 方法1代码：
```

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


```
