/* Coding Ninjas: Find pairs with given sum in doubly linked list */
vector<pair<int, int>> findPairs(Node *head, int k)
{

    vector<pair<int, int>> ans;

    Node *start = head;
    Node *end = head;

    while (end->next)
    {
        end = end->next;
    }

    while (start != end && end->next != start)
    {
        int data1 = start->data;
        int data2 = end->data;
        int sum = data1 + data2;

        if (sum == k)
        {
            pair<int, int> auxPair = {data1, data2};
            ans.push_back(auxPair);

            start = start->next;
            end = end->prev;
        }
        else if (sum < k)
            start = start->next;
        else
            end = end->prev;
    }

    return ans;
}