#include<string>
#include<bits/stdc++.h>
//#include<dos>
#include<conio.h>
#include<unistd.h>
#include"Trie.h"
using namespace std;	
int main(){
	int h;
	int n;
	// No of rounds to be performed, each round contains 2 chances for each player
	cout << "Enter the number of rounds in the game : ";
	cin >> n;
	int m=n*2;
	//randomly selecting which player to select players
	int r=rand()%2;
	cout << "The first chance to set the words is player : " << r+1 << endl; 
	// vector to store the scores of both player
	vector<float> ans(2);
	ans[0]=0;
	ans[1]=0;
	while(m--){
		Trie T;
		if(r==1){
			int x;
			// enter the number of words the player wants to enter
			cout << "Enter the set of strings to be inserted by the player 2" << endl;
			cin >> x;
			int a=x;
			h=a;
			// to store the set of strings in arrays of strings
			vector<string> temp;
			//Now the player will write the set of words
			cout << "PLayer 2 suggested words : ";
			while(a--){
				string input;
				cin >> input;
				//clear the strings so that another player cannot see the words suggested
				system("cls");
				// Inserting the strings in a Trie
				T.Insertword(input);
				temp.push_back(input);
				}
			// Now the hints given by the player so that another player can guess the words
			string hint2;
			int hint1;
			cout << "Player 2 please give some hint to player 2"<<endl;
			while(h--){
				cout << "No of words : ";
				cin >> hint1;
				cin.ignore();
				cout << "The meaning of the word or word use to describe something : "<<endl;
				getline(cin,hint2);
			}
			// Now another player will guess the words to gain points
			cout << "Now player 1 will sugest the words : ";
			while(x--){
				string input;
				cin >> input;
//				if(T.Search(input[0]))
//					ans[1]++;
				// temp variable is used to decide the accuracy of the player
				int temp=0;
				for(int i=0;i<input.size();i++){
					// to check whether the player has suggested the word correctly or not
					if(T.Search(input.substr(0,i))==false and i==0 ){
						temp=2;
						break;
					}
					if(T.Search(input.substr(0,i))==false){
						temp=1;
						break;
					}
					else{
						// for consecutive correct words a player will recieve +0.5 points
						ans[1]=ans[1]+0.5;
					}

				}
				if(temp==1 and ans[1]!=0)
					cout << "The word that player 1 suggested was partially correct " << endl;
				else if(temp==2 and ans[1]==0){
					cout << "Incorrect word" << endl;
				}
				else{
					// if the player has guessed the words correctly then add +1 point as well
					ans[1]=ans[1]+1;
					cout << "The word that player 1 has suggested was correct  and so he/she recieved " << ans[1] << " points " << endl;
				}
			}
			// Removing all the strings so that same word be repeated and so that during guessing it should not create ambiguity
			for(int i=0;i<temp.size();i++)
				T.Remove(temp[i]);
			// after the 1st innings we should change the value of r so that another person can give the word
			r=0;
		}
		else{
			// Now we will repeat the steps that were given for the previous player
			int x;
			cout << "Enter the set of strings to be inserted by the player 1" << endl;
			cin >> x;
			int a=x;
			h=a;
			vector<string> temp;
			cout << "Player 1 will give the words : ";
			while(a--){
				string input;
				cin >> input;
				system("cls");
				cout << endl;
				T.Insertword(input);
				temp.push_back(input);
			}
			cout << "Player 2 please give some hint to player 1"<<endl;
			string hint1,hint2;
			while(h--){
				cout << "No of words : ";
				cin >> hint1;
				cin.ignore();
				cout << "The meaning of the word or word use to describe something : "<<endl;
				getline(cin,hint2);
			}
			cout << "Now player 2 will sugest the words : ";
			while(x--){
				string input;
				cin >> input;
//				if(T.Search(input[0]))
//					ans[0]++;
				int temp=0;
				for(int i=0;i<input.size();i++){
					if(T.Search(input.substr(0,i))==false and i==0){
						temp=2;
						break;
					}
					if(T.Search(input.substr(0,i))==false){
						temp=1;
						break;
					}
					else
						ans[0]=ans[0]+0.5;
				}
				if(temp==1 and ans[0]!=0)
					cout << "The word that player 2 suggested was partially correct " << endl;
				else if(ans[0]==0){
					cout << "Incorrect word"<< endl;
				}
				else{
					ans[0]=ans[0]+1;
					cout << "The word that player 2 has suggested was correct  and so he/she recieved " << ans[1] << " points " << endl;
				}
			}
			for(int i=0;i<temp.size();i++)
				T.Remove(temp[i]);
			r=1;
		}
	}
// 	system("cls");
 	// showing the points of each player
	cout << "The points are : " << endl;
	cout << "Player 1 : " << ans[0] << endl;
	cout << "Player 2 : " << ans[1] << endl;
	// Comparing the points to determine the winner of the game
	if(ans[0] > ans[1]){
		cout << "Player 1 is the winner " << endl;
	}
	else if (ans[0] < ans[1]){
		cout << "Player 2 is the winner " << endl;
	}
	else{
		cout << "This is a draw " << endl;
	}
	return 0;
}
