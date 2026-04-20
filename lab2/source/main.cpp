import std;
import funcs;

int main() {
    std::println(
"--------------------------------\n\
Лабораторная работа №: 2 \n\
Группа: 6112-100503D \n\
Автор: Широбоков Игнат Вадимович \n\
Вариант: 2 \n\
--------------------------------");

    std::vector<int> vec = {};
    int choice = 100;
    int n = 0;

    std::print("Введите количество элементов:");
    std::cin >> n;

	while (n <= 0) {
        std::println("Количество элементов должно быть положительным числом");
        std::print("Введите количество элементов:");
        std::cin >> n;
    }



    while (choice != 0) {
        std::print("1. Для ручного ввода элементов \n\
2. Для генерации случайных чисел \n\
3. Для вывода результата \n\
0. Выход\n");

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            setVector(vec, n);
            getVector(vec);
            break;
        case 2:
            setVectorRandom(vec, n);
            getVector(vec);
            break;
        case 3:
            processVector(vec, n);
            break;
        case 0:
            break;
        default:
            std::println("Неверный ввод");
            break;
        }
    }

    return 0;
}
