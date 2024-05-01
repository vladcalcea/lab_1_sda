#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dish
{
    char name[100];
    int calories;
    int price;
    char restaurant[100];
    int stars;
} Dish;

void search(Dish *array, int size, char *searchterm)
{
    int flag = 0;
    int position = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchterm, array[i].name) == 0)
        {
            flag = 1;
            position = i;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Found, in %d\n", position);
    }
    else
    {
        printf("Not found\n");
    }
}

void eliminate(Dish *array)
{
    free(array);
}

void sorting(Dish *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j].stars < array[j + 1].stars)
            {
                Dish temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void print(Dish *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Dish number: %d, name: %s, calories: %d, price: %d$, stars: %d, restaurant: %s\n", i + 1, array[i].name, array[i].calories, array[i].price, array[i].stars, array[i].restaurant);
    }
}

void input_dish_info(Dish *new_dish)
{
    printf("Dish name: ");
    scanf("%s", new_dish->name);
    printf("Number of calories: ");
    scanf("%d", &new_dish->calories);
    printf("Number of stars: ");
    scanf("%d", &new_dish->stars);
    printf("Price: ");
    scanf("%d", &new_dish->price);
    printf("Restaurant name: ");
    scanf("%s", new_dish->restaurant);
}

void add_dish_at_beginning(Dish **array, int *size, Dish new_dish) {
  (*size)++;
  *array = (Dish *)realloc(*array, *size * sizeof(Dish));
  if (*array == NULL) {
    printf("Memory allocation failed\n");
    return;
  }
  for (int i = *size - 1; i > 0; i--) {
    (*array)[i] = (*array)[i - 1];
  }

  (*array)[0] = new_dish;
}

void add_dish_at_end(Dish **array, int *size, Dish new_dish)
{
    (*size)++;
    *array = (Dish *)realloc(*array, *size * sizeof(Dish));
    if (*array == NULL)
    {
        printf("Memory allocation has failed\n");
        return;
    }
    (*array)[*size - 1] = new_dish;
}

void add_dish_at_x(Dish **array, int *size, Dish *new_dish)
{
    int position;
    (*size)++;
    *array = (Dish *)realloc(*array, *size * sizeof(Dish));
    if (*array == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    for (int i = *size - 1; i > position; i--)
    {
        (*array)[i] = (*array)[i - 1];
    }
    (*array)[position] = *new_dish;
}

void delete(Dish *array, int size)
{
    int x;
    printf("Insert the element you want to delete: ");
    scanf("%d", &x);
    for (int i = x - 1; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    (size)--;
    array = (Dish *)realloc(array, size * sizeof(Dish));
}

void menu(Dish *array, int size, Dish new_dish)
{
    int n;
    printf("Menu:\n1) Search\n2) Eliminate\n3) Sorting\n4) Insert at the front\n5) Insert at the end\n6) Insert in X position\n7) Delete from X position\n8) Print\n9) Stop\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:{
        char searchterm[100];
        printf("Insert the name of the food you want to search for: ");
        scanf("%s", searchterm);
        search(array, size, searchterm);
        menu(array, size, new_dish);
        break;}
    case 2:
        eliminate(array);
        menu(array, size, new_dish);
        break;
    case 3:
        sorting(array, size);
        menu(array, size, new_dish);
        break;
    case 4:
        add_dish_at_beginning(&array, &size, new_dish);
        input_dish_info(&new_dish);
        menu(array, size, new_dish);
        break;
    case 5:
        add_dish_at_end(&array, &size, new_dish);
        input_dish_info(&new_dish);
        menu(array, size, new_dish);
        break;
    case 6:
        add_dish_at_x(&array, &size, &new_dish);
        input_dish_info(&new_dish);
        menu(array, size, new_dish);
        break;
    case 7:
        delete (array, size);
        menu(array, size, new_dish);
        break;
    case 8:
        print(array, size);
        menu(array, size, new_dish);
        break;
    case 9:
        break;
    default:
        menu(array, size, new_dish);
    }
}

int main()
{
    int size;
    Dish *array;
    int position;
    Dish *new_dish;
    printf("Insert the number of items: ");
    scanf("%d", &size);
    array = (Dish *)malloc(size * sizeof(Dish));
    if (array == NULL)
    {
        printf("Memory allocation has failed\n");
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
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
    menu(array, size, *new_dish);
    return 0;
}
