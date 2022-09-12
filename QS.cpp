#include <iostream>

class Node {

public:
  int Data;
  Node* Next;
  Node* Previous;


};


class Queue{
public:
  Node* Head;
  Node* Tail;
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
  Head = Head->Next;
  p->Next = NULL;
  p->Previous = NULL;
  return p;
}


void Add(int value){
  Node* newNode= new Node();
  newNode->Data = value;
  newNode->Next = NULL;
  newNode->Previous = NULL;

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
  Node* p = Head;
  Node *node = p;
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
