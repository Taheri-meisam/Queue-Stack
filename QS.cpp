#include <iostream>

class Node {
public:
  int Data;
  Node* Next; // points to next node 
  Node* Previous; // points to previous point 
};


class Queue{
public:
  Node* Head; // begining of the list 
  Node* Tail; // last element 
  int size;
Queue(){
  Head = NULL;
  Tail = NULL;
  size = 0;
}


Node* Deq(){
  Node* p = Head;
  if (p==NULL){
    std::cout << "Queue is Empty!!!"<<std::endl;
    return 0;
  }
  Head = Head->Next; // goes to the next element 
  p->Next = NULL;
  p->Previous = NULL;
  //delete p;
  return p; // you can return the node or just delete it here 
  //return if you are plannig to use that node // for example printing it 
}


void Add(int value){
  Node* newNode= new Node(); 
  newNode->Data = value;
  //first make next and previous pointers null
  newNode->Next = NULL;
  newNode->Previous = NULL;
  // if the list is empty head and tail are the same and point to the new element
  if(Head == NULL){
    Head = newNode;
    Tail = Head;
  }else {
    newNode->Previous = Tail;
    Tail->Next = newNode;
    Tail = newNode;
  }
  size++;
}

void printQ(){
  //Node* p = Head;
  Node *node = Head;
  while (node!=Tail){
    std::cout << node->Data << " ";
    node= node->Next;
  }
}

~Queue(){
  Node* p = Head;
  Node* temp = p;
  while(p!=NULL){
    temp = p;
    delete p;
    p=temp->Next;
    delete temp;
  }
}
};

int main(){
  Queue *q1 = new Queue();
  q1->Add(10);
  q1->Add(20);
  q1->Add(30);
  q1->Add(40);

  q1->printQ();
  Node* p2 = q1->Deq();
  q1->printQ();
  return 0;
}
