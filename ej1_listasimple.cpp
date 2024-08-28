#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node {
    int id;
    char name[30];
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
void pushNode(node **tail, node *newNode, int *length)
{
    if (*tail == NULL) {
        *tail = newNode;
        (*tail)->next = NULL;
        *length = *length + 1;
    }
    else {
        node *temp = *tail;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}

void insertNode(int position, node **tail, node *nodeToInsert, int *length){
    if (position >= *length || position < 0) return;

    node *currentNode = *tail;
    node *prevNode = NULL;
    for (int i = 0; i < position; i++){
      if(i == position - 1) {
        prevNode = currentNode;
      }
      currentNode = currentNode->next;
    }
    if(prevNode != NULL) prevNode->next = nodeToInsert;
    nodeToInsert->next = currentNode;
    if(position == 0) *tail = nodeToInsert;
    *length = *length + 1;
}
void insertNodeById(node **tail,int nodeId, node *nodeToInsert, int *length){
    node *currentNode = *tail;
    node *prevNode = NULL;
    cout << "Inserting node after: " << nodeId << endl;
    if((*tail)->id == nodeId){
      nodeToInsert->next = currentNode->next;
      (*tail)->next = nodeToInsert;
      length++;
      return;
    }
    do {
      prevNode = currentNode;
      currentNode = currentNode->next;
      if(currentNode == NULL) return;
    } while (prevNode->id != nodeId);
    prevNode->next = nodeToInsert;
    nodeToInsert->next = currentNode;
    *length = *length + 1;
}

void deleteNode(int position, node **tail, int *length){
    if (position >= *length || position < 0) return;
    if (position == 0) {
      *tail = (*tail)->next != NULL ? (*tail)->next : NULL;
      *length = *length - 1;
      return;
    }

    node *currentNode = *tail;
    node *prevNode = NULL;
    for (int i = 0; i < position; i++){
      if(i == position - 1) {
        prevNode = currentNode;
      }
      currentNode = currentNode->next;
    }
    if(prevNode != NULL) prevNode->next = currentNode->next;
    delete currentNode;
    *length = *length - 1;
}
void deleteNextNodeById(node **tail,int nodeId, int *length){
    node *currentNode = *tail;
    node *prevNode = NULL;

    if ((*tail)->id == nodeId) {
      *tail = (*tail)->next != NULL ? (*tail)->next : NULL;
      *length = *length - 1;
      return;
    }

    while (prevNode->id != nodeId){
      prevNode = currentNode;
      currentNode = currentNode->next;
      if(currentNode == NULL) return;
    }
    if(prevNode != NULL) prevNode->next = currentNode->next;
    delete currentNode;
    *length = *length - 1;
}

void printNode(node *tail) {
    node *temp = tail;
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

int main() {
    node *tail = NULL;
    node *newNode;
    int option;
    int position;
    int nodeId;
    int length = 0;


  while(option != 8){
    cout << "1. Add node" << endl;
    cout << "2. Insert node at a position" << endl;
    cout << "3. Insert node after a node by Id" << endl;
    cout << "4. Delete node at a position" << endl;
    cout << "5. Delete node by id" << endl;
    cout << "6. Print list" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter an option" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        {
          newNode = createNode();
          pushNode(&tail, newNode);
        }
        break;
    case 2:
        {
          cout << "Enter the position to insert the node" << endl;
          cin >> position;
          newNode = createNode();
          insertNode(position, &tail, newNode);
        }
        break;
    case 3:
        {
          cout << "Enter the id of the node to insert after" << endl;
          cin >> nodeId;
          newNode = createNode();
          insertNodeById(&tail, nodeId, newNode);
        }
        break;
    case 4:
        {
          cout << "Enter the position to delete the node" << endl;
          cin >> position;
          deleteNode(position, &tail);
        }
        break;
    case 5:
        {
          cout << "Enter the id of the node to delete" << endl;
          cin >> nodeId;
          deleteNextNodeById(&tail, nodeId);
        }
        break;
    case 6:
        {
          printNode(tail);
        }
        break;
    default:
        break;
    }
  }

    return 0;
}
