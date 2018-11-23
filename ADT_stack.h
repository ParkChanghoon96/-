#ifndef ADT_STACK // if not define
#define ADT_STACK // define

#include <stdio.h>


typedef struct node // node란 구조체 변수 선언 후, STACK_NODE로 변수명 변경
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

// Interface create_stack, push, pop, fill_space 함수를 선언
STACK* create_stack();
bool push(STACK* stack, void* in);
void* pop(STACK* stack);
void fill_space(int size);

#endif