import std;
import pawn;
import menus;

int main() {
    std::println(
"--------------------------------\n\
Лабораторная работа №: 3 \n\
Группа: 6112-100503D \n\
Автор: Широбоков Игнат Вадимович \n\
Вариант: 14 \n\
--------------------------------"
    );
    
    std::vector<Pawn> pawns = {};
    enterMenu(pawns);
    return 0;
}