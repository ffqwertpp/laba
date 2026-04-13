#pragma once;

export module funcs;
import std;

export void setVector(std::vector<int>& vec, int n) {
    for (int i = 0; i < n; i++)
    {
        std::println("Введите {} элемент: ", i + 1);

        int element = 0;
        std::cin >> element;
        vec.push_back(element);
    }
}

export void setVectorRandom(std::vector<int>& vec, int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-10, 10);

    vec.resize(n);

    for (int& x : vec) {
        x = dist(gen);
    }
}

export void getVector(std::vector<int>& vec, int n) {
    for (int i = 0; i < n; ++i)
    {
        std::println("{} элемент: {}", i + 1, vec[i]);
    }
}

export void processVector(std::vector<int>& vec, int n) {
    int prod = 1;
    for (int& x : vec) {
        prod *= x;
    }
    std::println("Произведение элементов последовательности: {} \n Количество элементов {}", prod, n);
}