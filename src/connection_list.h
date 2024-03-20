#ifndef CONNECTION_LIST_H
#define CONNECTION_LIST_H

#define MAX_CONNECTIONS 32

typedef struct {

	int list[MAX_CONNECTIONS];
	int count;

} ConnectionList;

int connlist_add(ConnectionList* clist, int connfd);
int connlist_find_id(ConnectionList* clist, int connfd);

#endif
