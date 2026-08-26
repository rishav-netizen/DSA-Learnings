#include <iostream>
#include <cctype>

using namespace std;

bool isAnagram(char A[], char B[]);

int main()
{
    char A[] = "decimal";
    char B[] = "medical";

    if (isAnagram(A, B))
    {
        cout << "\"" << A << "\" and \"" << B << "\" are Anagrams." << endl;
    }
    else
    {
        cout << "\"" << A << "\" and \"" << B << "\" are NOT Anagrams." << endl;
    }

    return 0;
}

// basically takes linear time
bool isAnagram(char A[], char B[])
{
    int l1 = 0, l2 = 0;
    for (; A[l1]; l1++);
    for (; B[l2]; l2++);

    //check for length
    if (l1 != l2)
    {
        return false;
    }

    //using hash table
    int H[26] = {0};

    // O(n)
    for (int i = 0; A[i]; i++)
    {
        H[tolower(A[i]) - 'a']++;
    }

    // O(n)
    for (int i = 0; B[i]; i++)
    {
        H[tolower(B[i]) - 'a']--;
        if (H[tolower(B[i]) - 'a'] < 0)
        {
            return false;
        }
    }

    // O(n)
    for (int i = 0; i < 26; i++)
    {
        if (H[i] != 0)
        {
            return false;
        }
    }

    return true;
}