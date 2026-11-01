#include "List.h"

List::List() : head(nullptr), tail(nullptr), count(0), sum(0) {}

List::List(const List& other) : head(nullptr), tail(nullptr), count(0), sum(0) {
    for (Node* p = other.head; p; p = p->next)
        *this += p->data;
}

List& List::operator=(const List& other) {
    if (this != &other) {
        clear();
        for (Node* p = other.head; p; p = p->next)
            *this += p->data;
    }
    return *this;
}

List::~List() { clear(); }

void List::clear() {
    while (head) {
        Node* t = head;
        head = head->next;
        delete t;
    }
    tail = nullptr;
    count = 0;
    sum = 0;
}

// Список A > список B, якщо сума елементів A більша за суму елементів B
bool List::operator>(const List& other) const {
    return sum > other.sum;
}

// Додає елемент в кінець списку
List& List::operator+=(int value) {
    Node* n = new Node(value);
    if (!head) head = tail = n;
    else { tail->next = n; tail = n; }
    ++count;
    sum += value;
    return *this;
}

void List::append(const List& other) {
    // копія кількості, щоб коректно працювало і при other == *this
    int n = other.count;
    Node* p = other.head;
    for (int i = 0; i < n && p; ++i, p = p->next)
        *this += p->data;
}

// Введення: спочатку кількість елементів, потім самі елементи
std::istream& operator>>(std::istream& in, List& l) {
    l.clear();
    int n;
    in >> n;
    for (int i = 0; i < n; ++i) {
        int v;
        in >> v;
        l += v;
    }
    return in;
}

// Виведення: [e1, e2, ...]  (сума = S)
std::ostream& operator<<(std::ostream& out, const List& l) {
    out << "[";
    for (List::Node* p = l.head; p; p = p->next) {
        out << p->data;
        if (p->next) out << ", ";
    }
    out << "]  (сума = " << l.sum << ")";
    return out;
}
