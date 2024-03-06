#include <stdio.h>

typedef struct str1 {
    char name[100];
    int year;
    char director[100];
    int views;
    int score;
};

int main(){
    struct str1 movie[10];
    int size;
    char name[100];
    printf("Insert number of movies:");
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        printf("Name of the movie: ");
        scanf("%s",&movie[i].name);
        printf("Year: ");
        scanf("%d",&movie[i].year);
        printf("Director name: ");
        scanf("%d",&movie[i].director);
        printf("Number of views: ");
        scanf("%d",&movie[i].year);
        printf("Score: ");
        scanf("%d",&movie[i].score);

    }
    for(int i=1;i<=size;i++){
        printf("Number: %d Name: %s Year: %d Director: %s Views: %d Score: %d\n",i,movie[i].name,movie[i].year,movie[i].director,movie[i].views,movie[i].score);
    }
    printf("Insert the name of the movie you are looking for:");
    scanf("%s",&name);
    for(int i=1;i<=size;i++){
        if (strcmp(name, movie[i].name)==0){
            printf("The movie you are looking for is in the %d position and it was produced in %d, by %s, has %s views with a score of %s",i,movie[i].year,movie[i].director,movie[i].views,movie[i].score);
        }
        }
    return 0;
}
