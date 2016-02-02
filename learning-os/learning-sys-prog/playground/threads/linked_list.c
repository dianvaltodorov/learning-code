#include <stdlib.h>
#include <stdio.h>

typedef struct list {
    int item;
    struct list *next;
} list;

void insert_list(list **l, int x)
{
    list *p;
    /* temporary pointer */
    p = malloc(sizeof(list));
    p->item = x;
    p->next = *l;
    *l = p;
}

list *predecessor_list(list *l, int x)
{
    if ((l == NULL) || (l->next == NULL)) {
        printf("Error: predecessor sought on null list.\n");
        return(NULL);
    }
    if ((l->next)->item == x)
        return(l);
    else
        return( predecessor_list(l->next, x) );
}

list *search_list(list *l, int x)
{
    if (l == NULL) return(NULL);
    if (l->item == x)
        return(l);
    else
        return( search_list(l->next, x) );
}

void delete_list(list **l, int x)
{
    list *p;
    /* item pointer */
    list *pred;
    /* predecessor pointer */
    list *search_list(), *predecessor_list();
    p = search_list(*l,x);
    if (p != NULL) {
        pred = predecessor_list(*l,x);
        if (pred == NULL)
            /* splice out list */
            *l = p->next;
        else
            pred->next = p->next;
        free(p);
        /* free memory used by node */
    }
}
