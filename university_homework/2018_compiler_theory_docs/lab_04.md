# Лабораторная работа 4
## Построение модели лексического анализатора

## Цель
Освоение навыка построения конечных распознавателей для лексического анализа цепочек языка.

## Задание
1. Выполнить описание множества классов лексем исходной конструкции.
2. Построить модель лексического анализатора.

## Выполнение

### Классы лексем
Множество допустимых для выбранной конструкции слов разбито на классы лексем:
* ключевые слова
    * bool
    * int
    * void
    * return
* разделители
    * ПРОБЕЛ
    * НОВАЯ-СТРОКА
    * ОТСТУП-ВПРАВО
    * ОТСТУП-ВЛЕВО
    * (
    * ):
    * ,
* операторы
    * ВЫРАЖЕНИЕ
    * ДРУГОЙ-ОПЕРАТОР
* идентификаторы

### Внутренние таблицы лексического анализатора

Таблица лексемы: ключевые слова.
<table>
    <tr>
        <th>Слово</th>
        <th>Код</th>
    </tr>
    <tr>
        <td>bool</td>
        <td>10</td>
    </tr>
    <tr>
        <td>int</td>
        <td>11</td>
    </tr>
    <tr>
        <td>void</td>
        <td>12</td>
    </tr>
    <tr>
        <td>return</td>
        <td>14</td>
    </tr>
</table>

Таблица лексем-разделителей:
<table>
    <tr>
        <th>Лексема</th>
        <th>Код</th>
    </tr>
    <tr>
        <td>ПРОБЕЛ</td>
        <td>1</td>
    </tr>
    <tr>
        <td>НОВАЯ-СТРОКА</td>
        <td>2</td></tr>
    <tr>
        <td>ОТСТУП-ВПРАВО</td>
        <td>4</td>
    </tr>
    <tr>
        <td>ОТСТУП-ВЛЕВО</td>
        <td>5</td>
    </tr>
    <tr>
        <td>(</td>
        <td>8</td>
    </tr>
    <tr>
        <td>):</td>
        <td>9</td>
    </tr>
    <tr>
        <td>,</td>
        <td>13</td>
    </tr>
</table>

Таблица лексем-операторов:
<table>
    <tr>
        <th>Лексема</th>
        <th>Код</th>
    </tr>
    <tr>
        <td>ВЫРАЖЕНИЕ</td>
        <td>3</td>
    </tr>
    <tr>
        <td>ДРУГОЙ-ОПЕРАТОР</td>
        <td>6</td>
    </tr>
</table>

Лексема "идентификатор": ИДЕНТИФИКАТОР, код - 7.

### Распознавание идентификаторов

Таблица переходов конечного распознавателя для семантического анализа лексемы-идентификатора:
<table>
    <tr>
        <th>Состояние</th>
		<th>[A-Za-z_]</th>
		<th>[0-9]</th>
		<th>Допустить</th>
    </tr><tr>
        <td>A</td>
		<td>B</td>
		<td>E</td>
		<td>0</td>
	</tr><tr>
        <td>B</td>
		<td>B</td>
		<td>B</td>
		<td>1</td>
	</tr><tr>
        <td>E</td>
		<td>E</td>
		<td>E</td>
		<td>0</td>
    </tr>
</table>

Автоматная грамматика для распознования лексемы-идентификатора:
```
1. <S> -> буква<A>
2. <A> -> буква<A>
3. <A> -> цифра<A>
4. <A> -> ε
```
Здесь буква - это [A-Za-z_].

### Проверка работы лексического анализатора на тестовых данных

#### Вход

```
bool isEven(int x):
    int remainder := x % 2
    return remainder = 0
```

#### Выход

Лексический разбор:
<table>
	<tr>
		<th>Текст программы</th>
		<th>Лексема</th>
		<th>Дескриптор</th>
	</tr><tr>
		<td>bool</td>
		<td>bool</td>
		<td>10</td>
	</tr><tr>
		<td>ПРОБЕЛ</td>
		<td>ПРОБЕЛ</td>
		<td>1</td>
	</tr><tr>
		<td>isEven</td>
		<td>ИДЕНТИФИКАТОР</td>
		<td>7</td>
	</tr><tr>
		<td>(</td>
		<td>(</td>
		<td>8</td>
	</tr><tr>
		<td>int</td>
		<td>int</td>
		<td>11</td>
	</tr><tr>
		<td>ПРОБЕЛ</td>
		<td>ПРОБЕЛ</td>
		<td>1</td>
	</tr><tr>
		<td>x</td>
		<td>ИДЕНТИФИКАТОР</td>
		<td>7</td>
	</tr><tr>
		<td>):</td>
		<td>):</td>
		<td>9</td>
	</tr><tr>
		<td>НОВАЯ-СТРОКА</td>
		<td>НОВАЯ-СТРОКА</td>
		<td>2</td>
	</tr><tr>
		<td>ОТСТУП-ВПРАВО</td>
		<td>ОТСТУП-ВПРАВО</td>
		<td>4</td>
	</tr><tr>
		<td>int remainder := x % 2</td>
		<td>ДРУГОЙ-ОПЕРАТОР</td>
		<td>6</td>
	</tr><tr>
		<td>НОВАЯ-СТРОКА</td>
		<td>НОВАЯ-СТРОКА</td>
		<td>2</td>
	</tr><tr>
		<td>return</td>
		<td>return</td>
		<td>14</td>
	</tr><tr>
		<td>ПРОБЕЛ</td>
		<td>ПРОБЕЛ</td>
		<td>1</td>
	</tr><tr>
		<td>remainder = 0</td>
		<td>ВЫРАЖЕНИЕ</td>
		<td>3</td>
	</tr><tr>
		<td>НОВАЯ-СТРОКА</td>
		<td>НОВАЯ-СТРОКА</td>
		<td>2</td>
	</tr><tr>
		<td>ОТСТУП-ВЛЕВО</td>
		<td>ОТСТУП-ВЛЕВО</td>
		<td>5</td>
	</tr>
</table>

Дескрипторный текст:
```
10 1 7 8 11 1 7 9 2 4 6 2 14 1 3 2 5
```