#include "stack.h"
#include <stdio.h>

int main () {
    Stack s = newIntegerStack();
    _stack.push(s,5);
    _stack.push(s,2);
    _stack.push(s,7);
    printf("%d  ",_stack.size(s));
    printf("%d\n",_stack.peek(s));
    _stack.pop(s);
    _stack.pop(s);
    printf("%d  ",_stack.size(s));
    printf("%d\n",_stack.peek(s));
    _stack.pop(s);
    printf("%d  ",_stack.size(s));
    printf("%d\n",_stack.peek(s));
    _stack.release(s);
}
