#ifndef ADT_STACK // if not define
#define ADT_STACK // define

#include <stdio.h>


typedef struct node // node�� ����ü ���� ���� ��, STACK_NODE�� ������ ����
{
	void* data_ptr;
	struct node* link;
} STACK_NODE;

// Stack ADT
typedef struct
{
	int count;
	STACK_NODE* top;
} STACK;

// Interface create_stack, push, pop, fill_space �Լ��� ����
STACK* create_stack();
bool push(STACK* stack, void* in);
void* pop(STACK* stack);
void fill_space(int size);

#endif