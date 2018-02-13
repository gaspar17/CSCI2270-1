#include <iostream>
using namespace std;

//definitions in .h file
struct Node {
			int id=-1;
			Node* next = nullptr;
};

class SLL {
	private:
		Node* createNode(int,Node*);
		Node* head = nullptr;
		Node* tail = nullptr;
		void deleteList();

	public:
		SLL(); //default constructor
		SLL(int);	//overloaded constructor
		//destructor, called when object is deleted
		~SLL();


		bool insertNodeAtEnd(int);
		//bool deleteNode(int);
		void printList();
};
