# Leetcode 92(Reverse Linked List II)

## 题目链接
[Reverse Linked List II](https://leetcode-cn.com/classic/problems/reverse-linked-list-ii/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(1)*

- 反转链表m——n，需要设置四个指针，指针m-pre指向m节点的前一个节点，指针m-cur指向m节点，指针n-cur指向n节点，n-next指向n节点的下一个节点
- 之后对链表m——n进行反转，思想与[Reverse Linked List](https://leetcode-cn.com/classic/problems/reverse-linked-list/description/)相同。
- 之后m-pre后面指向n-cur,m-cur指向n-next

### 方法1代码：
```
	
	class Solution {
	public:
	    ListNode* reverseBetween(ListNode* head, int m, int n) {
	        ListNode* dummy = new ListNode(-1);
	        dummy->next = head;
	        ListNode* temp = dummy;
	        ListNode* m_pre = NULL;
	        ListNode* m_cur = NULL;
	        ListNode* n_cur = NULL;
	        ListNode* n_next = NULL;
	        for(int i=0;i<=n;++i){
	            if(i==m-1){
	                m_pre = temp;
	            }
	            if(i==m){
	                m_cur = temp;
	            }
	            if(i==n){
	                n_cur = temp;
	            }
	            temp=temp->next;
	        }
	        n_next = temp;
	        m_pre->next = NULL;
	        n_cur->next = NULL;
	
	        ListNode* pre = NULL;
	        ListNode* cur = m_cur;
	        while(cur!=NULL){
	            ListNode* next = cur->next;
	            cur->next=pre;
	            pre = cur;
	            cur = next;
	        }
	        m_cur->next = n_next;
	        m_pre->next = n_cur;
	
	        ListNode* result = dummy->next;
	        delete dummy;
	        return result;
	    }
};



```


