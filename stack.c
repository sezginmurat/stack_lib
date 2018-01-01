#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_COUNT 3
#define STACK_SIZE 10

/*
 * stack data structure
 */
struct stack {
	int array[STACK_SIZE * STACK_COUNT];
	int size[STACK_COUNT];
};

/*
 * stack_print()
 *	Prints the stack
 */
void stack_print(struct stack *s)
{
	int i;
 
	for (i = 0; i < STACK_SIZE; i++) {
		printf("%d ", s->array[i]);
	}
	printf("size = %d\n", s->size[0]);

	for (i = STACK_SIZE; i < STACK_SIZE * 2; i++) {
		printf("%d ", s->array[i]);
	}
	 printf("size = %d\n", s->size[1]);
 
	for (i = STACK_SIZE * 2; i < STACK_SIZE * 3; i++) {
		printf("%d ", s->array[i]);
	}
	printf("size = %d\n", s->size[2]);
}

/*
 * stack_pop()
 *	pops an element from the stack.
 */
int stack_pop(struct stack *s, int stack_num)
{
	int index;
	int data;

	/*
	 * Calculate the top index
	 */
	index = s->size[stack_num - 1] + ((stack_num - 1) * STACK_SIZE) - 1;
 
	data = s->array[index];
	s->array[index] = 0;
	s->size[stack_num - 1]--;
 
	return data;
}

/*
 * stack_push()
 *	pushes an element to the stack.
 */
void stack_push(struct stack *s, int data, int stack_num)
{
	int index;

	index = s->size[stack_num - 1] + ((stack_num - 1) * STACK_SIZE);
	s->array[index] = data;
	s->size[stack_num - 1]++;
}

/*
 * main()
 *	Test code.
 */
int main(void)
{
	struct stack *my_stack;

	my_stack = (struct stack *)malloc(sizeof(struct stack));
	if (!my_stack) {
		return 1;
	}

	memset(my_stack, 0, sizeof(struct stack));

	stack_push(my_stack, 1, 1); 
	stack_push(my_stack, 2, 2); 
	stack_push(my_stack, 3, 3); 
	stack_push(my_stack, 4, 1); 
	stack_push(my_stack, 5, 2); 
	stack_push(my_stack, 6, 3); 
	stack_push(my_stack, 7, 1); 
	stack_push(my_stack, 8, 2); 
	stack_push(my_stack, 9, 3); 
	stack_push(my_stack, 10, 1); 
	stack_push(my_stack, 11, 2); 
	stack_push(my_stack, 12, 3); 

	printf("After pushing the elements\n"); 
	stack_print(my_stack);

	printf("\n");

	stack_pop(my_stack, 1);
	stack_pop(my_stack, 2);
	stack_pop(my_stack, 3);
	stack_pop(my_stack, 1);
	stack_pop(my_stack, 1);
	stack_pop(my_stack, 3);
	stack_pop(my_stack, 1);
 
	printf("After poping the elements\n"); 
	stack_print(my_stack);

	return 0;
}
