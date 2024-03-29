#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* lista1=(List*)malloc(sizeof(List));
  lista1->head=NULL;
  lista1->tail=NULL;
  lista1->current=NULL;
  return lista1;
}

void * firstList(List * list) {
  if(list->head !=NULL){
    list->current=list->head;
    return list->head->data;
  }else{
    return NULL;
  }
  

}

void * nextList(List * list) {
  if( list->current !=NULL){
    list->current=list->current->next;
  }
  if( list->current !=NULL){
    return list->current->data;
  }else{
    return NULL;
  }
}

void * lastList(List * list) {
  if(list->tail!=NULL){
    list->current=list->tail;
    return list->tail->data;
  }else{
    return NULL;
  }
}

void * prevList(List * list) {
  if(list->current != NULL){
    list->current=list->current->prev;
    
  }
  if(list->current != NULL){
    return list->current->data;
  }else{
    return NULL;
  }  
  
}

void pushFront(List * list, void * data) {
  Node * nodo1=createNode(data);
  if(list->head !=NULL){
    nodo1->next=list->head;
    list->head->prev=nodo1;
    list->head=nodo1;
    
  }else{
    list->head=nodo1;
    list->tail=nodo1;
  }
  list->current=nodo1;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node * nodo3=createNode(data);
  if(list->current->next != NULL){
    nodo3->next=list->current->next;
    nodo3->next->prev=nodo3;

    nodo3->prev=list->current;
    list->current->next=nodo3;
  }else{
    list->tail=nodo3;

    nodo3->prev=list->current;
    list->current->next=nodo3;
  }
  
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  Node* nn = list->current;
  if(list->current->next !=NULL){
    nn->next->prev=nn->prev;
  }else{
    list->tail=nn->prev;
    
  }
  if(list->current->prev !=NULL){
    nn->prev->next=nn->next;
  }else{
    list->head=nn->next;
    
  }
  return list->current->data;
  
}
  
  
  

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}