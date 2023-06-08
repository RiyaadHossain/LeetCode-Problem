/* 142. Linked List Cycle II */
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return nullptr;
}

/* 328. Odd Even Linked List */
ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == nullptr)
        return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *firstEven = even;

    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = firstEven;
    return head;
}

/* 19. Remove Nth Node From End of List */
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL || head->next == nullptr)
        return nullptr;

    ListNode *forw = head;
    while (n != 0)
    {
        n--;
        forw = forw->next;
    }

    ListNode *prev = nullptr;
    ListNode *target = head;
    while (forw != nullptr)
    {
        prev = target;
        target = target->next;
        forw = forw->next;
    }

    if (prev == nullptr)
        head = head->next;
    else
        prev->next = target->next;

    delete target;

    return head;
}

/* 2095. Delete the Middle Node of a Linked List */
ListNode *deleteMiddle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    ListNode *prev = head, *slow = head, *fast = head->next;
    while (fast)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;
    }

    prev->next = slow->next;
    delete slow;
    return head;
}

/* 148. Sort List */
class Solution
{

private:
    ListNode *mergeSort(ListNode *ptr1, ListNode *ptr2)
    {
        ListNode *sortedHead = new ListNode(0);
        ListNode *curr = sortedHead;

        while (ptr1 && ptr2)
        {
            if (ptr1->val <= ptr2->val)
            {
                curr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                curr->next = ptr2;
                ptr2 = ptr2->next;
            }

            curr = curr->next;
        }

        if (ptr1)
            curr->next = ptr1;
        if (ptr2)
            curr->next = ptr2;

        return sortedHead->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        // Find the middle
        ListNode *prev = head, *slow = head, *fast = head;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return mergeSort(l1, l2);
    }
}

/* GFG: Given a linked list of 0s, 1s and 2s, sort it. */
Node *
segregate(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;
    while (curr)
    {
        if (curr->data == 0)
        {
            zeroTail->next = curr;
            zeroTail = zeroTail->next;
        }

        if (curr->data == 1)
        {
            oneTail->next = curr;
            oneTail = oneTail->next;
        }

        if (curr->data == 2)
        {
            twoTail->next = curr;
            twoTail = twoTail->next;
        }

        curr = curr->next;
    }

    if (oneHead->next)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    return zeroHead->next;
}

/* 2. Add Two Numbers */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *resultHead = new ListNode(0);
    ListNode *resultList = resultHead;
    int carry = 0;

    while (l1 || l2)
    {
        int sum = carry;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        int num = sum % 10;
        resultList->next = new ListNode(num);
        resultList = resultList->next;
    }

    if (carry == 1)
        resultList->next = new ListNode(carry);

    return resultHead->next;
}