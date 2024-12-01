#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct circular_list {
    int key;
    struct circular_list* next;
};

struct doubly_circular_list{
    int key;
    struct doubly_circular_list* next, *prev;
};

typedef struct circular_list* list;
typedef struct doubly_circular_list* double_list;

void show(list);
void show_reversed(list);
void add_to_start(list*, int);
void add_to_end(list*, int);
void delete_first(list*);
void delete_last(list*);
list find_element(list, int);
bool delete_found(list*, int);
void add_before_element(list*, int, int);
void add_after_element(list*, int, int);


void show_double(double_list);
void show_reversed_double(double_list);
void add_to_start_double(double_list*, int);
void add_to_end_double(double_list*, int);
void delete_first_double(double_list*);
void delete_last_double(double_list*);
double_list find_element_double(double_list, int);
bool delete_found_double(double_list*, int);
void add_before_element_double(double_list*, int, int);
void add_after_element_double(double_list*, int, int);