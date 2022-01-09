Ким Макар Максимович БПИ201<br>
Вариант 13

### Домашнее задание №5

#### Построение многопоточных приложение

#### Задание:

В гостинице 10 номеров рассчитаны на одного человека и 15 номеров рассчитаны на двух человек. В гостиницу приходят
клиенты дамы и клиенты джентльмены, и конечно они могут провести ночь в номере только с представителем своего пола. Если
для клиента не находится подходящего номера, он уходит искать ночлег в другое место. Создать многопоточное приложение,
моделирующее работу гостиницы

#### Решение:
Для выполнения данного задания была выбрана модель 
построения многопоточных приложений "Взаимодействующие
равные". Клиенты гостиницы - потоки. При попытке заселиться
или выселиться из отеля, они обращаются к инстансу класса Hotel, 
в котором хранится вся информация о номерах, используя при этом 
мьютекс. <br>
Источники информации:<br>
https://pro-prof.com/forums/topic/parallel-programming-paradigms
http://www.williamspublishing.com/PDF/5-8459-0388-2/part.pdf

#### Запуск:
Для запуска программы необходимо предоставить пути к входному
и выходному файлу соответственно в качестве аргументов командной строки.<br>
В выходном файле сначала должно стоять положительное целое значение n - 
количество посетителей отеля. <br>
Далее идёт n строк, в которых должен быть
описан каждый посетитель. <br><br>
Описание посетителя состоит из следующих параметров: 
- Имя (строка)
- Пол (1, если мужской; 0, если женский)
- Время заезда (целое, неотрицательное число)
- Время пребывания (целое, неотрицательное число)
