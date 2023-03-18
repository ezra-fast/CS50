

int main(void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));

    y = malloc(sizeof(int));

    *x = 42;
    *y = 13;

    y = x;

    *y = 13;

    free(x);
    free(y);
}