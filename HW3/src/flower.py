from enum import Enum
import myRandom

#----------------------------------------------
# Перечисляемый тип представляющий типа цветка
class FlowerType(Enum):
    DOMESTIC = 1
    GARDEN = 2
    WILD = 3
    INVALID_PLACE_NUMBER = 0

# Класс цветка
class Flower :
    # Конструктор цветка
    def __init__(self):
        self.name = ""
        self.flowerType = FlowerType.INVALID_PLACE_NUMBER.name
    
    # Считывание параметров цветка из строки
    def ReadStrArray(self, strArray, i):
        if i >= len(strArray) - 1:
            return 0
        self.name = strArray[i]
        self.flowerType = FlowerType(int(strArray[i + 1]) 
            if int(strArray[i + 1]) <= 3 and int(strArray[i + 1]) >= 0 else 0).name
        i += 2
        return i

    # Случайная генерация параметров цветка
    def RandomIn(self):
        self.name = myRandom.randName()
        self.flowerType = FlowerType(myRandom.randInt(1, 3)).name

    # Вывод данных цветка в файл
    def Write(self, ostream):
        ostream.write("Flower: name = {}, flower type = {}, quotient = {}".format(self.name, self.flowerType, self.Quotient()))
        pass

    # Вычисление частного от деления числа гласных букв
    # в названии цветка на общую длину его названия
    def Quotient(self):
        numberOfVowels = 0
        for ch in self.name:
            if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A'
                or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U'):
                numberOfVowels += 1
        return numberOfVowels / len(self.name)
