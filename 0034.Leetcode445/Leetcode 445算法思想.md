# Leetcode 445(Add Two Numbers II)

## 题目链接
[Add Two Numbers II](https://leetcode-cn.com/classic/problems/add-two-numbers-ii/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(1)*

- 基本思想是：采用头插法新建两个链表，与题中的顺序相反，之后按照[Add Two Numbers](https://leetcode-cn.com/classic/problems/add-two-numbers/description/)的思想对这两个新链表操作即可即可。

### 方法1代码：
```
	
	class Solution {
	public:
	    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	        ListNode* new_l1 = head_insert(l1);
	        ListNode* new_l2 = head_insert(l2);
	        ListNode* dummy = new ListNode(-1);
	        int carry = 0;
	        while(new_l1||new_l2){
	            int sum = 0;
	            if(new_l1!=nullptr){
	                sum+=new_l1->val;
	                new_l1 = new_l1->next;
	            }
	            if(new_l2!=nullptr){
	                sum+=new_l2->val;
	                new_l2 = new_l2->next;
	            }
	            sum+=carry;
	            
	            ListNode* node = new ListNode(sum%10);
	            node->next =dummy->next;
	            dummy->next = node;
	            
	            carry = sum/10;
	        }
	        if(carry!=0){
	            ListNode* node = new ListNode(carry);
	            node->next = dummy->next;
	            dummy->next = node;
	        }
	        
	        ListNode* res_list = dummy->next;
	        
	        delete dummy;
	        return res_list;
	    }
	    ListNode* head_insert(ListNode* L){
	        ListNode* cur = L;
	        ListNode* dummy = new ListNode(-1);
	        while(cur!=nullptr){
	            ListNode* node = new ListNode(cur->val);
	            node->next = dummy->next;
	            dummy->next = node;
	            cur = cur->next;
	        }
	        ListNode* res = dummy->next;
	        delete dummy;
	        return res;
	    }
	};



```


