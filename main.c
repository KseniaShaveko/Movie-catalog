#include <stdio.h>
#include <locale.h>
#include <malloc.h>

typedef struct Film { //создание структуры фильма
  char* name;         // название фильма(не уверена, что надо, но пусть будет, удалить не долго)
  int year;           // число год выпуска
  char* genre;        // строка название жанра
  char* country;      // строка название страны/стран производителя
  float rating;       // рейтинг дробное число
} film;               // переименование

typedef struct Knot { // структура узел (двусвязный список фильмов)
  film a;             // какой-то фильм со всеми его данными
  struct Knot *next;  // связь к следующему элементу
  struct Knot *prev;  // связь к предыдущему элементу
} knot;               // переименование

typedef struct Favorites_List { // структура избранных фильмов (двусвязный список)
  int value;                    // численное значение - количество фильмов
  struct Favorites_List *next;  // свзь со следующим элементом
  struct Favorites_List *prev;  // связь с предыдущем элементов
} favorites_list;               // переименование

typedef struct User {     // структура пользователя
  char* login;            // логин(строка от 3 до 20 символов латинского алфавита)
  int password;           // пароль (строка от 6 до 20 символов)
  int cart_number;        // номер карты (строка из 16 цифр)
  favorites_list *value;  // кол-во избранных из структуры избранных
  short Admin;            // админ ли пользователь (0 или 1)
} user;                   // переименование

int main(void) { 
  setlocale(LC_ALL,"");
  return 0; 
  }