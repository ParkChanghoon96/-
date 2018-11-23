#include <stdio.h> // stdio.h, stdlib.h, ADT_stack.h란 헤더파일을 불러옴.
#include <stdlib.h>
#include "ADT_stack.h"

STACK* create_stack() // create_stack 함수의 내용을 정의
{
	STACK* stack = (STACK*)malloc(sizeof(STACK)); //malloc을 통해 STACK의 크기만큼 stack에 메모리 할당
	stack->count = 0; // stack의 count를 선언, 0으로 정의
	stack->top = NULL; // stack의 top을 선언, 안전성을 위해 NULL값으로 정의
	return stack;
}

bool push(STACK* stack, void* in) // push 함수의 내용을 정의
{
	STACK_NODE* new_node = (STACK_NODE*)malloc(sizeof(STACK_NODE)); 
	new_node->data_ptr = in; // in 데이터를 new_node의 data_ptr로 지정
	new_node->link = stack->top; // link로 이어줌
	stack->top = new_node; // top을 new_node로 교체
	(stack->count)++; // stack의 count를 1 증가
	return true;
}

void* pop(STACK* stack) //pop 함수의 내용을 정의
{
	if(stack->count == 0) // count가 0이라면 NULL값을 반환
	{
		return NULL;
	}
	else // count가 0이 아니라면 ~
	{
		STACK_NODE* temp = (STACK_NODE*) malloc (sizeof(STACK_NODE));
		temp = stack->top; // temp에 top 데이터를 백업
		void* data_out = stack->top->data_ptr;
		stack->top = stack->top->link; // top을 top과 link되어 있는 다음 데이터로 교체
		free(temp); // malloc을 통해 할당된 데이터를 제거하는 과정
		(stack->count)--; // stack의 count를 1 감소
		return data_out;
	}
}

void fill_space(int size) // fill_space 함수의 내용을 정의
{
	int a;
	for(a = 0; a < size; a++) // a가 size보다 적을 때까지만 a를 +1 하며 공백을 한 칸씩 입력.
	{
	printf(" ");
	}
}