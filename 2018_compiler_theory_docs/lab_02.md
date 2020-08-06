# Лабораторная работа 2
## Построение КС-грамматик

## Цель
Освоение навыка классификации порождающих грамматик и построения контекстно-свободных грамматик.

## Задание
Выделить в форме БНФ множества классов лексем и получить формальное описание синтаксиса конструкции языка программирования в форме КС-грамматики.

## Выполнение

### Множество нетерминалов N

<table>
    <tr>
        <th>Нетерминал</th>
        <th>Индекс</th>
    </tr>
    <tr>
        <td>функция</td>
        <td>1001</td>
    </tr>
    <tr>
        <td>тип</td>
        <td>1002</td>
    </tr>
    <tr>
        <td>аргументы</td>
        <td>1003</td>
    </tr>
    <tr>
        <td>блок</td>
        <td>1004</td>
    </tr>
    <tr>
        <td>операторы</td>
        <td>1005</td>
    </tr>
    <tr>
        <td>оператор</td>
        <td>1006</td>
    </tr>
    <tr>
        <td>оператор возврата</td>
        <td>1007</td>
    </tr>
</table>

### Множество терминалов T
<table>
    <tr>
        <th>Терминал</th>
        <th>Индекс</th>
    </tr>
    <tr>
        <td>ПРОБЕЛ</td>
        <td>1</td>
    </tr>
    <tr>
        <td>НОВАЯ-СТРОКА</td>
        <td>2</td>
    </tr>
    <tr>
        <td>ВЫРАЖЕНИЕ</td>
        <td>3</td>
    </tr>
    <tr>
        <td>ОТСТУП-ВПРАВО</td>
        <td>4</td>
    </tr>
    <tr>
        <td>ОТСТУП-ВЛЕВО</td>
        <td>5</td>
    </tr>
    <tr>
        <td>ДРУГОЙ-ОПЕРАТОР</td>
        <td>6</td>
    </tr>
    <tr>
        <td>ИДЕНТИФИКАТОР</td>
        <td>7</td>
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
        <td>,</td>
        <td>13</td>
    </tr>
    <tr>
        <td>return</td>
        <td>14</td>
    </tr>
</table>

Пустая цепочка — индекс 0.

### Начальный нетерминал: 1001

### Правила грамматики P
```
 1) 1001 -> 1002 1 7 8 9 1004
 2) 1001 -> 1002 1 7 8 1003 9 1004
 3) 1003 -> 1002 7
 4) 1003 -> 1002 7 13 1 1003
 5) 1004 -> 2 4 1005 5
 6) 1005 -> 1006 2
 7) 1005 -> 1006 2 1005
 8) 1006 -> 1007
 9) 1006 -> 3
10) 1006 -> 6
11) 1002 -> 10
12) 1002 -> 11
13) 1002 -> 12
14) 1007 -> 14
15) 1007 -> 14 1 3
```