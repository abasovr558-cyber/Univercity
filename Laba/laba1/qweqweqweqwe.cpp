#include <iostream>
#include <chrono>
#include <stack>

// Функция проверки, пуст ли стек
bool isEmpty(std::stack<int>& st) {
    return st.empty();
}

template <typename Func, typename... Args>
auto measure_execution_time(Func&& func, Args&&... args) {
    auto start_time = std::chrono::high_resolution_clock::now();  // Начинаем отсчет времени
    auto result = func(std::forward<Args>(args)...);  // Выполняем переданную функцию с аргументами
    auto end_time = std::chrono::high_resolution_clock::now();  // Останавливаем отсчет времени

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);  // Вычисляем продолжительность в миллисекундах
    return std::make_pair(result, duration.count());  // Возвращаем результат и время выполнения
}


int main() {
    return 0;
}