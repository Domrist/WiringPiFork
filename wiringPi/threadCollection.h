//remak thread collection onto pointers
#include <stdbool.h>/////////////
#include <pthread.h>

#ifndef __THREAD_COLLECTION_H__
#define __THREAD_COLLECTION_H__

typedef struct Node{ ////////////////////////////////////////////////////thread collector that cotains every interrupts thread
  pthread_t nodeThread;
  struct Node *next;
}threadNode;

typedef struct nodeList{
	threadNode *first,*head;
}mainList;	

mainList threadNodeList;

#ifdef __cplusplus
	extern "C"{
#endif
		extern bool is_empty();
		extern void push_back(pthread_t thread);
		extern void clearList();
		extern int countOfThread();
#ifdef __cplusplus
	}
#endif

#endif
