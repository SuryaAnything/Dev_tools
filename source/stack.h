#include <stdlib.h>
#include <stdio.h>
#define DEFAULT_SIZE 20
#include <stdbool.h>
#include <limits.h>
typedef struct Collections{
    int* head;
    int size;
 }Collections;
typedef Collections* Stack;

static void pushElementIntoStack(Stack , int);
static void popElementOutStack(Stack);
static int peekElementOfStack(Stack);
static bool checkForEmptyStack(Stack);
static int getSizeOfStack(Stack);
static void freememoryblock(Stack);

Stack newIntegerStack();
void newCollections();

typedef struct
{
    void (*push) (Stack stack, int element);
    void (*pop) (Stack stack);
    int (*peek) (Stack stack);
    bool (*isEmpty) (Stack);
    int (*size) (Stack);
    void (*release) (Stack);
}StackFunction;

StackFunction _stack;

Stack newIntegerStack() {
    Collections* st = (Stack)malloc(sizeof(Collections));
    st->head = (int*)malloc(DEFAULT_SIZE*sizeof(int));
    _stack.push = pushElementIntoStack;
    _stack.pop = popElementOutStack;
    _stack.peek = peekElementOfStack;
    _stack.isEmpty = checkForEmptyStack;
    _stack.size = getSizeOfStack;
    _stack.release = freememoryblock;
    *(st->head) = INT_MIN;
    st->head = st->head + 1;
    st->size = 0;
    return st;
}

static void pushElementIntoStack(Collections* st, int element){
    *(st->head) = element;
    st->head = st->head + 1;
    st->size+=1;
}

static void popElementOutStack(Collections* stack) {
    if (!checkForEmptyStack(stack)) {
        stack->head = stack->head - 1;
    }
    stack->size-=1;
}

static int peekElementOfStack(Collections* stack) {
    if (checkForEmptyStack(stack))
        printf("<__Empty Stack__>?/");
    else
        return *(stack->head-1);
    return INT_MIN;
}

static bool checkForEmptyStack(Collections* stack) {
    if (stack->size==0){
        return true;
    }
    else{
        return false;
    }
}

static int getSizeOfStack(Collections* stack) {
    return stack->size;
}

static void freememoryblock(Collections* stack) {
    free(stack);
}