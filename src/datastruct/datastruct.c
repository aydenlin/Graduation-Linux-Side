#include "datastruct.h"
#include <malloc.h>

void list_insert(List_head *lh, List *e) {
	pthread_mutex_lock(&lh->locker);
	if (lh->head == NULL) {
		lh->head = e;
		lh->tail = e;	
	} else {
		lh->head->prev = e;
		e->next = lh->head;
		lh->head = e;
	}
	pthread_mutex_unlock(&lh->locker);
}

List * list_obtain(List_head *lh) {
	List * obtained = NULL;;
	pthread_mutex_lock(&lh->locker);
	if (lh->tail != NULL) {
		obtained = lh->tail;
		lh->tail = lh->tail->prev;
		if (lh->tail != NULL)
			lh->tail->next = NULL;
		else
			lh->head = NULL;
	}
	pthread_mutex_unlock(&lh->locker);
	return obtained;
}

void list_del(List_head *lh, List *e) {
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
	if (list == NULL)
		return NULL;
	return list->obj;
}

int is_empty(List_head *lh) {
	return lh->head == NULL && lh->tail == NULL;
}

void lh_init(List_head **lh) {
	*lh = (List_head *)malloc(sizeof(List_head));
	(*lh)->head = NULL;
	(*lh)->tail = NULL;
	if (pthread_mutex_init(&(*lh)->locker, NULL) != 0) {
		free(*lh);
	}
}
