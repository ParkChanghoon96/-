#include <stdio.h> // stdio.h, stdlib.h, ADT_stack.h�� ��������� �ҷ���.
#include <stdlib.h>
#include "ADT_stack.h"

STACK* create_stack() // create_stack �Լ��� ������ ����
{
	STACK* stack = (STACK*)malloc(sizeof(STACK)); //malloc�� ���� STACK�� ũ�⸸ŭ stack�� �޸� �Ҵ�
	stack->count = 0; // stack�� count�� ����, 0���� ����
	stack->top = NULL; // stack�� top�� ����, �������� ���� NULL������ ����
	return stack;
}

bool push(STACK* stack, void* in) // push �Լ��� ������ ����
{
	STACK_NODE* new_node = (STACK_NODE*)malloc(sizeof(STACK_NODE)); 
	new_node->data_ptr = in; // in �����͸� new_node�� data_ptr�� ����
	new_node->link = stack->top; // link�� �̾���
	stack->top = new_node; // top�� new_node�� ��ü
	(stack->count)++; // stack�� count�� 1 ����
	return true;
}

void* pop(STACK* stack) //pop �Լ��� ������ ����
{
	if(stack->count == 0) // count�� 0�̶�� NULL���� ��ȯ
	{
		return NULL;
	}
	else // count�� 0�� �ƴ϶�� ~
	{
		STACK_NODE* temp = (STACK_NODE*) malloc (sizeof(STACK_NODE));
		temp = stack->top; // temp�� top �����͸� ���
		void* data_out = stack->top->data_ptr;
		stack->top = stack->top->link; // top�� top�� link�Ǿ� �ִ� ���� �����ͷ� ��ü
		free(temp); // malloc�� ���� �Ҵ�� �����͸� �����ϴ� ����
		(stack->count)--; // stack�� count�� 1 ����
		return data_out;
	}
}

void fill_space(int size) // fill_space �Լ��� ������ ����
{
	int a;
	for(a = 0; a < size; a++) // a�� size���� ���� �������� a�� +1 �ϸ� ������ �� ĭ�� �Է�.
	{
	printf(" ");
	}
}