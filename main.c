#include <stdio.h>
#include "circular_list.h"

void init_menu(){
    printf("Wybierz typ listy\n");
    printf("1. Lista cykliczna jednokierunkowa\n");
    printf("2. Lista cykliczna dwukierunkowa\n");
    printf("0. Wyjdz\n");
}

void show_menu(){
    printf("Program pozwalajacy operowac na listach cyklicznych\n");
    printf("1. Wyswietlij liste\n");
    printf("2. Dodaj do poczatku listy\n");
    printf("3. Dodaj do konca listy\n");
    printf("4. Usun pierwszy element\n");
    printf("5. Usun ostatni element\n");
    printf("6. Wyszukaj element\n");
    printf("7. Usun szukany element\n");
    printf("8. Dodaj przed szukanym elementem\n");
    printf("9. Dodaj po szukanym elemencie\n");
    printf("0. Wyjdz\n");
}

void circular_linked_list_loop(){
    list l = 0;
    int user_input,
        target;
    do{
        show_menu();
        scanf("%d", &user_input);
        switch(user_input){
            case 1:
                show(l);
                break;
            case 2:
                printf("Enter the element you want to add\n");
                scanf("%d", &target);
                add_to_start(&l, target);
                break;
            case 3:
                printf("Enter the element you want to add\n");
                scanf("%d", &target);
                add_to_end(&l, target);
                break;
            case 4:
                delete_first(&l);
                break;
            case 5:
                delete_last(&l);
                break;
            case 6:
                printf("Enter the element you want to find\n");
                scanf("%d", &target);
                if(find_element(l, target)){
                    printf("Element found\n");
                }else{
                    printf("Element not found\n");
                }
                break;
            case 7:
                printf("Enter the element you want to find and delete\n");
                scanf("%d", &target);
                if(delete_found(&l, target)){
                    printf("Element found and deleted\n");
                }else{
                    printf("Element not found\n");
                }
                break;
            case 8:
                printf("Enter the element before which you want to add a new element\n");
                scanf("%d", &target);
                printf("Enter the element you want to add\n");
                scanf("%d", &user_input);
                add_before_element(&l, target, user_input);
                break;
            case 9:
                printf("Enter the element after which you want to add a new element\n");
                scanf("%d", &target);
                printf("Enter the element you want to add\n");
                scanf("%d", &user_input);
                add_after_element(&l, target, user_input);
                break;
            case 0:
                return;
            default:
                printf("Incorrect input\n");
                break;
        }
    }while(true);
}


void doubly_circular_linked_list_loop(){
    double_list l = 0;
    int user_input,
            target;
    do{
        show_menu();
        scanf("%d", &user_input);
        switch(user_input){
            case 1:
                show_double(l);
                break;
            case 2:
                printf("Enter the element you want to add\n");
                scanf("%d", &target);
                add_to_start_double(&l, target);
                break;
            case 3:
                printf("Enter the element you want to add\n");
                scanf("%d", &target);
                add_to_end_double(&l, target);
                break;
            case 4:
                delete_first_double(&l);
                break;
            case 5:
                delete_last_double(&l);
                break;
            case 6:
                printf("Enter the element you want to find\n");
                scanf("%d", &target);
                if(find_element_double(l, target)){
                    printf("Element found\n");
                }else{
                    printf("Element not found\n");
                }
                break;
            case 7:
                printf("Enter the element you want to find and delete\n");
                scanf("%d", &target);
                if(delete_found_double(&l, target)){
                    printf("Element found and deleted\n");
                }else{
                    printf("Element not found\n");
                }
                break;
            case 8:
                printf("Enter the element before which you want to add a new element\n");
                scanf("%d", &target);
                printf("Enter the element you want to add\n");
                scanf("%d", &user_input);
                add_before_element_double(&l, target, user_input);
                break;
            case 9:
                printf("Enter the element after which you want to add a new element\n");
                scanf("%d", &target);
                printf("Enter the element you want to add\n");
                scanf("%d", &user_input);
                add_after_element_double(&l, target, user_input);
                break;
            case 0:
                return;
            default:
                printf("Incorrect input\n");
                break;
        }
    }while(true);
}


int main() {
    int user_input;
    do{
        init_menu();
        scanf("%d", &user_input);
        switch(user_input){
            case 1:
                circular_linked_list_loop();
                break;
            case 2:
                doubly_circular_linked_list_loop();
                break;
            case 0:
                return 0;
            default:
                printf("Incorrect input\n");
                break;
        }
    }while(true);
}
