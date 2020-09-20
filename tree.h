/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef TREE_H
#define TREE_H

//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//-----------------------------------------------------------
// BinaryTree data node definition
//-----------------------------------------------------------
class Node
{
 public:
   string Name;
   int Count, Rank;
   float Percentage;
   Node *Left;
   Node *Right;
};

//-----------------------------------------------------------
// Define the BinaryTree class interface 
//-----------------------------------------------------------
class BinaryTree
{
 public:
   // Constructor functions
   BinaryTree();
  ~BinaryTree();

   // General binary tree operations
   bool Search(string Name);
   bool Insert(string Name, int Count, float Percentage, int Rank);
   bool Delete(string Name);
   void Print();

 private:
   // Helper functions
   void DestroyHelper(Node * Tree);
   bool SearchHelper(string Name, Node * Tree);
   bool InsertHelper(string Name,int Count,float Percentage, int Rank, Node * &Tree);
   bool DeleteNode(Node * &Tree);
   bool DeleteHelper(string Name, Node * &Tree);
   void PrintHelper(Node * Tree);

   // Tree pointer
   Node *Root;
};

#endif /* TREE_H */

