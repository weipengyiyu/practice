#include "main.h"

/*创建一个空栈*/
void init(stack *s)
{
	s->top = (NODE*)malloc(sizeof(NODE));
	if(NULL != s->top)
	{
		s->bottom = s->top;
		s->top->pNext = NULL;
	}
	else
	{
		printf("动态内存分配失败！");
		exit(-1);
	}
}

int is_empty(stack *s)
{
	return (s->bottom == s->top) ? 1 : 0;
}

int push(stack *s, NODE *node)
{
	NODE *pnew = (NODE*)malloc(sizeof(NODE));
    pnew->name = malloc(sizeof(char)*name_size);

	if(node->name != NULL)
	{
		strcpy(pnew->name, node->name);
	}
	else
	{
		strcpy(pnew->name, "NULL");
	}
	pnew->salary = node->salary;
	pnew->age = node->age;
	pnew->work_age = node->work_age;

	pnew->pNext = s->top;	//使new指向栈
	s->top = pnew;			//使top指向new

	return 0;
}

int pop(stack *s, NODE *node)
{
	NODE *p = NULL;
	p = s->top;

	if(is_empty(s))
	{
		return -1;
	}
	else
	{
//		val = &(p->data);
	//	*val = p->data;
		s->top = p->pNext;
		free(p);
		p = NULL;

		return 1;
	}
}

void clear(stack *s)
{
	NODE *p = NULL;
	NODE *q = NULL;

	p = s->top;

	if(is_empty(s))
	{
		return;
	}
	else
	{
		while(p != s->bottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		s->top = s->bottom;
	}
}

void traverse(stack *s)
{
	NODE *p = NULL;
	p = s->top;

	if(is_empty(s))
    {
        printf("\n系统信息为空！\n");
    }

	while(p != s->bottom)
	{
        printf("name: %s \t", p->name);
		printf("salary: %d \t", p->salary);
		printf("age: %d \t", p->age);
		printf("work_age: %d \t", p->work_age);
		p = p->pNext;
		printf("\n");
	}
	printf("\n");
}

int query_name(stack *s, const char *name)
{
	NODE *p = NULL;
	p = s->top;
    int flag = 1;

	while(p != s->bottom)
	{
	    if(strcmp(p->name, name) == 0)
        {
            flag = 0;
            printf("name: %s \t", p->name);
            printf("salary: %d \t", p->salary);
            printf("age: %d \t", p->age);
            printf("work_age: %d \t", p->work_age);
        }
		p = p->pNext;
	}
	printf("\n");

	return flag;
}

int query_modifi(stack *s, const char *name)
{
	NODE *p = NULL;
	p = s->top;
    int flag = 1;
    int temp = 0;

	while(p != s->bottom)
	{
	    if(strcmp(p->name, name) == 0)
        {
            flag = 0;
            printf("请输入年龄\n");
            scanf("%d", &temp);
            p->age = temp;
            printf("请输入工龄\n");
            scanf("%d", &temp);
            p->work_age = temp;
            printf("请输入薪资\n");
            scanf("%d", &temp);
            p->salary = temp;
        }
		p = p->pNext;
	}
	printf("\n");

	return flag;
}
