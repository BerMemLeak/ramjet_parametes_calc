# Решение прямой и обратной задачи по курсу Специальные двигатели МГТУ им. Баумана

Этот репозиторий содержит код для решения прямой и обратной задачи по курсу "Специальные двигатели". 

## Описание
Прямая задача находит коэффициент тяги через относительную площадь диффузора, после чего другие проектные параметры. Обратная задача находит относительную площадь диффузора через коэффициент тяги.

## Использование
Для использования этого кода вам нужно подставить свои исходные данные в конструктор класса. Также, необходимо определить значение λa из таблички и использовать его в коде.

## Пример

```C++
int main(int argc, char *argv[]) {

# Подставьте свои исходные данные

dvig d(3.2,   223.3,   1950,   1.27,   282,   1.4,   287,   0.5,   0.5,    1,   1,     0,      16);
#	 M_n,    T_n,    T_p,      k,     R,    k_b,   R_b,   f_vx,  f_kr,  f_a, fi_n, C_x_dop,  n
...
}


```
