#ifndef _LIST_H_
#define _LIST_H_

#include <malloc.h>
#include "types.h"

#ifndef NULL
#define NULL 0
#endif /* NULL */

#define _TYPE_ byte *
#define INIT_LIST_ELEMENT(list, val) do { \
	list = (List *)malloc(sizeof(List)); \
	list->obj = val; \
	list->prev = NULL; \
	list->next = NULL; \
} while(0)

typedef struct list {
	_TYPE_ obj ;
	struct list *prev;
	struct list *next;
} List;

typedef struct list_head {
	List *head;
	List *tail;
} List_head;

// True if equal, False if not equal
int equal(_TYPE_ former, _TYPE_ latter);
void list_insert(List_head *lh, List *e);
void list_delete(List_head *lh, List *e);
List * list_search(List_head *lh, _TYPE_ e);
_TYPE_ list_get_obj(List *list);
int is_empty(List_head *lh);

#endif /* _LIST_H_ */
