// Header file for TRIE DATA STRUCTURE
// TRIE IS A KIND OF TREE USED TO STORE A SET OF WORDS
#include<string>
using namespace std;
// class to make new individual nodes
class TrieNode{
	public:
		// to store a specific word in a node
		char data;
		// make a node which will point 26 nodes of different letters
		TrieNode **children;
		// used to search whether the item is present or not
		bool isTerminal;
		// constructor to initialize
		TrieNode(char data){
			this->data=data;
			// making 26 nodes to point on 26 distinct letters
			children=new TrieNode*[26];
			for(int i=0;i<26;i++)
				children[i]=NULL;
			// to insert the distinct letters
			isTerminal=false;
		}
		
};
class Trie{
	TrieNode *root;
	public:
		Trie(){
			root=new TrieNode('\0');
		}
		void Insert(TrieNode *root,string data){
			if(data.size()==0){
				root->isTerminal=true;
				return;
			}
			// getting the index of the node
			int index=data[0]-'a';
			TrieNode *child;
			// it indicates that letter is already their so no need to make a new node
			if(root->children[index]!=NULL){
				child=(root->children[index]);
			}
			// that letter is not there in the trie
			else{
				child=new TrieNode(data[0]);
				root->children[index]=child;
			}
			root->isTerminal=true;
			//this indicates that letter is inserted, so that to make things easier to searcha subset or a string
			// Recursion to insert the letter
			Insert(child,data.substr(1));
		}
		void Insertword(string data){
			Insert(root,data);
		}
		bool Searchword(TrieNode *root,string data){
			// if that word is their then only size becomes 0 after every recursive steps as we are taking substring from 1 to the size in each recursive steps
			if(data.size()==0)
				return root->isTerminal;
			// to get index of the node
			int index=data[0]-'a';
			TrieNode *child;
			// if the string is more than the wortd given or the data is not their in the trie
			if(root->children[index]==NULL)
				return false;
			child=root->children[index];
			// recursive step
			return Searchword(child,data.substr(1));
		}
		bool Search(string data){
			return Searchword(root,data);
		}
		void Remove(TrieNode *root,string data){
			if(data.size()==0){
				root->isTerminal=false;
				return;
			}
			int index=data[0]-'a';
			TrieNode *child;
			if(root->children[index]!=NULL){
				child=root->children[index];
			}
			else{
				return;
			}
			Remove(child,data.substr(1));
			if(root->isTerminal==false){
				for(int i=0;i<26;i++){
					if(child->children[i]!=NULL)
						return;
				}
			}
			delete child;
			child->children[index]=NULL;
		}
		void Remove(string data){
			Remove(root,data);
		}
};		
