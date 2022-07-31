#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursive printing

void printInterleaving(char *s1, char * s2, char *Store_char, int s1length, int s2length, int iterator)
{
    bool repeating_char = false;
    if (s1length == 0 && s2length == 0) {
        for (int i = 0; i < strlen(Store_char); i++)
        {
            if(Store_char[i] == Store_char[i +1])
                repeating_char = true;
            
        }
        if(repeating_char != true){
            cout << Store_char << endl;
        }

    }
    // if s1 not empty then include/add
    if (s1length !=0)
    {
        Store_char[iterator] = s1[0];
        printInterleaving(s1 + 1, s2, Store_char, s1length - 1, s2length, iterator + 1);
    }

    // if s2 not empty then include/add
    if (s2length != 0)
    {
        Store_char[iterator] = s2[0];
        printInterleaving(s1, s2 + 1, Store_char, s1length, s2length -1, iterator + 1);
    }
}

// dma and print
void printoutput (char *s1, char *s2, int s1length, int s2length)
{
    // dnma
    char *Store_size = new char [((s1length + s2length + 1)*sizeof(char))];

    // Set the terminator for the output string
    Store_size[s1length + s2length] = '\0';

    // print
    printInterleaving(s1, s2, Store_size, s1length, s2length, 0);

    // free memory
    free(Store_size);
}

// Driver code
int main()
{
    char input1[] = "abc";
    char input2[] = "dfab";
    printoutput(input1, input2, strlen(input1), strlen(input2));
    return 0;
}
