#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

void count_string (string &tmpstring, int &most_vowel, int &most_consonants, int &accent_character);

int main()
{
/*     int mymost_consonants = 0;
    int mymost_vowel = 0;
    int myaccent_character = 0; */
    map<int, string> WordResult;

    string array_of_string [] = {"strengthsaeiueouy", "ants 1ew", "turkey", "facetious"};
    int getArrayLength = sizeof(array_of_string)/sizeof(string);

    // storing values into 2D array (vowels, consonant, accen)
    // x = V[0], C[1], A[2] = 3 (fixed value)
    // y = array_of_string length = dynamic
    int storeVCA [getArrayLength][3]= 
    {
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}
    };
    // looping through the array_of_string[] and count vowels, consonant, and accent characters
    for (int i = 0; i < getArrayLength; i++)
    {
        int mymost_vowel = 0;
        int mymost_consonants = 0;
        int myaccent_character = 0;

        string getArrayWord = array_of_string[i];
    //    count and store vowels, consonant, and accent characters into a 2D array
        count_string(getArrayWord, mymost_vowel, mymost_consonants, myaccent_character);
        storeVCA [i][0] = mymost_vowel;
        storeVCA [i][1] = mymost_consonants;
        storeVCA [i][2] = myaccent_character;  
    }
   // look for max value in 2D array
   int tmp_tracking_max [getArrayLength];
    for (int row = 0; row < getArrayLength ; row++)
    {
        int tmp = 0;
        int max = 0;
        for (int column = 0; column < 3; column++)
        { 
            if(storeVCA[column][row] > max)
            {
               max = storeVCA[column][row];
               //tmp = column;
               tmp_tracking_max[row] = max;
            }
        }
        //cout << max << endl;
        WordResult.insert({max, array_of_string[row]});
    }//cout << tmp << endl;
    //cout << array_of_string[tmp] << endl;
    map<int, string>::iterator it;
    for (it = WordResult.begin(); it !=WordResult.end(); it++)
    {
        cout << "[" << (*it).first << ", " << (*it).second << "]" << endl;
    }

}

void count_string (string &inputWords, int &most_vowel, int &most_consonants, int &accent_character)
{
    for (int i = 0; i <inputWords.length(); i++)
    {
        if (inputWords.at(i) == 'a' || inputWords.at(i) == 'A' || inputWords.at(i) =='e' || inputWords.at(i) =='E' || inputWords.at(i) =='i' || inputWords.at(i) =='I' || inputWords.at(i) =='o' ||
            inputWords.at(i) =='O' || inputWords.at(i) =='u' || inputWords.at(i) =='U' || inputWords.at(i) =='y' || inputWords.at(i) =='Y' )
        {
            most_vowel++; 
        }
        else if ((inputWords.at(i)>='a' && inputWords.at(i)<= 'z') || (inputWords.at(i) >= 'A' && inputWords.at(i)<= 'Z')) 
        {
            most_consonants++;
        }
        else 
        { 
            accent_character++;
        }
    }
}
