// ADT STACK
#include <stdio.h>
#include "ADT_stack.h"

int main(void)
{
	STACK* stack_ptr;
	stack_ptr = create_stack(); // create_stack함수 호출

	int i, k, m;

	// +-pushed 100
	i = 100;
	if(!push(stack_ptr, &i)) // push함수 호출
	{
		printf("oops\n"); // 구문에서 오류 발생 시 oops 출력.
		return -1;
	}
	else // 오류가 나지 않을 시
	{
		fill_space(stack_ptr->count); // fill_space 함수 호출 (공백 입력)
		printf(" +->pushed: %d\n", i);
	}

	// +-pushed 200
	k = 200; // i = 100과 동일한 방법
	if(!push(stack_ptr, &k))
	{
		printf("oops\n");
		return -1;
	}
	else
	{
		fill_space(stack_ptr->count);
		printf(" +->pushed: %d\n", k);
	}

	// +-pushed 300
	m = 300; // i = 100과 동일한 방법
	if(!push(stack_ptr, &m))
	{
		printf("oops\n");
		return -1;
	}
	else
	{
		fill_space(stack_ptr->count);
		printf(" +->pushed: %d\n", m);
	}

	// popped 300
	int* temp; // temp 변수 선언(백업용)
	temp = (int*)pop(stack_ptr); // pop함수 선언, 데이터를 temp로 백업
	fill_space(stack_ptr->count);
	printf("  <-popped: %d\n", *temp);

	// pushed loop(배열의 1~10)
	int idx;
	int data[10] = {1,2,3,4,5,6,7,8,9,10};
	
	for(idx = 0 ;idx < 10 ;idx++)
	{
		if(!push(stack_ptr, &data[idx]))
		{
			printf("oops\n");
			return -1;
		}
		else
		{
			fill_space(stack_ptr->count);
			printf(" +->pushed: %d\n", data[idx]);
		}
	}

	// loop pop until empty
	while(stack_ptr->count != 0) // count가 0이 아닐 때까지만 반복
	{
		temp = (int*)pop(stack_ptr);
		fill_space(stack_ptr->count);
		printf("  <-popped: %d\n", *temp);
	}

	if(stack_ptr->count == 0) // count가 0이라면 구문 출력
	{
		printf("stack is empty");
	}

	return 0;
}