#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "connection_list.h"


//adds to the list of connections
int connlist_add(ConnectionList* clist, int connfd){
	if (clist->count < MAX_CONNECTIONS)
	{
		clist->list[clist->count] = connfd;
		clist->count++;
		return 0;//success
	}
	else
	{
		return 1; //list is full
	}
}


int connlist_find_id(ConnectionList* clist, int connfd){
	for(int i = 0; i < clist->count; i++)
	{
		if (clist->list[i] == connfd)
		{
			return i+1;//return descriptor		
		}
	}
	return -1; //not found
}
