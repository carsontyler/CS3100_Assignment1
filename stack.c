#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


stackT* NewStack(void){
	stackT* stack = (stackT*) malloc(sizeof(stackT*));
	stack->head = NULL;
	return stack;
}

void Push(stackT *stack, valueT value){
	nodeT* node = (nodeT*) malloc(sizeof(nodeT));
	node->value = value;
	node->next = stack->head;
	stack->head = node;	
	return;
}

valueT Pop(stackT *stack){
	if (IsEmpty(stack)){
		printf("ERROR: Empty stack\n");
		return 0;
	}
	valueT value = stack->head->value;
	nodeT* temp = stack->head;
	stack->head = stack->head->next;
	free(temp);
	return value;
}

void EmptyStack(stackT *stack){
	nodeT* nodeToDelete = stack->head;
	nodeT* nodeNext = nodeToDelete->next;
	while (nodeToDelete != NULL)
	{
		nodeNext = nodeToDelete->next;
		free(nodeToDelete);
		nodeToDelete = nodeNext;
	}
	stack->head = NULL;
	return;
}

void FreeStack(stackT *stack){
	if (!IsEmpty(stack))
	{
		printf("ERROR: Non-empty stack\n");
		return;
	}
	free(stack);
	return;
}

bool IsEmpty(stackT *stack){
	if (stack->head == NULL)
		return true;
	return false;
}

