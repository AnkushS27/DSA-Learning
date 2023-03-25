#include <iostream>

using namespace std;

class trieNode{
    public:
    char data;
    trieNode* children[26];
    bool isTerminal;
    
    trieNode(char ch){
        data = ch;
        
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        
        isTerminal = false;
    }
};

class Trie{
    public:
    trieNode* root;
    
    Trie(){
        root = new trieNode('\0');
    }
    
    void insertUtil(trieNode* root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        
        //assumption, word will be in caps
        int index = word[0] - 'A';
        trieNode* child;
        
        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        //absent
        else{
            child = new trieNode(word[0]);
            root->children[index] = child;
        }
        
        //recursive call
        insertUtil(child, word.substr(1));
    }
    
    void insertWord(string word){
        insertUtil(root, word);
    }
    
    // T.C. of insertion, search and deletion = O(L) ; L is the length of word
    
    bool searchUtil(trieNode* root, string word){
        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }
        
        int index = word[0] - 'A';
        trieNode* child;
        
        if(root->children[index] != NULL){   //present
            child = root->children[index];
        } else {                             //absent
            return false;
        }
        
        //recursive call
        return searchUtil(child, word.substr(1));
    }
    
    bool searchWord(string word){
        return searchUtil(root, word);
    }
    
    void deleteUtil(trieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }
        
        int index = word[0] - 'A';
        trieNode* child;
        
        if(root->children[index] != NULL){   //present
            child = root->children[index];
        }
        
        deleteUtil(child, word.substr(1));
    }
    
    void deleteWord(string word){
        if(searchWord(word)){
            deleteUtil(root, word);
            cout<<"Deleted"<<endl;
        } else {
            cout<<"Word not found"<<endl;
        }
    }
    
};

int main()
{
    Trie* t = new Trie();
    
    t->insertWord("ABCDE");
    
    cout<<"Present or not "<<t->searchWord("ABCDE")<<endl;
    
    t->deleteWord("ABCDE");
    
    cout<<"Present or not "<<t->searchWord("ABCDE")<<endl;

    return 0;
}
