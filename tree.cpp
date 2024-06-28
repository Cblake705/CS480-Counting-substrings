//tree.cpp
//made by christian blake
//red id: 824904815
#include "tree.h"
#include <iostream>
#include <cctype>
//function to return index of character
int charIndex(char letter) {
    //index null terminator
    if (letter == '\0') return 30;
    //map lowercase to index 0-25
    //use ascii subtraction
    if (letter >= 'a' && letter <= 'z') return letter - 'a';
    //map uppercase to same index
    if (letter >= 'A' && letter <= 'Z') return letter - 'A';
    //map special charcters.
    if (letter == ' ') return 26;
    if (letter == '/') return 27;
    if (letter == '-') return 28;
    if (letter == '_') return 29;
    //otherwise return invalid
    return -1;
}
//helper function for insert
bool insertSuffix(CharNode* currentNode, const char* stringBeingInserted){
//base case for end of string
    if(!stringBeingInserted || *stringBeingInserted == '\0'){
        currentNode->next[30] = new CharNode();
        return true;
    }
    //loop through string and subsequent substrings recursively
        int index = charIndex(*stringBeingInserted);
        //skip invalid char
        if (index >= 0) {
        //create new node if next node index is empty
            if (!currentNode->next[index]){
                currentNode->next[index] = new CharNode();
            }
            return insertSuffix(currentNode->next[index], stringBeingInserted + 1);
        }
        //invalid character skip
        return insertSuffix(currentNode, stringBeingInserted + 1);
}
//insert function
//sti = string to insert and build trie tree
bool insert(CharNode* currentNode, const char* stringBeingInserted) {
    //check for string
    if (!stringBeingInserted){
        return false;
    }
    //create full string then iterate
    for (const char* suffix = stringBeingInserted; *suffix; ++suffix){
        if(!insertSuffix(currentNode,suffix)){
            return false;
        }
    }
    return true;
}


bool search(CharNode* currentNode, const char* strBeingSearched){
    //check for empty string or nullptr
    if(!strBeingSearched || *strBeingSearched == '\0'){
        return false;
    }
    CharNode* node = currentNode;
    //search through string being searched iteratively
    while(*strBeingSearched){
        int index = charIndex(*strBeingSearched);
        //no invalid char in insert return false
        if(index == -1){
            return false;
        }
        node = node->next[index];
        //check to see if next node does not exist
        if (!node){
            return false;
        }
        //check to see if next node does not exist
        ++strBeingSearched;
    }
    return true;
}