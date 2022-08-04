#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout<<"Hello World"<<endl;
    unordered_map<string, vector<string>> edges;
    unordered_map<string, bool> hasParent;
    edges["mammal"].push_back("feline");
   // hasParent["a"] = TRUE;
    edges["mammal"].push_back("canine");
    edges["mammal"].push_back("monotreme");
    //edges["dog"].push_back("d");
    edges["feline"].push_back("jaguar");
    edges["feline"].push_back("lion");
    edges["feline"].push_back("cat");

    cout << edges["feline"][0] << ", " << edges["feline"][1] << ", "<< edges["feline"][2] << ", ";
  

}
