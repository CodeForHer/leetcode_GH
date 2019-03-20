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

void Show_list(ListNode* head){
    ListNode* point = head;
    while(point!=NULL){
        cout<<point->val<<"->";
        point=point->next;
    }
    cout<<"NULL";
}

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

int main()
{
    vector<int> vec = {1,2,3,4,1,2};
    ListNode* point = Make_list(vec);
    Show_list(point);
    //cout << "Hello world!" << endl;
    return 0;
}
