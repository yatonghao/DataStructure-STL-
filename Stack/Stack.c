#include "Stack.h"

void StackInit(ST* ps) {
    assert(ps);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}
void StackDestroy(ST* ps) {
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}
bool StackEmpty(ST* ps) {
    assert(ps);
    return ps->top == 0;
}
void StackPush(ST* ps, STDataType x) {
    assert(ps);

    if(ps->capacity == ps->top) {
        int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
        STDataType *tmp = (STDataType*)realloc(ps->a, newCapacity * sizeof(STDataType));
        assert(tmp);
        ps->a = tmp;
        ps->capacity = newCapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;
}
void StackPop(ST* ps) {
    assert(ps);
    assert(!StackEmpty(ps));
    ps->top--;
}

STDataType StackTop(ST* ps) {
    assert(ps);
    assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];
}

int StackSize(ST* ps) {
    assert(ps);
    return ps->top;
}