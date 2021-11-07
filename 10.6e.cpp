#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 64

using namespace std;

typedef struct {
    int index;
    char author[N];
    char title[N];
    int reader_id;
    char surname[N];
    char order_date[N];
} BookOrderBlank;

BookOrderBlank input(){
    BookOrderBlank obj;
    printf("Provide information about book \n");
    printf("Index | title | author :\n");
    scanf("%d %63s %63s", &obj.index, obj.title, obj.author);
    printf("\nProvide information about reader: \n");
    printf("Reader ID | surname | order date :\n");
    scanf("%d %63s %63s", &obj.reader_id, obj.surname, obj.order_date);

    return obj;
}

void print(BookOrderBlank obj) {
    printf("\nInformation about ordered book:\n");
    printf("'%s' by %s\n",obj.title, obj.author);
    printf("\nInformation about reader:\n");
    printf("Id: %d, surname: %s, order date: %s\n", obj.reader_id, obj.surname, obj.order_date);
}


int main(){
    BookOrderBlank obj;
    obj = input();

    print(obj);
    return 0;
}
