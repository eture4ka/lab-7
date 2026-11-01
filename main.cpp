#include <iostream>
#include "List.h"
using namespace std;

// Сортування масиву списків за зростанням сум (метод бульбашки через operator>)
void sortLists(List* arr, int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (arr[j] > arr[j + 1]) {
                List tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

void printAll(const List* arr, int n) {
    for (int i = 0; i < n; ++i)
        cout << "  Список " << i + 1 << ": " << arr[i] << endl;
}

int main() {
    int n;
    cout << "Введіть кількість списків: ";
    cin >> n;
    if (n <= 0) {
        cout << "Некоректна кількість списків." << endl;
        return 1;
    }

    List* lists = new List[n];

    cout << "Для кожного списку введіть кількість елементів, а потім самі елементи:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Список " << i + 1 << ": ";
        cin >> lists[i];
    }

    cout << "\nВихідний масив списків:" << endl;
    printAll(lists, n);

    // 1. Сортування за зростанням сум
    sortLists(lists, n);
    cout << "\nПісля сортування за зростанням сум:" << endl;
    printAll(lists, n);

    // 2. Додавання елементів списку з найменшою сумою до списку з найбільшою
    if (n >= 2) {
        List& smallest = lists[0];       // після сортування - найменша сума
        List& largest  = lists[n - 1];   // після сортування - найбільша сума
        largest.append(smallest);
        cout << "\nДодано елементи списку з найменшою сумою до списку з найбільшою:" << endl;
        printAll(lists, n);
    } else {
        cout << "\nДля об'єднання потрібно щонайменше 2 списки." << endl;
    }

    delete[] lists;
    return 0;
}
