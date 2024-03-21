#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str1 {
    char name[100];
    int calories;
    int price;
    char restaurant[100];
    int stars;
} dish;

void search(dish *array, int size) {
    char name[100];
    printf("Insert the name of the food: ");
    scanf("%s", name);
    for (int i = 0; i < size; i++) {
        if (strcmp(name, array[i].name) == 0) {
            printf("This dish is saved at the %d position, contains %d calories, has %d stars, costs %d$, and is from %s.\n", i + 1, array[i].calories, array[i].stars, array[i].price, array[i].restaurant);
        }
    }
}

void eliminate(dish *array) {
    free(array);
}

void sorting(int size, dish *array) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].stars < array[j + 1].stars) {
                dish temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("Sorted dishes based on stars:\n");
    for (int i = 0; i < size; i++) {
        printf("stars: %d name: %s\n", array[i].stars, array[i].name);
    }
}

void print(int size, dish *array) {
    for (int i = 0; i < size; i++) {
        printf("Dish number: %d, Name: %s, Calories: %d, Price: %d$, Stars: %d, Restaurant: %s\n", i + 1, array[i].name, array[i].calories, array[i].price, array[i].stars, array[i].restaurant);
    }
}

void insert_front(int *size, dish **array) {
    (*size)++;
    *array = (dish *)realloc(*array, *size * sizeof(dish));
    if (*array == NULL) {
        printf("Memory allocation has failed\n");
        return;
    }
    for (int i = *size - 1; i > 0; i--) {
        (*array)[i] = (*array)[i - 1];
    }
    printf("Insert the name of the new element: ");
    scanf("%s", (*array)[0].name);
    printf("Insert the number of calories: ");
    scanf("%d", &(*array)[0].calories);
    printf("Insert the number of stars: ");
    scanf("%d", &(*array)[0].stars);
    printf("Insert the price: ");
    scanf("%d", &(*array)[0].price);
    printf("Insert the name of the restaurant: ");
    scanf("%s", (*array)[0].restaurant);
}

void insert_end(int *size, dish **array) {
    (*size)++;
    *array = (dish *)realloc(*array, *size * sizeof(dish));
    if (*array == NULL) {
        printf("Memory allocation has failed\n");
        return;
    }
    printf("Insert the name of the new element: ");
    scanf("%s", (*array)[*size - 1].name);
    printf("Insert the number of calories: ");
    scanf("%d", &(*array)[*size - 1].calories);
    printf("Insert the number of stars: ");
    scanf("%d", &(*array)[*size - 1].stars);
    printf("Insert the price: ");
    scanf("%d", &(*array)[*size - 1].price);
    printf("Insert the name of the restaurant: ");
    scanf("%s", (*array)[*size - 1].restaurant);
}

void insert_x(int *size, dish **array) {
    int x;
    printf("Insert the position where you would like to add the new element: ");
    scanf("%d", &x);
    (*size)++;
    *array = (dish *)realloc(*array, *size * sizeof(dish));
    if (*array == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    for (int i = *size - 1; i > x - 1; i--) {
        (*array)[i] = (*array)[i - 1];
    }
    printf("Insert the name of the new element: ");
    scanf("%s", (*array)[x - 1].name);
    printf("Insert the number of calories: ");
    scanf("%d", &(*array)[x - 1].calories);
    printf("Insert the number of stars: ");
    scanf("%d", &(*array)[x - 1].stars);
    printf("Insert the price: ");
    scanf("%d", &(*array)[x - 1].price);
    printf("Insert the name of the restaurant: ");
    scanf("%s", (*array)[x - 1].restaurant);
}

void delete(int *size, dish **array) {
    int x;
    printf("Insert the element you want to delete: ");
    scanf("%d", &x);
    for (int i = x - 1; i < *size - 1; i++) {
        (*array)[i] = (*array)[i + 1];
    }
    (*size)--;
    *array = (dish *)realloc(*array, *size * sizeof(dish));
}

void menu(int size, dish *array) {
    int n;
    printf("Menu:\n1) Search\n2) Eliminate\n3) Sorting\n4) Insert at the front\n5) Insert at the end\n6) Insert in X position\n7) Delete from X position\n8) Print\n9) Stop\n");
    scanf("%d", &n);
    switch (n) {
    case 1:
        search(array, size);
        menu(size, array);
        break;
    case 2:
        eliminate(array);
        menu(size, array);
        break;
    case 3:
        sorting(size, array);
        menu(size, array);
        break;
    case 4:
        insert_front(&size, &array);
        menu(size, array);
        break;
    case 5:
        insert_end(&size, &array);
        menu(size, array);
        break;
    case 6:
        insert_x(&size, &array);
        menu(size, array);
        break;
    case 7:
        delete(&size, &array);
        menu(size, array);
        break;
    case 8:
        print(size, array);
        menu(size, array);
        break;
    case 9:
        break;
    default:
        menu(size, array);
    }
}

int main() {
    int size;
    dish *array;
    printf("Insert the number of items: ");
    scanf("%d", &size);
    array = (dish *)malloc(size * sizeof(dish));
    if (array == NULL) {
        printf("Memory allocation has failed\n");
        return -1;
    }
    for (int i = 0; i < size; i++) {
        printf("Insert the name of the dish: ");
        scanf("%s", array[i].name);
        printf("Insert the number of calories: ");
        scanf("%d", &array[i].calories);
        printf("Insert the number of stars: ");
        scanf("%d", &array[i].stars);
        printf("Insert the price: ");
        scanf("%d", &array[i].price);
        printf("Insert the name of the restaurant: ");
        scanf("%s", array[i].restaurant);
    }
    menu(size, array);
    return 0;
}
