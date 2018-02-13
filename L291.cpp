  //Double linked lists

  //makes deleting much easier
struct node{
  int key;
  node* previous;
  node* next;
  node(int k, node *p, node *n){
    key = k;
    previous = p;
    next = n;
  }
};

int insertDouble(int lefVal, int val){
  //inserting a node into a double linked list after node where key = leftVal
  node *left = search(leftVal);
  node *d = new node(val, NULL, NULL);
  if(left == NULL){
    //add as the head
    d -> next = head; //why dont we need to pass head if we are using it as a statement
    head -> previous = d;
    head = d;
  }
  else if(left -> next == NULL){
    //add as tail
    left -> next = d;
    d -> previous = left;
    tail = d;
  }
  else{
    //add as middle node
    left -> next -> previous = d;
    d -> previous = left;
    d -> next = left -> next;
    left -> next = d;
    //order matters
  }
}

int deleteDouble(value){
  //head node case
  //tail node case
  //middle node case
  node -> previous -> next = node -> next;
  node -> next -> previous = node -> previous;
  delete[] node;a
}

//create three nodes
int main(){
  node *x = new node(4,NULL,NULL))
  node *x2 = new node(5,x,NULL)
  node *x3 = new node(6,x2,NULL)

  x -> next = x2;
  x2 -> next = x3;
}
