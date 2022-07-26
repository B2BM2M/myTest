#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    string input1[3] = {"a", "b", "c"};
    string input2[3] = {"1", "2", "3" };
    vector<string> interleave;
    vector<string> store_combine_inputs;
    
    copy(begin(input1), end(input1), back_inserter(store_combine_inputs));
    copy(begin(input2), end(input2), back_inserter(store_combine_inputs));
    
    int input1_size = sizeof(input1) / sizeof(string);
    int input2_size = sizeof(input2) / sizeof(string);
    int arraypermutation = input1_size * input2_size;
    
    int counter = 0;
    while (arraypermutation !=0 && !store_combine_inputs.empty())
    {
        for (int i = 0; i < input1_size; i++)
        {
            if(input1[i] != input2[i])
            {
                interleave.push_back(input1[i]);
                interleave.push_back(input2[i]);
                arraypermutation--;
                store_combine_inputs.erase(store_combine_inputs.begin() + i); // remove 1 char to track how many left
            }
            else if (input1[i + 1] !=input2[i]) // move 1 char to the right of input1 array and check
            {
                interleave.push_back(input1[i + 1]);
                interleave.push_back(input2[i]);
                arraypermutation--;
                store_combine_inputs.erase(store_combine_inputs.begin() + (i+1)); // remove 1 char to track how many left
            }
            else if ((input1[i] !=input2[i + 1])) // move 1 char to the right of input2 array and check
            {
                interleave.push_back(input1[i]);
                interleave.push_back(input2[i + 1]);
                arraypermutation--;
                store_combine_inputs.erase(store_combine_inputs.begin() + (input1_size + i + 1 )); // starting from end of input1 + i + 1, remove position
            }
            else if (input1[i - 1] !=input2[i]) // move 1 char to the left of input1 array and check
            {
                interleave.push_back(input1[i - 1]);
                interleave.push_back(input2[i]);
                arraypermutation--;
                store_combine_inputs.erase(store_combine_inputs.begin() + (i-1)); // remove 1 char to track how many left
            }
            else if ((input1[i] !=input2[i - 1])) // move 1 char to the right of input2 array and check
            {
                interleave.push_back(input1[i]);
                interleave.push_back(input2[i - 1]);
                arraypermutation--;
                store_combine_inputs.erase(store_combine_inputs.begin() + (input1_size + i - 1 )); // starting from end of input1 + i - 1, remove position
            }
            else 
            {
                counter = 0;
                arraypermutation++;
            }
            cout << interleave[i];
        }
        counter++;
        arraypermutation--;
    
    }
    

    for (auto i : store_combine_inputs)
    {
        cout << i << endl;
    }
    




}