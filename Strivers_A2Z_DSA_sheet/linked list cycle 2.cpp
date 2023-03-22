// Problem : https://leetcode.com/problems/linked-list-cycle-ii/
// Explanation (with maths) : https://youtu.be/QfbOhn0WZ88

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

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            ListNode *entry = head;
            while (entry != slow)
            {
                entry = entry->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main()
{
    int n = creater(); // Takes number of elements to insert into the list from user, then takes those elements input from user too
    cyclemaker();      // Takes position as input from user and points the next of last node of list to that positiion

    ListNode *ans = detectCycle(head);

    printer(ans); // Prints all node values inside the cycle
    deleter(n);
    return 0;
}