#include "datastruct.h"
#include <malloc.h>
#include "tools.h"
#include "errno.h"

#define _LIST_OBTAIN_LOOP_MAXNUM_ 10
extern 
void list_insert(List_head *lh, List *e) {
	int before = list_is_empty(lh);
	pthread_mutex_lock(&lh->obtain_locker);
	if (lh->head == NULL) {
		lh->head = e;
		lh->tail = e;	
	} else {
		lh->head->prev = e;
		e->next = lh->head;
		lh->head = e;
	}
	if (before)
		pthread_cond_signal(&lh->empty_cond);
	pthread_mutex_unlock(&lh->obtain_locker);
}

List * list_obtain(List_head *lh) {
	int count = 0;
	List * obtained = NULL;
		
	while (list_is_empty(lh)) { 
		if (count++ >= _LIST_OBTAIN_LOOP_MAXNUM_)
			goto TIMEOUT;
		message("list_obtain in loop");
		pthread_cond_wait(&lh->empty_cond, &lh->empty_locker);
	}
	message("list_obtain after pthread_cond_wait");
	pthread_mutex_lock(&lh->obtain_locker);
	if (lh->tail != NULL) {
		obtained = lh->tail;
		lh->tail = lh->tail->prev;
		if (lh->tail != NULL)
			lh->tail->next = NULL;
		else
			lh->head = NULL;
	}
	pthread_mutex_unlock(&lh->obtain_locker);
	return obtained;
TIMEOUT:
	errno = 1;
	return NULL;
}


int list_is_empty(List_head *lh) {
	if (lh->head == NULL)
		return TRUE;
	else 
		return FALSE;
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
	if (pthread_mutex_init(&(*lh)->empty_locker, NULL) != 0)
		free(*lh);
	if (pthread_mutex_init(&(*lh)->obtain_locker, NULL) != 0)
		free(*lh);
	if (pthread_cond_init(&(*lh)->empty_cond, NULL) != 0)
		free(*lh);
}
