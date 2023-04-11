// Problem : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Explanation : Available in my written notes

#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} *head;

void creater()
{
    head = new ListNode;
    ListNode *ptr = head;
    int n;
    cin >> n;
    while (n)
    {
        cin >> ptr->val;
        if (--n)
        {
            ptr->next = new ListNode;
            ptr = ptr->next;
        }
    }
}

void printer(ListNode *ptr = head)
{
    while (ptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void deleter()
{
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

ListNode *middleNode(ListNode *head)
{
    ListNode *ptr1 = head;
    ListNode *ptr2 = head;
    // int i = 0;
    while (ptr1 && ptr1->next)
    {
        ptr1 = ptr1->next->next;
        // i++;
        // if(i%2) ptr2 = ptr2->next;
        ptr2 = ptr2->next;
    }
    return ptr2;
}

ListNode* reverser(ListNode* prev, ListNode* s, ListNode* e, ListNode* head){
    ListNode* s_save = s;
    ListNode* prev_save = prev;
    while(s != e){
        ListNode *temp = s->next;
        s->next = prev;
        prev = s;
        s = temp;
    }
    s_save->next = e->next;
    e->next = prev;
    if(prev_save) prev_save->next = e;
    else head = e;
    return head;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(k == 1) return head;
    ListNode* s = head;
    ListNode* e = head;
    ListNode* prev = NULL;
    while(e){
        for(int i = 0; i < k - 1 && e != NULL; i++) e = e->next;
        if(!e) break;
        ListNode* prev_save = s;
        ListNode* save = e->next;
        head = reverser(prev, s, e, head);
        prev = prev_save;
        s = save;
        e = save;
    }
    return head;
}

int main()
{
    creater(); // Takes number of elements to insert into the list from user, then takes those elements input from user too
    int k;
    cin >> k;

    head = reverseKGroup(head, k);

    printer();
    deleter();
    return 0;
}