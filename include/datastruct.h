#ifndef _LIST_H_
#define _LIST_H_

#include <pthread.h>
#include <malloc.h>
#include "types.h"


#define _TYPE_ byte *
#define RELEASE_QUEUE_CAPACITY (sizeof(List)*100)
#define INIT_LIST_ELEMENT(list, val) (({do { \
	list = (List *)malloc(sizeof(List)); \
	list->obj = val; \
	list->prev = NULL; \
	list->next = NULL; \
} while(0);}), list)

typedef struct list {
	struct list *prev;
	struct list *next;
	_TYPE_ obj;
} List;

typedef struct list_head {
	pthread_mutex_t empty_locker;
	pthread_mutex_t obtain_locker;
	pthread_cond_t  empty_cond;
	List *head;
	List *tail;
	List **release_queue;	
} List_head;

int list_is_empty(List_head *lh);
List * list_obtain(List_head *lh);
void lh_init(List_head **lh);
// True if equal, False if not equal
int equal(_TYPE_ former, _TYPE_ latter);
void list_insert(List_head *lh, List *e);
void list_del(List_head *lh, List *e);
List * list_search(List_head *lh, _TYPE_ e);
_TYPE_ list_get_obj(List *list);
int is_empty(List_head *lh);

#endif /* _LIST_H_ */
