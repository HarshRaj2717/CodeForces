// Problem : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// ** It's easier in O(n) time and multiple passes
// ** But, a bit of trick is needed for solving in one pass

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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* ptr_prev = NULL;
    ListNode* ptr = head;
    ListNode* temp = head;
    while(n){
        temp = temp->next;
        --n;
    }

    while(temp){
        temp = temp->next;
        ptr_prev = ptr;
        ptr = ptr->next;
    }

    if(ptr_prev) ptr_prev->next = ptr->next;
    else head = head->next;

    return head;
}

int main()
{
    creater(); // Takes number of elements to insert into the list from user, then takes those elements input from user too
    int n;
    cin >> n;

    head = removeNthFromEnd(head, n);

    printer();
    deleter();
    return 0;
}