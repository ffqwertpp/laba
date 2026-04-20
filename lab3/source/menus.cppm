#pragma once

export module menus;
import std;
import pawn;

export void inGameMenu(std::vector<Pawn>& pawns);

export void showPawns(const std::vector<Pawn>& pawns) {
    std::println("Пешки на поле: \n");
        for (const auto& pawn : pawns) {
            std::println("Позиция: \n X:{} Y:{} \nЦвет: {}\n", std::to_string(pawn.getX()), std::to_string(pawn.getY()), (pawn.getColor() ? "Белая" : "Черная"));
        }    
}

export void enterMenu(std::vector<Pawn>& pawns) {
    int choice = 100;

    while(choice > 0) {
        std::println("1. Добавить пешку на поле\n\
2. Удалить пешку с поля\n\
3. Вывести вектор пешек\n\
4. Начать игру\n\
0. Выйти из программы");
        std::cin >> choice;

        switch(choice) {
            case 1: {
                if (pawns.size() >= 16) {
                    std::println("Максимальное количество пешек на поле достигнуто");
                    break;
                }
                std::println("Введите позицию пешки(x y):");
                int x, y;
                std::cin >> x >> y;
                std::println("Выберите цвет пешки (0 - черная, 1 - белая):");
                bool color;
                std::cin >> color;
                for (const auto& pawn : pawns) {
                    if (pawn.getX() == x && pawn.getY() == y) {
                        std::println("Пешка уже существует на этой позиции");
                        break;
                    }
                }
                pawns.push_back(Pawn(x, y, color, true, true));
                break;
            }

            case 2: {
                int index = 0;
                std::println("Введите позицию пешки для удаления(x y):");
                int x, y;
                std::cin >> x >> y; 
                for (auto& pawn : pawns) {
                    if (pawn.getX() == x && pawn.getY() == y) {
                        index = &pawn - &pawns[0];
                        break;
                    }
                }
                if (index != 0) {
                    pawns.erase(pawns.begin() + index);
                    std::println("Пешка удалена");
                } else {
                    std::println("Пешка не найдена");
                }
                break;
            }

            case 3:
                showPawns(pawns);
                break;
            case 4:
                inGameMenu(pawns);
                break;

            case 0:
                std::println("Выход из программы");
                break;

            default:
                std::println("Неверный выбор");
        }
    }
}

export void inGameMenu(std::vector<Pawn>& pawns) {
    int choice = 100;

    while (choice > 0) {
        std::println("1. Сходить пешкой(Ввести начальную и конечную позиции)\n\
2. Вернуться в главное меню\n\
3. Вывести вектор пешек\n");
        std::cin >> choice;

        switch(choice > 0) {
            case 1: {
                std::println("Введите начальную позицию пешки(x y):");
                int startX, startY;
                std::cin >> startX >> startY;
                std::println("Введите конечную позицию пешки(x y):");
                int endX, endY;
                std::cin >> endX >> endY;

                Pawn pawnToMove = findPawnWhichCanMoveOnCoordinates(endX, endY, pawns);

                if (pawnToMove.getX() == startX && pawnToMove.getY() == startY) {
                    if (pawnToMove.canMoveWithAnotherPawns(endX, endY, pawns)) {
                        std::println("Пешка успешно перемещена");
                    } else if (pawnToMove.canCaptureWithAnotherPawns(endX, endY, pawns)) {
                        std::println("Пешка успешно перемещена и съела другую пешку");
                    } else {
                        std::println("Невозможно переместить пешку на эту позицию, так как она занята другой пешкой");
                    }
                } else {
                    std::println("Пешка не может двигаться на эту позицию");
                }
                break;
            }
            case 2:
                return;
            case 3:
                showPawns(pawns);
                break;
            default:
                std::println("Неверный выбор");
        }
    }
}