#include <iostream>
#include <string.h>
#include <map>
using namespace std;

void count_string (string &tmpstring, int &most_vowel, int &most_consonants, int &accent_character);

int main()
{
/*     int mymost_consonants = 0;
    int mymost_vowel = 0;
    int myaccent_character = 0; */
    map<int, string> WordResult = {};

    string array_of_string [] = {"strengthsaeiueouy", "ants 1", "turkey", "facetious"};
    int getArrayLength = sizeof(array_of_string)/sizeof(string);

    // cout << getArrayLength;

    for (int i = 0; i < getArrayLength; i++)
    //for (int i = 0; i < 4; i++)
    {
        int  mymost_vowel = 0;
        int  mymost_consonants = 0;
        int myaccent_character = 0;

        string getArrayWord = array_of_string[i];
    //    cout << getArrayWord << endl;
        count_string(getArrayWord, mymost_vowel, mymost_consonants, myaccent_character);
        
        if (mymost_vowel >= mymost_consonants && mymost_vowel >= myaccent_character)
        {
            WordResult.insert({mymost_vowel, getArrayWord});
            cout << getArrayWord << " Has more Vowel " << '\t' << i << endl;
            
        }
        else if (mymost_consonants >= mymost_vowel && mymost_consonants > myaccent_character)
        {
            WordResult.insert({mymost_consonants, getArrayWord});
            cout << getArrayWord << " Has more Consonants " << '\t' << i << endl;
           
        }
        else 
        {
            WordResult.insert({myaccent_character, getArrayWord});
            cout << getArrayWord << " Accent  characters" << '\t' << i << endl;
           
        }

    }
    
    for (auto itr = WordResult.begin(); itr !=WordResult.end(); itr++)
    {
        cout << itr->first << '\t' << itr->second <<'\n';
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

