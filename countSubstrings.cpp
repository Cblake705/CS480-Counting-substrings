//countsubstrings.cpp
//made by christian blake
//red id: 824904815
#include "tree.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char **argv) {
    //Check for proper number of command lines
    if(argc != 3){
        //error message
        std::cerr << "Proper form: " << argv[0] << " <vocabulary file> <test file>" << std::endl;
        return EXIT_FAILURE;
    }
    //open vocab file for reading
    std::ifstream dictstream(argv[1]);
    //check if opened properly
    if(!dictstream.is_open()){
        std::cerr << "Vocab folder unable to open." <<std::endl;
        return EXIT_FAILURE;
    }
    
    std::vector<std::string> vocabulary;
    std::string line;
    //read lines in from the vocab file and insert into vocabulary vector
    while (std::getline(dictstream, line)){
        //check for non empty line
        if (!line.empty()){
            vocabulary.push_back(line);
        }
    }
    dictstream.close();
    //open testfile and check if it is open
    std::ifstream testFile(argv[2]);
    if(!testFile.is_open()){
        std::cerr << "test file folder unable to open." <<std::endl;
        return EXIT_FAILURE;
    }
    //Read in each line from testFile, then build 
    //trie tree using insert and iterate through each vocabulary
    //word increasing the count and outputting # of vocab words found.
    while(std::getline(testFile, line)){
        if (!line.empty()){
            //create a node
            CharNode* root = new CharNode;
            //get first character of testfile word
            const char* testString = line.c_str();
            //insert word into trie tree
            insert(root, testString);
            //count for # of vocab words found
            int count = 0;
            //search each word in vocabulary file
            for(const auto& vWord : vocabulary){
                if(search(root, vWord.c_str())){
                    count++;
                }
            }
            //print the count
            std::cout << count << '\n';
            
        }
    }
    testFile.close();
    return EXIT_SUCCESS;
}