#ifndef LIST_H
#define LIST_H

#include <iostream>

// Клас "Список" (однозв'язний). Структура Node вкладена в клас.
class List {
public:
    // Вкладена структура - вузол списку
    struct Node {
        int   data;   // значення елемента
        Node* next;   // вказівник на наступний вузол
        Node(int d = 0) : data(d), next(nullptr) {}
    };

private:
    Node* head;   // початок списку
    Node* tail;   // кінець списку
    int   count;  // кількість елементів
    long long sum; // сума елементів

public:
    List();
    List(const List& other);              // конструктор копіювання
    List& operator=(const List& other);   // оператор присвоєння
    ~List();

    int       size() const { return count; }
    long long getSum() const { return sum; }
    bool      empty() const { return count == 0; }

    // --- Перевантажені оператори ---
    bool  operator>(const List& other) const;  // порівняння двох списків за сумою елементів
    List& operator+=(int value);               // додавання елемента в кінець списку

    // Додавання всіх елементів іншого списку в кінець цього
    void append(const List& other);

    // Введення / виведення полів
    friend std::istream& operator>>(std::istream& in, List& l);
    friend std::ostream& operator<<(std::ostream& out, const List& l);

private:
    void clear();
};

#endif
