#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node {
    int id;
    char name[30];
    int length;
    node *next;
};

node *createNode (){
    node *newNode;
    newNode=new(struct node);
    cout<<"Enter your id ";
    cin>>newNode->id;
    fflush(stdin);
    cout<<"Enter your name: ";
    cin>>newNode->name;
    newNode->next = NULL;
    return newNode;
}
void pushNode(node *tail, node *newNode)
{
        if (tail == NULL)
        {
            newNode->next = NULL;
            tail = newNode;
        }
        else
        {
            node *temp = tail;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
        }
}

void insertNode(int position, node *tail, node *nodeToInsert){
  if (position >= tail->length || position < 0) return;

  node *currentNode = tail;
  node *prevNode;
  for (int i = 0; i < position; i++){
    if(i == position - 1) {
      prevNode = currentNode;
    }
    currentNode = currentNode->next;
  }
  prevNode->next = nodeToInsert;
  nodeToInsert->next = currentNode;
}
void insertNodeById(node *tail,int nodeId, node *nodeToInsert){
  node *currentNode = tail;
  node *prevNode;
  while (currentNode->id != nodeId){
    if(currentNode->next == NULL) return;
    prevNode = currentNode;
    currentNode = currentNode->next;
  }
  prevNode->next = nodeToInsert;
  nodeToInsert->next = currentNode;
}

void deleteNode(int position, node *tail){
  if (position >= tail->length || position < 0) return;

  node *currentNode = tail;
  node *prevNode;
  for (int i = 0; i < position; i++){
    if(i == position - 1) {
      prevNode = currentNode;
    }
    currentNode = currentNode->next;
  }
  prevNode->next = currentNode->next;
  delete currentNode;
}
void deleteNodeById(node *tail,int nodeId){
  node *currentNode = tail;
  node *prevNode;
  while (currentNode->id != nodeId){
    if(currentNode->next == NULL) return;
    prevNode = currentNode;
    currentNode = currentNode->next;
  }
  prevNode->next = currentNode->next;
  delete currentNode;
}

void printNode(node *tail)
{
    struct node *temp = tail;
    cout<<"List content..."<<endl;
    while (temp != NULL)
    {
        cout<<"CC: "<<temp->id<<endl;
        cout<<"Name: "<<temp->name<<endl;
 		cout<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    node *tail = NULL;
    node *newNode;
    int option;
    int position;
    int nodeId;

    cout << "1. Add node" << endl;
    cout << "2. Insert node at a position" << endl;
    cout << "3. Insert node after a node by Id" << endl;
    cout << "4. Delete node at a position" << endl;
    cout << "5. Delete node by id" << endl;
    cout << "6. Print list" << endl;
    cout << "7. Exit" << endl;

  while(option != 8){
    cout << "Enter an option" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        newNode = createNode();
        pushNode(tail, newNode);
        break;
    case 2:
        cout << "Enter the position to insert the node" << endl;
        cin >> position;
        newNode = createNode();
        insertNode(position, tail, newNode);
        break;
    case 3:
        cout << "Enter the id of the node to insert after" << endl;
        cin >> nodeId;
        newNode = createNode();
        insertNodeById(tail, nodeId, newNode);
        break;
    case 4:
        cout << "Enter the position to delete the node" << endl;
        cin >> position;
        deleteNode(position, tail);
        break;
    case 5:
        cout << "Enter the id of the node to delete" << endl;
        cin >> nodeId;
        deleteNodeById(tail, nodeId);
        break;
    case 6:
        printNode(tail);
        break;
    default:
        break;
    }
  }

    return 0;
}
