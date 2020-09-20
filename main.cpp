/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Grant Elliott
 *
 * Created on April 24, 2020, 4:19 PM
 */

#include <cstdlib>
#include<string.h>
#include <iostream>
#include "tree.h"
#include <locale>
using namespace std;

/*
 * 
 */
//----------------------------------------------
string FixWord(string word)
{
    // Loop over characters to fix word
    string result = "";
    for (int i=0; i<(int)word.length(); i++)
    {
        // Save special character
        if (word[i] == '\'')
            result += word[i];
        
        // Save lower case letters
        else if ((word[i] >= 'a') && (word[i] <= 'z'))
            result += word[i];
        
        // Save upper case letters as lower case letters
        else if ((word[i] >= 'A') && (word[i] <= 'Z'))
            result += word[i] - 'A' + 'a';
    }
    return result;
}
int main()
{
    // Create tree
    BinaryTree Tree;
    
    //Open the male name text file
    ifstream din;
    din.open("male.txt");
    string name="",input="";
    int count = 0, rank = 0;
    float percentage = 0.0;
    //Input the values
    din >> name >> count >> percentage >> rank;
    //Loop over the file and enter each entry
    while(!din.eof()){
        name = FixWord(name);
        Tree.Insert(name,count,percentage,rank);
        din >> name >> count >> percentage >> rank;
    }
    
    //Prompt the user to search for names. If the name is found, print out the information, else error.
	//Stops when the user types quit.
	//Capatilization does not matter.
    while(input!="quit"){
        cout<<"Enter a name to search for: ";
        cin>>input;
        input = FixWord(input);
        if (Tree.Search(input)==true){
            
        }else{
            cout<<"That name is not on the list of names."<<endl<<endl;
        }
    }
    Tree.Print();
   
   return 0;
}

