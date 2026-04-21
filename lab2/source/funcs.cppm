#pragma once

export module funcs;
import std;

export std::vector<int> setVector(int n) {
    std::vector<int> vec = {};
    
    for (int i = 0; i < n; i++)
    {
        std::println("Введите {} элемент: ", i + 1);

        int element = 0;
        std::cin >> element;
        vec.push_back(element);
    }

    return vec;
}

export std::vector<int> setVectorRandom(int n) {
    std::vector<int> vec(n); 

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-10, 10);

    for (int& x : vec) {
        x = dist(gen);
    }

    return vec;
}

export void getVector(const std::vector<int>& vec) {
    for (const int& x : vec)
    {
        std::print("{} ", x);
    }
    std::println("");
}

export int processVector(const std::vector<int>& vec) {
    int prod = 1;
    for (const int& x : vec) {
        prod *= x;
    }
    return prod;
}