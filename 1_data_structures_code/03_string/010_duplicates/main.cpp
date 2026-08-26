#include <iostream>
#include <cctype>

using namespace std;

// Method 1: Using Hash Table / Counting Array (O(n) time, 104 bytes space)
void findDuplicatesHash(const char A[])
{
    int H[26] = {0}; // Frequency array for 'a' - 'z'
    char temp;
    for (int i = 0; A[i] != '\0'; i++)
    {
        temp = tolower(A[i]); //case insensitive hash table so, 'a' and 'A' are duplicates
        H[temp - 'a']++;
    }

    cout << "Duplicates using Hash Table (with count):\n";
    for (int i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            cout << "  Character '" << (char)(i + 'A') << "' is duplicated " << H[i] << " times\n";
        }
    }
}


// Method 2: Using Bitwise Operations (Bitmasking: O(n) time, 4 bytes space)
// Uses Left Shift (<<), Masking (&), and Merging (|)
void findDuplicatesBitwise(const char A[])
{
    long int H = 0, a;
    char temp;
    for (int i = 0; A[i]; i++)
    {
        temp = tolower(A[i]);

        //creating mask
        a = 1;
        a = a << (temp - 'a');

        //check if letter already there (masking)
        if ((H & a) > 0)
        {
            cout << "Duplicate found: " << A[i] << endl;
        }
        // if not there them mark its presence (merging)
        else
        {
            H = H | a;
        }
    }
    cout << endl;
}

int main()
{
    char A[] = "bitch ass nigga";

    cout << "  Finding Duplicates in String: \"" << A << "\"\n";

    // 1. Bitwise approach (from whiteboard lecture)
    findDuplicatesBitwise(A);

    cout << "\n";

    // 2. Hash table approach (for frequency verification)
    findDuplicatesHash(A);

    return 0;
}
