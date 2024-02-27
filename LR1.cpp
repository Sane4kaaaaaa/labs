#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    //Введите размерность исходного массива
    cin >> n;

    vector<double> arr(n);

    //Введите элементы массива
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Вывод исходного массива
    cout << arr.size() << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << fixed << setprecision(3) << arr[i] << " ";
    }
    cout << endl;

    // Добавление суммы и среднего арифметического
    double sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    arr.push_back(sum);
    arr.push_back(sum / (arr.size()-1));

    // Вывод массива после добавления
    for (int i = 0; i < arr.size(); i++) {
        cout << fixed << setprecision(3) << arr[i] << " ";
    }
    cout << endl;

    // нахождение максимума
    double max = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    // Подсчет отрицательных чисел и поиск максимального значени
    int negCount=0;
    for (int i = 0; i < arr.size(); ++i) {
	  if (arr[i] < 0) {
    	negCount++;
	     if (negCount % 2 == 0) {
	        arr[i] = max / 2;}} // Заменяем каждое второе отрицательное чис половиной максимум
	}


    // Вывод массива после выполнения операции
    for (int i = 0; i < arr.size(); i++) {
        cout << fixed << setprecision(3) << arr[i] << " ";
    }
    cout << endl;

    int choice;
    //Выберите действие (1 - добавить элемент, 2 - удалить элемент, 0 - выход)
    cin >> choice;

    while (choice != 0) {
        if (choice == 1) {
            double newElement;
            //Введите элемент для добавления
            cin >> newElement;
            arr.push_back(newElement);
            cout << "+: " << arr.size() << endl;
        }
        else if (choice == 2) {
            if (!arr.empty()) {
                arr.pop_back();
                cout << "-: " << arr.size() << endl;
            }
            else {
                //cout << "Массив пустой, невозможно удалить элемент." << endl;
            }
        }

        // Вывод массива после выполнения операции
        for (int i = 0; i < arr.size(); i++) {
            cout << fixed << setprecision(3) << arr[i] << " ";
        }
        cout << endl;

        // Добавление суммы и среднего арифметического
        sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        arr.push_back(sum);
        arr.push_back(sum / (arr.size()-1));

        // Вывод массива после выполнения операции
        for (int i = 0; i < arr.size(); i++) {
            cout << fixed << setprecision(3) << arr[i] << " ";
        }
        cout << endl;

       // нахождение максимума
    double max = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    // Подсчет отрицательных чисел и поиск максимального значени
    int negCount=0;
    for (int i = 0; i < arr.size(); ++i) {
	  if (arr[i] < 0) {
    	negCount++;
	     if (negCount % 2 == 0) {
	        arr[i] = max / 2;}} // Заменяем каждое второе отрицательное чис половиной максимум
	}

        // Вывод массива после выполнения операции
        for (int i = 0; i < arr.size(); i++) {
            cout << fixed << setprecision(3) << arr[i] << " ";
        }
        cout << endl;

        //cout << "Выберите действие (1 - добавить элемент, 2 - удалить элемент, 0 - выход): ";
        cin >> choice;
    }

    return 0;
}
