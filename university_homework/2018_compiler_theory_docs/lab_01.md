# Лабораторная работа 1
## Формальное описание конструкций языка программирования с помощью формы Бекуса-Наура

## Цель
Освоение навыка использования формы Бекуса-Наура.

## Задачи
1. Выбрать и согласовать с преподавателем языковую конструкцию известного языка программирования (Паскаль, С++ и т.п.).
2. Выполнить формальное описание выбранной конструкции языка программирования в нормальной форме Бекуса-Наура.

## Выполнение
* Рассматриваемая структура: объявление функции в моём языке.
* Начальный нетерминал: <функция>.

```
1) <функция> ::= <тип> ПРОБЕЛ ИДЕНТИФИКАТОР ( [<аргументы>] ): <блок>
2) <тип> ::= bool | int | void
3) <аргументы> ::= <тип> ИДЕНТИФИКАТОР [,ПРОБЕЛ <аргументы>]
4) <блок> ::= НОВАЯ-СТРОКА ОТСТУП-ВПРАВО <операторы> ОТСТУП-ВЛЕВО
5) <операторы> ::= <оператор> НОВАЯ-СТРОКА [<операторы>]
6) <оператор> ::= <оператор возврата> | ВЫРАЖЕНИЕ | ДРУГОЙ-ОПЕРАТОР
7) <оператор возврата> ::= return [ПРОБЕЛ ВЫРАЖЕНИЕ]
```

### Примечания
* У <оператор> нет переноса строки в конце.
* У <операторы> в конце есть перенос строки.

### Примеры цепочек
```
bool isEven(int x):
    int remainder := x % 2
    return remainder = 0
```
```
int abc():
    if 3 < 5:
        return 1
    else:
        return 2
```
```
int z():
    return 0
```
```
void doNothing():
    3 + 5
    return
```
```
void doNothingWithArgs(bool b, int i):
    True and False
```
Минимальная цепочка:
```
int f():
    0
```

### Вывод минимальной цепочки
Цепочка:
```
int f():
    0
```

Вывод:
```
<функция>
    => (1)
<тип> ПРОБЕЛ ИДЕНТИФИКАТОР (): <блок>
    => (2)
int ПРОБЕЛ ИДЕНТИФИКАТОР (): <блок>
    => (4)
int ПРОБЕЛ ИДЕНТИФИКАТОР (): НОВАЯ-СТРОКА
ОТСТУП-ВПРАВО <операторы> ОТСТУП-ВЛЕВО
    => (5)
int ПРОБЕЛ ИДЕНТИФИКАТОР (): НОВАЯ-СТРОКА
ОТСТУП-ВПРАВО <оператор> НОВАЯ-СТРОКА
ОТСТУП-ВЛЕВО
    => (6)
int ПРОБЕЛ ИДЕНТИФИКАТОР (): НОВАЯ-СТРОКА
ОТСТУП-ВПРАВО ВЫРАЖЕНИЕ НОВАЯ-СТРОКА
ОТСТУП-ВЛЕВО
```

### Вывод обычной цепочки
Цепочка:
```
bool isEven(int x):
    int remainder := x % 2
    return remainder = 0
```

Вывод:
```
<функция>
    => (1)
<тип> ПРОБЕЛ ИДЕНТИФИКАТОР ( <аргументы> ): <блок>
    => (2)
bool ПРОБЕЛ ИДЕНТИФИКАТОР ( <аргументы> ): <блок>
    => (3)
bool ПРОБЕЛ ИДЕНТИФИКАТОР ( <тип> ИДЕНТИФИКАТОР ): <блок>
    => (2)
bool ПРОБЕЛ ИДЕНТИФИКАТОР ( int ИДЕНТИФИКАТОР ): <блок>
    => (4)
bool ПРОБЕЛ ИДЕНТИФИКАТОР ( int ИДЕНТИФИКАТОР ): НОВАЯ-СТРОКА
ОТСТУП-ВПРАВО <операторы> ОТСТУП-ВЛЕВО
    => (5)
bool ПРОБЕЛ ИДЕНТИФИКАТОР ( int ИДЕНТИФИКАТОР ):
НОВАЯ-СТРОКА ОТСТУП-ВПРАВО <оператор> НОВАЯ-СТРОКА
<операторы> ОТСТУП-ВЛЕВО
    => (5)
bool ПРОБЕЛ ИДЕНТИФИКАТОР ( int ИДЕНТИФИКАТОР ): НОВАЯ-СТРОКА
ОТСТУП-ВПРАВО <оператор> НОВАЯ-СТРОКА
<оператор> НОВАЯ-СТРОКА ОТСТУП-ВЛЕВО
    => (6)
bool ПРОБЕЛ ИДЕНТИФИКАТОР ( int ИДЕНТИФИКАТОР ): НОВАЯ-СТРОКА
ОТСТУП-ВПРАВО ДРУГОЙ-ОПЕРАТОР НОВАЯ-СТРОКА
<оператор> НОВАЯ-СТРОКА
ОТСТУП-ВЛЕВО
    => (6)
bool ПРОБЕЛ ИДЕНТИФИКАТОР ( int ИДЕНТИФИКАТОР ): НОВАЯ-СТРОКА
ОТСТУП-ВПРАВО ДРУГОЙ-ОПЕРАТОР НОВАЯ-СТРОКА
<оператор возврата> НОВАЯ-СТРОКА
ОТСТУП-ВЛЕВО
    => (7)
bool ПРОБЕЛ ИДЕНТИФИКАТОР ( int ИДЕНТИФИКАТОР ): НОВАЯ-СТРОКА
ОТСТУП-ВПРАВО ДРУГОЙ-ОПЕРАТОР НОВАЯ-СТРОКА
return ПРОБЕЛ ВЫРАЖЕНИЕ НОВАЯ-СТРОКА
ОТСТУП-ВЛЕВО
```
