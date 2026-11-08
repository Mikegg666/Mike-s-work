#include<stdio.h>
typedef struct stack {
    int top;
    int *data;
    int capacity;
} stack;
stack *initstack() {
    stack *s = (stack*)malloc(sizeof(stack));
    if (s == NULL) {
        return NULL;
    }
    s->capacity = 4;
    s->top = -1;
    s->data = (int *)malloc(s->capacity * sizeof(int));
    if (s->data == NULL) {
        free(s);
        return NULL;
    }
    return s;
}
int expendstack(stack *s) {
    int *newdata = (int *)malloc(s->capacity * 2 * sizeof(int));
    if (newdata == NULL) {
        return -1;
    }
    for (int i = 0; i < s->capacity; i++) {
        newdata[i] = s->data[i];
    }
    free(s->data);
    s->data = newdata;
    s->capacity *= 2;
    return 0;
}
int push(stack *s, int value) {
    if (s->top + 1 >= s->capacity) {
        if (expendstack(s) == -1) {
            return -1; 
        }
    }
    s->data[++s->top] = value;
    return 0;
}
int main() {
    stack *s = initstack();
    push(s, 5);
    push(s, 10);
    push(s, 15);
    push(s, 20);
    push(s, 25); // This will trigger the stack to expand
    push(s, 30);
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
    return 0;
}