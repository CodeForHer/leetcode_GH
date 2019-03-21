#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Make_list(vector<int>& vec){
    int n = vec.size();
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    for(int i=0;i<n;i++){
        cur->next = new ListNode(vec[i]);
        cur = cur->next;
    }
    cur = dummy->next;
    delete dummy;
    return cur;
}

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

void Show_list(ListNode* head){
    ListNode* point = head;
    while(point!=NULL){
        cout<<point->val<<"->";
        point=point->next;
    }
    cout<<"NULL";
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
