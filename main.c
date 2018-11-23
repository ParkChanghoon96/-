// ADT STACK
#include <stdio.h>
#include "ADT_stack.h"

int main(void)
{
	STACK* stack_ptr;
	stack_ptr = create_stack(); // create_stack�Լ� ȣ��

	int i, k, m;

	// +-pushed 100
	i = 100;
	if(!push(stack_ptr, &i)) // push�Լ� ȣ��
	{
		printf("oops\n"); // �������� ���� �߻� �� oops ���.
		return -1;
	}
	else // ������ ���� ���� ��
	{
		fill_space(stack_ptr->count); // fill_space �Լ� ȣ�� (���� �Է�)
		printf(" +->pushed: %d\n", i);
	}

	// +-pushed 200
	k = 200; // i = 100�� ������ ���
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
	m = 300; // i = 100�� ������ ���
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
	int* temp; // temp ���� ����(�����)
	temp = (int*)pop(stack_ptr); // pop�Լ� ����, �����͸� temp�� ���
	fill_space(stack_ptr->count);
	printf("  <-popped: %d\n", *temp);

	// pushed loop(�迭�� 1~10)
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
	while(stack_ptr->count != 0) // count�� 0�� �ƴ� �������� �ݺ�
	{
		temp = (int*)pop(stack_ptr);
		fill_space(stack_ptr->count);
		printf("  <-popped: %d\n", *temp);
	}

	if(stack_ptr->count == 0) // count�� 0�̶�� ���� ���
	{
		printf("stack is empty");
	}

	return 0;
}