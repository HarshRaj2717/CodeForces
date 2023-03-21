// Problem : https://leetcode.com/problems/linked-list-cycle/

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

int creater()
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

    return n; // Returning n to make it easier and error-free when we delete the list at  end of program using deleter()
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

void deleter(int n)
{
    while (head && n--)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

void cyclemaker()
{
    int pos;
    cin >> pos;

    ListNode *tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }

    ListNode *ptr = head;
    for (int i = 0; i < pos; i++)
    {
        ptr = ptr->next;
    }

    tail->next = ptr;
}

bool hasCycle(ListNode *head)
{
    if (!head)
        return false;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast)
    {
        if (fast == slow)
            return true;
        slow = slow->next;
        if (fast->next)
            fast = fast->next->next;
        else
            fast = fast->next;
    }
    return false;
}

int main()
{
    int n = creater(); // Takes number of elements to insert into the list from user, then takes those elements input from user too
    cyclemaker();      // Takes position as input from user and points the next of last node of list to that positiion

    hasCycle(head) ? cout << "true" << endl : cout << "false" << endl;

    deleter(n);
    return 0;
}