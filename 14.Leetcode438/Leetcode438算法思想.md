# Leetcode 438(Find All Anagrams in a String)

## 题目链接
[Find All Anagrams in a String](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(1)*

- 采用滑动窗口的思想，窗口[l,r]动态的存放连续的字符字串。
- 设置两个哈希表，aim_freq 用来统计目标字符串p的字符频率；real_freq用来表示被处理字符串s的滑动窗口[l,r]内的字符频率。
- 函数may_satiasfy参数是这两个哈希表，当前窗口[l,r]的字符频率比目标字符串p的字符频率小的时侯，则此时窗口右边界需要向右扩张；否则左边界右移。
- satisfy函数用来判断当前窗口[l,r]的字符频率与目标字符串p的字符频率是否相同。
- 无论是左移还是右移，都要对移动后的窗口[i,j]，更新result哈希表。

### 方法1代码：
```

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
			//注意，这里需要加上窗口大小与p字符串长度相同的条件
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


```
