#ifndef _LIST_H
#define _LIST_H

struct list_head {
	struct list_head *next, *prev;
};

//LIST_HEAD_INIT
#define LIST_HEAD_INIT(name) { &(name), &(name) }

//LIST_HEAD
#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

//list_entry
#define offsetof(TYPE,MEMBER) ((unsigned int) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({    \
		const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
		(type *)( (char*)__mptr - offsetof(type,member) );})

#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

//list_for_each
#define list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)

void INIT_LIST_HEAD(struct list_head *list);
void list_add(struct list_head *new, struct list_head *head);
void list_add_tail(struct list_head *new, struct list_head *head);
void list_del(struct list_head *entry);

#endif
