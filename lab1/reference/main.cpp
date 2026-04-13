import std;

int main() {

	std::println(
		"--------------------------------\n\
Лабораторная работа №: 1 \n\
Группа: 6112-100503D \n\
Автор: Широбоков Игнат Вадимович \n\
Вариант: 2 \n\
--------------------------------"
	);

	int element = 0;
	int n = 0;
	while(true)
	{
		std::print("Введите количество элементов: ");
		std::cin >> n;
		if (n > 0)
		{
			break;
		}
	}

	int prod = 1;
	
	for (int i = 0; i < n; i++)
	{
		std::println("Введите {} элемент: ", i + 1);

		std::cin >> element;
		prod *= element;
	}

	std::println("Количество элементов: {}; \nПроизведение элементов последовательности: {}. \n", n, prod);
	std::system("pause");

	return 0;
}