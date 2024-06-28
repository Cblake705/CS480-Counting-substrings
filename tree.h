/*tree.h*/
/*Created by Christian Blake on 9/1/2023 */
//made by christian blake
//red id: 824904815
/* valid chars: a-z, ', -, _, single space, terminator of string */
/* always explicitly initialize all next child nodes to NULL or nullptr */
#ifndef TREE_H
#define TREE_H
#define NCHILD 31
typedef struct CharNode{
    struct CharNode *next[NCHILD] = {nullptr};
}CharNode;
bool insert(CharNode* currentNode, const char* stringBeingInserted);
bool search(CharNode* currentNode, const char* strBeingSearched);
bool insertSuffix(CharNode* currentNode, const char* strBeingInserted);
#endif // TREE_H