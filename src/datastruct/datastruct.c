#include "datastruct.h"
#include <malloc.h>

void list_insert(List_head *lh, List *e) {
	if (lh->head == NULL) {
		lh->head = e;
		lh->tail = e;	
	}
	else {
		lh->head->prev = e;
		e->next = lh->head;
		lh->head = e;
	}
}

List * list_obtain(List_head *lh) {
	List * obtained = NULL;;
	if (lh->tail != NULL) {
		obtained = lh->tail;
		lh->tail = lh->tail->prev;
		if (lh->tail != NULL)
			lh->tail->next = NULL;
		else
			lh->head = NULL;
	}
	return obtained;
}

void list_delete(List_head *lh, List *e) {
	if (e->prev != NULL)
		e->prev->next = e->next;
	else 
		lh->head = e->next;
	if (e->next != NULL)
		e->next->prev = e->prev;
	free(e);
}

List * list_search(List_head *lh, _TYPE_ e) {
	List *iterator = lh->head;
	while (iterator != NULL) {
		if (equal(iterator->obj, e))
			return iterator;
		iterator = iterator->next;
	}
	return NULL;
}

int equal(_TYPE_ former, _TYPE_ latter) {
	return former == latter;
}

_TYPE_ list_get_obj(List *list) {
	return list->obj;
}

int is_empty(List_head *lh) {
	return lh->head == lh->tail == NULL;
}
