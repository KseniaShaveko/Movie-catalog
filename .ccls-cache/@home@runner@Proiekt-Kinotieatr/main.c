#include <locale.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>     //просто пусть будет
#include <unistd.h>     //вдруг   пригодится
//#include <string.h>     в         будующем

typedef struct Film {      //создание структуры фильма
  int index;
  char name[80];         // название фильма
  char year[8];          // год выпуска
  char country[40];      //  название страны/стран производителя
  char genre[45];        //  название жанра
  char rating[5];         // рейтинг 
} film;                   // переименование

typedef struct Knot { // структура узел (двусвязный список фильмов)
  film a;             // какой-то фильм со всеми его данными
  struct Knot* next;  // связь к следующему элементу
  struct Knot* prev;  // связь к предыдущему элементу
} knot;               // переименование

typedef struct Favorites_List { // структура избранных фильмов (двусвязный список)
  int value;                    // численное значение - количество фильмов
  struct Favorites_List *next;  // свзь со следующим элементом
  struct Favorites_List *prev;  // связь с предыдущем элементов
} favorites_list;               // переименование

typedef struct User {    // структура пользователя
  char *login;           // логин(строка от 3 до 20 символов латинского алфавита)
  int password;          // пароль (строка от 6 до 20 символов)
  int cart_number;       // номер карты (строка из 16 цифр)
  favorites_list *value; // кол-во избранных из структуры избранных
  short Admin;           // админ ли пользователь (0 или 1)
} user;                  // переименование





knot * init_film(film a){              //инициализируем первый элемент списка
  knot *list;                          //создали узел
  list = (knot*)malloc(sizeof(knot));  // выделели память
  list -> a = a;                       // узел, хранящий инфу о фильме
  list -> prev = list;                 // предыдущий указывает на себя
  list -> next = list;                 // следующий указывает на себя=
  return list;                         // вернули
}

void add(knot* list, film a){          //функция добавления фильма
  knot* temp;
  knot* temp_next;
  knot* temp_prev;
  temp = (knot*)malloc(sizeof(knot));
  temp_next = list -> next;
  temp_prev = list -> prev;
  if (temp_prev ==NULL){ 
    list -> prev = list;
  }
  if (temp_prev == list){
    temp_prev = list -> next;
  }
  list -> next = temp;
  temp -> a = a;
  temp -> next = temp_next;
  temp -> prev = list;
  temp_next -> prev = temp;
}

void print(knot* list){  // функция принта
  knot* w;
  w = list;
  do{
    printf("%s\n", w -> a.name);
    printf("%s\n", w -> a.year);
    printf("%s\n", w -> a.country);
    printf("%s\n", w -> a.genre);
    printf("%s\n\n", w -> a.rating);
    w = w -> prev;
  } while (w != list);
}

int main(void) {
  setlocale(LC_ALL, "");  //Функция позволяет выводить кирилицу
  
  FILE* open_film = fopen("films.txt", "r");
  film a;
  knot* list;
  int index = 1;
  a.index = index;
  fgets(a.name, 80, open_film);
  fgets(a.year, 8, open_film);  
  fgets(a.country, 40, open_film);  
  fgets(a.genre, 45, open_film);  
  fgets(a.rating, 5, open_film);
  list = init_film(a);
  while (!feof(open_film)){
    film a;
    ++index;
    a.index = index;
    fgets(a.name, 80, open_film);
    fgets(a.year, 8, open_film);  
    fgets(a.country, 40, open_film);  
    fgets(a.genre, 45, open_film);  
    fgets(a.rating, 5, open_film);
    add(list, a);
  }
  print(list);
}