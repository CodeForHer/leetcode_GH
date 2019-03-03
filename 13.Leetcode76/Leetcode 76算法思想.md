# Leetcode 76(Minimum Window Substring)

## 题目链接
[Minimum Window Substring](https://leetcode-cn.com/problems/minimum-window-substring/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(1)*

- 采用滑动窗口的思想，窗口[l,r]动态的存放连续的字符字串。
- 设置两个哈希表，aim用来统计目标字符串t的字符频率；result用来表示被处理字符串s的滑动窗口[l,r]内的字符频率。
- 函数satiasfy参数是这两个哈希表，用来判断两个哈希表统计的字符频率是否相同。若相同，则说明当前窗口满足条件，则可以判断这个窗口是否是满足包含目标字符串的最小字符；反之，不能判断。
- 这道题目关键点是窗口的移动。若窗口的右边界没到被处理字符串的右边界，并且当前窗口不满足satisfy函数，则向右移动窗口；否则左移窗口。无论是左移还是右移，都要对移动后的窗口[i,j]，更新result哈希表。

### 方法1代码：
```

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
	//这里的两个参数aim和result应该写成引用类型，否则当数据规模增大，使用值传递会进行赋值操作，消耗大量时间，leetcode上最后一个测试用例无法通过
        for(unordered_map<char,int>::iterator p=aim.begin();p!=aim.end();++p){
            if(p->second!=0){
                if(result[p->first]<p->second){
                    return false;
                }
            }
        }
        return true;
    }


```
#### 需要注意的地方
- satisfy函数参数应该写成引用类型，否则无法通过最后一个测试用例
