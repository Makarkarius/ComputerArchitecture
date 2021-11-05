import myRandom

#----------------------------------------------
# Класс дерева
class Tree :
    # Конструктор дерева
    def __init__(self):
        self.name = ""
        self.age = 0
    
    # Считывание параметров дерева из строки
    def ReadStrArray(self, strArray, i):
        if i >= len(strArray) - 1:
            return 0
        self.name = strArray[i]
        self.age = int(strArray[i + 1])
        i += 2
        return i

    # Случайная генерация параметров дерева
    def RandomIn(self):
        self.name = myRandom.randName()
        self.age = myRandom.randInt(0, 1e9)

    # Вывод данных дерева в файл
    def Write(self, ostream):
        ostream.write("Tree: name = {}, age = {}, quotient = {}".format(self.name, self.age, self.Quotient()))
        pass

    # Вычисление частного от деления числа гласных букв
    # в названии дерева на общую длину его названия
    def Quotient(self):
        numberOfVowels = 0
        for ch in self.name:
            if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A'
                or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U'):
                numberOfVowels += 1
        return numberOfVowels / len(self.name)