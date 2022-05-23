#include "threadCollection.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>


bool is_empty(){
  return threadNodeList.first == NULL;
}
void push_back(pthread_t thread){
  printf("%s","Added");
  threadNode *tmpNode;
  tmpNode = (threadNode*)malloc(sizeof(threadNode));
  tmpNode->nodeThread = thread;
  tmpNode->next = NULL;
  if(threadNodeList.first == NULL || threadNodeList.head == NULL){
    threadNodeList.first = tmpNode;
    threadNodeList.head = tmpNode;
  }
  else{
    threadNode *p;
    p = threadNodeList.head;
    while(p->next != NULL){ 
      p = p->next;
    }
    p->next = tmpNode;
  }
}
int countOfThread(){
	int count = 0;
	
	while(threadNodeList.head != NULL){
			threadNodeList.head = threadNodeList.head->next;
			count += 1; 
	}
	return count;
}
void clearList(){
 printf("%s","CLEAR LIST");
  if(threadNodeList.first == NULL  || threadNodeList.head == NULL){
    return;
  }
  else{
	  threadNode *p ;  
    while(threadNodeList.head != NULL){
      p = threadNodeList.head;
      threadNodeList.head = threadNodeList.head->next;
      pthread_cancel(p->nodeThread);
      //pthread_kill(p->nodeThread,0);
      free(p);
    }
  }
}
