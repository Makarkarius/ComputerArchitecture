import sys
from extender import *

#----------------------------------------------
def error1():
    print("Incorrect command line!\n")
    print("If you want to have your own data you must write:\n")
    print("python main.py -f <inputFileName> <output1FileName> <output2FileName>\n\n")
    print("If you want to test it on randomised data you must write:\n")
    print("python main.py -t <number of elements> <output1FileName> <output2FileName>\n\n")

if __name__ == '__main__':
    if len(sys.argv) == 5:
        if sys.argv[1] == "-f": # Случай с готовыми исходными данными
            inputFileName  = sys.argv[2]
            output1FileName = sys.argv[3]
            output2FileName = sys.argv[4]
            
            # Чтение исходного файла, содержащего данные, разделенные пробелами и переводами строки
            ifile = open(inputFileName)
            str = ifile.read()
            ifile.close()


            # Формирование массива строк, содержащего чистые данные в виде массива строк символов.
            strArray = str.replace("\n", " ").split(" ")

            print('==> Start')

            container = Container()
            container.ReadStrArray(strArray) # Заполнение контейнера из массива строк

        elif sys.argv[1] == "-t": # Случай требующий случайной генерации нужного числа растений
            numOfElems = int(sys.argv[2])
            output1FileName = sys.argv[3]
            output2FileName = sys.argv[4]

            print('==> Start')

            container = Container()
            container.RandomIn(numOfElems) # Заполнение контейнера случайно генерируемыми растениями
        else: # Некорректный ввод параметров
            error1()
            exit()
        
        ofile = open(output1FileName, 'w')
        container.Write(ofile) # Вывод данных в файл
        ofile.close()

        container.Sort() # Сортировка контейнера

        ofile = open(output2FileName, 'w')
        container.Write(ofile) # Вывод данных в файл
        ofile.close()

        print('==> Finish')
    else: # Некорректный ввод параметров
        error1()
        exit()


    
