/* Remove Duplicates from Sorted List */

Node *removeDuplicates(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;

    Node *current = head;

    while (current->next != nullptr)
    {
        if (current->data == current->next->data)
        {
            Node *duplicate = current->next;
            current->next = duplicate->next;
            if (duplicate->next != nullptr)
                duplicate->next->prev = current;
            delete duplicate;
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}
