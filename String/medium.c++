/* 151. Reverse Words in a String */

string reverseWords(string s)
{

    reverse(s.begin(), s.end());
    int start = 0, end = 0, i = 0, n = s.size();

    while (i < n)
    {
        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Find the end of the current word
        while (i < n && s[i] != ' ')
        {
            s[end] = s[i];
            end++;
            i++;
        }
        cout << s;
        cout << " " << end << endl;

        while (start < end)
        {
            // Reverse the current word
            reverse(s.begin() + start, s.begin() + end);

            // Add a space after the reversed word
            s[end] = ' ';
            end++;

            // Update the start index for the next word
            start = end;
        }

        i++;
    }

    // Remove extra space at the end if present
    if (end > 0)
        s.resize(end - 1);

    return s;
}

/* 451. Sort Characters By Frequency */
string frequencySort(string s)
{
    string ans = "";
    vector<pair<int, char>> hashTable('z' + 1, {0, 0});

    for (auto it : s)
        hashTable[it] = {hashTable[it].first + 1, it};

    sort(hashTable.begin(), hashTable.end());

    for (auto it : hashTable)
        ans = string(it.first, it.second) + ans;

    return ans;
}