#include <stdio.h>
#include <malloc.h>

struct list {
    struct list * next;
    int value;
};

struct list *
list_at(struct list * lst, size_t idx)
{
    if (lst && idx)
        return list_at(lst->next, idx-1);
    return lst;
}

struct list *
c(int value, struct list * next)
{
    struct list * lst = malloc(sizeof(struct list));
    lst->next = next;
    lst->value = value;
    return lst;
}

int
main(int argc, char * argv[])
{
    struct list * lst = c(1, c(2, c(3, NULL)));
    printf("%d\n", list_at(lst, 2)->value);

    return 0;
}
