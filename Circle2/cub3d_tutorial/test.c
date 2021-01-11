#include <stdio.h>
#include <stdlib.h>
typedef struct _test_t {
    int data;
}test_t;
int main(void)
{
    test_t *test;
    test = malloc(sizeof(test_t));
    test->data = 3;
    printf("test->data = %d\n", test->data);

    return 0;
}


