#include <iostream>
using namespace std;

const int N = 50; // Максимальний розмір масиву

// Загальні функції
void input_array(int arr[], int &size) {
    do {
        cout << "Enter the number of elements (2 to 50): ";
        cin >> size;
        if (cin.fail() || size < 2 || size > N) {
            cout << "Error: Size must be in the range [2, 50]. Try again." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    } while (size < 2 || size > N);

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void output_array(const int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функції для task1
int show_multiples_of_10(const int arr[], int size) {
    int count = 0;

    cout << "Numbers divisible by 10 in reverse order: ";
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] % 10 == 0) {
            cout << arr[i] << " ";
            count++;
        }
    }
    cout << endl;

    return count;
}

void task1() {
    int arr[N]; // Масив
    int size;   // Кількість елементів

    // Введення елементів
    input_array(arr, size);

    // Виведення масиву
    output_array(arr, size);

    // Виведення чисел, кратних 10, та їх кількості
    int count = show_multiples_of_10(arr, size);
    cout << "Count of numbers divisible by 10: " << count << endl;
}

// Функції для task2
void duplicate_even_numbers(int arr[], int &size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            // Перевірка на переповнення масиву
            if (size >= N) {
                cout << "Error: Cannot duplicate, array size limit exceeded!" << endl;
                return;
            }

            // Зсув елементів вправо для дублювання
            for (int j = size; j > i; j--) {
                arr[j] = arr[j - 1];
            }

            size++;    // Збільшуємо розмір масиву
            i++;       // Пропускаємо дубльований елемент
        }
    }
}

void task2() {
    int arr[N]; // Масив
    int size;   // Кількість елементів

    // Введення масиву
    input_array(arr, size);

    // Виведення початкового масиву
    cout << "Initial array:" << endl;
    output_array(arr, size);

    // Дублювання парних чисел
    duplicate_even_numbers(arr, size);

    // Виведення зміненого масиву
    cout << "Modified array with duplicated even numbers:" << endl;
    output_array(arr, size); 
}

// Головна функція
int main() {
    int menu;
    cout << "\nEnter task number: ";
    cin >> menu;
    switch (menu) {
        case 1: 
            task1(); 
            break;
        case 2: 
            task2(); 
            break;
        default: 
            cout << "\nUnknown operation!" << endl;
    }

    return 0;
}