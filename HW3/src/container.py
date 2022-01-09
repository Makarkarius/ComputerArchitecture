import tree
import shrub
import flower
import myRandom

#----------------------------------------------
# Класс контейнера для растений
class Container:
    # Конструктор контейнера
    def __init__(self):
        self.store = []

    # Заполнение контейнера растениями из массива строк
    def ReadStrArray(self, strArray):
        arrayLen = len(strArray)
        i = 0   # Индекс, задающий текущую строку в массиве
        while i < arrayLen:
            str = strArray[i]
            key = int(str)   # преобразование в целое 
            if key == 1: # признак дерева
                plant = tree.Tree()
            elif key == 2: # признак кустарника
                plant = shrub.Shrub()
            elif key == 3: # признак цветка
                plant = flower.Flower()
            else:
                # что-то пошло не так. Должен быть известный признак
                return
            i += 1
            i = plant.ReadStrArray(strArray, i) # чтение растения с возвратом позиции за ним
            self.store.append(plant)

    # Заполнение контейнера случайно генерируемыми растениями
    def RandomIn(self, numOfElems):
        for i in range(numOfElems):
            key = myRandom.randInt(1, 3)
            if key == 1: # признак дерева
                plant = tree.Tree()
            elif key == 2: # признак кустарника
                plant = shrub.Shrub()
            elif key == 3: # признак цветка
                plant = flower.Flower()
            plant.RandomIn()
            self.store.append(plant)

    # Вывод всех элементов контейнера в файл
    def Write(self, ostream):
        ostream.write("Container stores {} plants:\n".format(len(self.store)))
        for i in range(len(self.store)):
            ostream.write("{}: ".format(i))
            self.store[i].Write(ostream)
            ostream.write("\n")
        pass

    # Сортировка контейнера по возрастанию
    # с помощью прямого включения
    def Sort(self):
        for i in range(len(self.store)):
            curr_plant = self.store[i]
            idx = i
            while idx > 0 and self.store[idx - 1].Quotient() > curr_plant.Quotient():
                self.store[idx] = self.store[idx - 1]
                idx -= 1
            self.store[idx] = curr_plant

