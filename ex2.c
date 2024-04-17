#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str1 {
    char name[100];
    int calories;
    int price;
    char restaurant[100];
    int stars;
} Dish;

void search(Dish *array, int size, char *searchTerm) {
  int flag = 0;
  for (int i = 0; i < size; i++) {
    if (strcmp(searchTerm, array[i].name) == 0) {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    printf("Found\n");
  } else {
    printf("Not found\n");
  }
}

void eliminate(Dish *array) {
    free(array);
}

void sorting(Dish *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].stars < array[j + 1].stars) {
                Dish temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("Sorted based on stars");
}

void print(Dish *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("Dish number: %d, name: %s, calories: %d, price: %d$, stars: %d, restaurant: %s\n", i + 1, array[i].name, array[i].calories, array[i].price, array[i].stars, array[i].restaurant);
    }
}

void insert_front(Dish **array, int *size) {
    (*size)++;
    *array = (Dish *)realloc(*array, *size * sizeof(Dish));
    if (*array == NULL) {
        printf("Memory allocation has failed\n");
        return;
    }
    for (int i = *size - 1; i > 0; i--) {
        (*array)[i] = (*array)[i - 1];
    }
    insertions_front(*array, *size);
}

void insertions_front(Dish *array, int size) {
    printf("Insert the name of the new element: ");
    scanf("%s", array[0].name);
    printf("Insert the number of calories: ");
    scanf("%d", &array[0].calories);
    printf("Insert the number of stars: ");
    scanf("%d", &array[0].stars);
    printf("Insert the price: ");
    scanf("%d", &array[0].price);
    printf("Insert the name of the restaurant: ");
    scanf("%s", array[0].restaurant);
}

void insert_end(Dish **array, int *size) {
    (*size)++;
    *array = (Dish *)realloc(*array, *size * sizeof(Dish));
    if (*array == NULL) {
        printf("Memory allocation has failed\n");
        return;
    }
    insertions_end(*array, *size);
}

void insertions_end(Dish *array, int size) {
    printf("Insert the name of the new element: ");
    scanf("%s", array[size - 1].name);
    printf("Insert the number of calories: ");
    scanf("%d", &array[size - 1].calories);
    printf("Insert the number of stars: ");
    scanf("%d", &array[size - 1].stars);
    printf("Insert the price: ");
    scanf("%d", &array[size - 1].price);
    printf("Insert the name of the restaurant: ");
    scanf("%s", array[size - 1].restaurant);
}


void insert_x(Dish **array, int *size) {
    int x;
    printf("Insert the position where you would like to add the new element: ");
    scanf("%d", &x);
    (*size)++;
    *array = (Dish *)realloc(*array, *size * sizeof(Dish));
    if (*array == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    for (int i = *size - 1; i > x - 1; i--) {
        (*array)[i] = (*array)[i - 1];
    }
    insertion_x(*array, *size, x);
}
void insertion_x(Dish *array, int size, int x){
    printf("Insert the name of the new element: ");
    scanf("%s", array[x - 1].name);
    printf("Insert the number of calories: ");
    scanf("%d", &array[x - 1].calories);
    printf("Insert the number of stars: ");
    scanf("%d", &array[x - 1].stars);
    printf("Insert the price: ");
    scanf("%d", &array[x - 1].price);
    printf("Insert the name of the restaurant: ");
    scanf("%s", array[x - 1].restaurant);
}

void delete(Dish *array, int size) {
    int x;
    printf("Insert the element you want to delete: ");
    scanf("%d", &x);
    for (int i = x - 1; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    (size)--;
    array = (Dish *)realloc(array, size * sizeof(Dish));
}

void menu(Dish *array, int size) {
    int n;
    printf("Menu:\n1) Search\n2) Eliminate\n3) Sorting\n4) Insert at the front\n5) Insert at the end\n6) Insert in X position\n7) Delete from X position\n8) Print\n9) Stop\n");
    scanf("%d", &n);
    switch (n) {
    case 1:
        char searchTerm[100];
    printf("Insert the name of the food you want to search for: ");
    scanf("%s", searchTerm);
    search(array, size, searchTerm);
        menu(array, size);
        break;
    case 2:
        eliminate(array);
        menu(array, size);
        break;
    case 3:
        sorting(array, size);
        menu(array, size);
        break;
    case 4:
        insert_front(&array, &size);
        menu(array, size);
        break;
    case 5:
        insert_end(&array, &size);
        menu(array, size);
        break;
    case 6:
        insert_x(&array, &size);
        menu(array, size);
        break;
    case 7:
        delete(array, size);
        menu(array, size);
        break;
    case 8:
        print(array, size);
        menu(array, size);
        break;
    case 9:
        break;
    default:
        menu(array, size);
    }
}

int main() {
    int size;
    Dish *array;
    printf("Insert the number of items: ");
    scanf("%d", &size);
    array = (Dish *)malloc(size * sizeof(Dish));
    if (array == NULL) {
        printf("Memory allocation has failed\n");
        return -1;
    }
    for (int i = 0; i < size; i++) {
        printf("Insert the name of the Dish: ");
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
    menu(array, size);
    return 0;
}
