#include <iostream>
#include <string.h>

using namespace std;



void count_string ( string &tmpstring, int &most_vowel, int &most_consonants, int &accent_character);

int main()
{
int mymost_consonants = 0;
int mymost_vowel = 0;
int myaccent_character = 0;

string array_of_string[] = {"strengths", "ants 1", "turkey", "facetious"};

string inputWordsw = array_of_string[3];

count_string(inputWordsw, mymost_vowel, mymost_consonants, myaccent_character);

cout << "vowel  " << mymost_vowel << endl;
cout << "consonant  " << mymost_consonants << endl;
cout << "Accent character  " << myaccent_character << endl;
    
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