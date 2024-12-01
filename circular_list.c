#include <malloc.h>
#include "circular_list.h"

void show(list l){
    if (l == NULL) {
        printf("[ ]\n");
        return;
    }

    list head = l;
    printf("[ ");
    while (true) {
        printf("%d ", head->key);
        head = head->next;
        if (head == l) break;
    }
    printf("]\n");
}


void add_to_start(list* l, int value){
    list new_node = malloc(sizeof(struct circular_list));
    new_node->key = value;
    if (*l == NULL) {
        new_node->next = new_node;
        *l = new_node;
        return;
    } else {
        list last = *l;
        while (last->next != *l) {
            last = last->next;
        }
        new_node->next = *l;
        last->next = new_node;
        *l = new_node;
    }
}


void add_to_end(list* l, int value){
    list new_node = malloc(sizeof(struct circular_list));
    new_node->key = value;
    if (*l == NULL) {
        *l = new_node;
        new_node->next = *l;
        return;
    }
    list temp = *l;
    while (temp->next != *l) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = *l;
}


void delete_first(list* l){
    if (*l == NULL) {
        printf("List is empty!");
        return;
    }
    if ((*l)->next == *l) {
        free(*l);
        *l = 0;
        return;
    }
    list temp_node = *l;
    list last_node = *l;


    while (last_node->next != *l) {
        last_node = last_node->next;
    }


    last_node->next = temp_node->next;
    *l = temp_node->next;
    free(temp_node);
}


void delete_last(list* l){
    if (*l == NULL) {
        printf("List is empty!");
        return;
    }
    if ((*l)->next == *l) {
        free(*l);
        *l = 0;
        return;
    }


    list temp_node = *l;
    list last_node = NULL;


    while (temp_node->next != *l) {
        last_node = temp_node;
        temp_node = temp_node->next;
    }
    last_node->next = *l;
    free(temp_node);
}


list find_element(list l, int target){
    if (l == NULL) {
        return NULL;
    }

    list temp = l;

    do{
        if(temp->key == target) {
            return temp;
        }
        temp = temp->next;
    }while(temp->next != l);
    return NULL;
}


bool delete_found(list* l, int target){
    if (*l == NULL) {
        printf("List is empty, nothing to delete.\n");
        return false;
    }

    list curr = (*l)->next;
    list prev = *l;

    if (curr == *l && curr->key == target) {
        free(curr);
        *l = 0;
        return false;
    }

    if (curr->key == target) {
        (*l)->next = curr->next;
        free(curr);
        return true;
    }

    while (curr != *l && curr->key != target) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->key == target) {
        prev->next = curr->next;
        if (curr == *l) {
            *l = prev;
        }
        free(curr);
        return true;
    } else {
        return false;
    }
}


void add_before_element(list* l, int target, int value){
    list new_node = malloc(sizeof(struct circular_list));
    if (*l == NULL) {
        printf("List is empty!");
        return;
    }

    new_node->key = value;
    list current = *l;
    list prev = NULL;

    do {
        if (current->key == target) {
            if (prev == NULL) {
                new_node->next = *l;

                list temp = *l;
                while (temp->next != *l) {
                    temp = temp->next;
                }
                temp->next = new_node;
                *l = new_node;
            } else {
                new_node->next = current;
                prev->next = new_node;
            }
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *l);
}


void add_after_element(list* l, int target, int value){
    list new_node = malloc(sizeof(struct circular_list));
    if (*l == NULL) {
        return;
    }

    new_node->key = value;
    list current = *l;

    do {
        if (current->key == target) {
            new_node->next = current->next;
            current->next = new_node;
            return;
        }
        current = current->next;
    } while (current != *l);
}



//Lista cykliczna dwukierunkowa
void show_double(double_list l){
    if (l == NULL) {
        printf("[ ]\n");
        return;
    }

    double_list head = l;
    printf("[ ");
    while (true) {
        printf("%d ", head->key);
        head = head->next;
        if (head == l) break;
    }
    printf("]\n");
}


void add_to_start_double(double_list *l, int value){
    double_list new_node = malloc(sizeof(struct doubly_circular_list));
    new_node->key = value;
    if (*l == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *l = new_node;
    } else {
        double_list last = *l;
        while (last->next != *l) {
            last = last->next;
        }
        new_node->next = *l;
        (*l)->prev = new_node;
        last->next = new_node;
        new_node->prev = last;
        *l = new_node;
    }
}


void add_to_end_double(double_list* l, int value){
    double_list newNode = malloc(sizeof(struct doubly_circular_list));
    newNode->key = value;

    if (!*l) {
        newNode->next = newNode->prev = newNode;
        *l = newNode;
    } else {

        double_list last = (*l)->prev;
        newNode->next = *l;
        newNode->prev = last;
        last->next = newNode;
        (*l)->prev = newNode;
    }
}


void delete_first_double(double_list* l){
    double_list q = NULL;
    if(*l != NULL)
    {
        q=(*l)->next;
        if(q==(*l))
        {
            *l = NULL;
        }
        else{
            (*l)->key = q->key;
            (*l)->next = q->next;
        }
        free(q);
    }
}


void delete_last_double(double_list* l){
    if (*l == NULL) {
        printf("The list is empty.\n");
        return;
    }

    double_list tail = (*l)->prev;
    if (tail == *l) {
        free(*l);
        *l = NULL;
    } else {
        double_list newTail = tail->prev;
        newTail->next = *l;
        (*l)->prev = newTail;
        free(tail);
    }
}


double_list find_element_double(double_list l, int target){
    double_list q = l;
    if(q != NULL)
    {
        while((q->next != l) && (q->key != target))
        {
            q = q->next;
        }
        if(q->key == target)
        {
            return q;
        }
    }
    return NULL;
}


bool delete_found_double(double_list* l, int target){
    double_list q = NULL;
    double_list p = *l;
    q = find_element_double(*l,target);
    if(q == 0)
    {
        printf("Element not found\n");
        return false;
    }
    else
    {
        if(q == q->next)
        {
            *l = 0;
        }
        else if (q->next == p)
        {
            delete_last_double(&p);
            return true;
        }
        else{
            if((*l) == q->next)
            {
                *l = q;
            }
            delete_first_double(&q);
            return true;
        }
    }
    return false;
}


void add_before_element_double(double_list* l, int target, int value){
    double_list q = NULL;
    q = find_element_double(*l,target);
    if(q == NULL)
    {
        printf("Element not found\n");
    }
    else{
        add_to_start_double(&q,value);
    }
}


void add_after_element_double(double_list *l, int target, int value){
    double_list q = NULL;
    q = find_element_double(*l, target);
    if(q == NULL)
    {
        printf("Element not found\n");
    }
    else{
        add_to_start_double(&(q->next),value);
    }
}


void diffList(list* a, list* b){
    list *head_b = b;
    list temp;

    while((*b)->next != *head_b){
        while(*a!=NULL){
            temp = find_element(*a, (*b)->key);
            if (temp==NULL)
            {
                break;
            }
            else{
                delete_first(&temp);
            }
        }
        b = &(*b)->next;
    }
}
