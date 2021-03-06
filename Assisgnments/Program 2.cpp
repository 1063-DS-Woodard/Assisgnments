// Danny Woodard 
// 4/4/18
// 1063 Data Structures
// Email: dannyrwoodard@yahoo.com					    
// Semester: Spring 2018                                                    
// Intructor: Griffin   
// Description of Program:Description:      
// This program creates a priority list based queue using a class with methods
// that allows the user to push/pop animal names based on commands in
// the input_data.txt file.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


// Struct holds the node

struct Node {
	string val;
	Node *next;
	Node() {
		val = " ";
		next = NULL;
	}
	Node(string v) {
		val = v;
		next = NULL;
	}
};

// ClassName - Queue
// uses nodes to create a list based queue with
// a linked list to aid in pushing and popping items
//  to and from the queue

// Methods for the class:
// void Queue()
// void read
// string pop()
// void push
// bool empty()
// void print()
class Queue {
private:
	Node *Front;
	Node *Rear;
	string command;
	string word;
	ifstream cin;
	ofstream cout;

public:
	//FunctionName :Queue
	//Description:This is the constructor
	//Params:None
	//Returns: None
	Queue() {
		Front = Rear = NULL;
		cin.open("input_data.txt");
		cout.open("priorQ_data.txt");
	}

	// FunctionName :readFile
	// Description: Reads commands and either performs a push or pop method
	// Params: None
    // Returns: item removed
		void readFile() {
		int i = 1;

		cout << "Animals Popped off the Queue : " << endl << endl;

		while (!cin.eof()) {
			cin >> command >> word;

			if (!command.compare("push")) {
				push(word);
			}
			if (!command.compare("pop")) {
				cout << i << " " << pop() << endl;
				i++;

			}
		}

		cout << endl;
	}




	// FunctionName :LengthQueue
	// Description:Sorts the words in the queue based the length of the word.
	// Params: None
	// Returns: nothing

	void LengthQueue() {
		{
			Node *temp = Front;
			if (empty())
			{              // Has no return value
				return;
			}
			//Prepares the words to swap if needed
			while (temp->next != NULL)
			{
				string firstWord = temp->val;
				string secondWord = temp->next->val;

				//If the first word is longer than the next word
				if (firstWord.length()>secondWord.length())
				{
					temp->val = secondWord;
					temp->next->val = firstWord;
				}


				//If the first word is equal in length to the
				//second word 
				else if (firstWord.length() == secondWord.length())
				{
					if (firstWord>secondWord)
					{
						temp->val = secondWord;
						temp->next->val = firstWord;
					}
				}
				temp = temp->next;
			}
		}

		cout << endl;
	}


	//FunctionName :Pop
	//Description:This method removes an item from the list
	//Params: None
	//Returns:The String
	string pop() {
		if (!empty())
		{
			Node *temp = Front;   // temp pointer so we can delete node
			string v = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;		  // give mem back to system
			return v;
		}
		else {
			cout << " Error: cannot pop off empty queue." << endl;
			return " ";
		}
	}


	// FunctionName :Push
	// Description:This method adds an item to the list and begins to sort the
	// list everytime a new item is added via the sort method
	// Params:string v - the item to be added
	// Returns:none

	void push(string v) {
		Node *n = new Node(v);

		// handle the empty case
		if (empty()) {
			Front = n;
			Rear = n;
		}
		else {
			// not empty add to rear
			Rear->next = n;
			Rear = n;
		}
	}



	// FunctionName :Bool Empty
	// Description: We need to check if the list is empty or not
	// Returns: Returns true/false
	bool empty() {
		return (Front == NULL);
	}

	//FunctionName: String item
	//Description:Returns the first item in the queue
	//Params :none
	//Returns:string
	string item()
	{
		// Checks the first item in queue and then returns it
		while (!empty())
		{
			return Front->val;
		}
		return "";
	}



	//FunctionName : PrintFile
	//Description: Prints all the items currently in the queue to an outfile
	//Parameters: 
	//Returns:none
	void print() {
		cout << "Animals Remaining in the Queue : " << endl << endl;
		Node *temp = Front;
		while (temp) {
			cout << temp->val << "\n";
			temp = temp->next;

		}
		cout << endl;
	}
};
int main() {
	Queue Q;
	Q.readFile();
	Q.print();

}

