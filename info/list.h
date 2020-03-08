#ifndef LIST_H_
#define LIST_H_

typedef struct Node
{
	char *name;
	int age;
	int work_age;
	int salary;
	struct Node *pNext;
}NODE;

typedef struct
{
	NODE *top;
	NODE *bottom;
}stack;

void init(stack *s);
int is_empty(stack *s);
int push(stack *s, NODE *node);
int pop(stack *s, NODE *node);
void clear(stack *s);
void traverse(stack *s);
int query_name(stack *s, const char *name);
int query_modifi(stack *s, const char *name);

#endif /* LIST_H_ */
