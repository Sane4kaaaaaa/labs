#include <iostream>
#include <vector>
#include <string>
//добавление комментариев
class Array {
private:
    std::vector<double> data;
    int size;

public:
    Array(int s) : size(s) {
        data.resize(size);
    }

    void fillArray() {
       // std::cout << "Введите элементы массива:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cin >> data[i];
        }
    }

    Array addArrays(const Array& arr) {
        if (size != arr.size) {
            throw std::invalid_argument("Arrays must be of the same size for addition");
        }
        Array result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] + arr.data[i];
        }
        return result;
    }

    Array subtractArrays(const Array& arr) {
        if (size != arr.size) {
            throw std::invalid_argument("Arrays must be of the same size for subtraction");
        }
        Array result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] - arr.data[i];
        }
        return result;
    }

    Array multiplyArrays(const Array& arr) {
        if (size != arr.size) {
            throw std::invalid_argument("Arrays must be of the same size for multiplication");
        }
        Array result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] * arr.data[i];
        }
        return result;
    }

    Array divideArrays(const Array& arr) {
        if (size != arr.size) {
            throw std::invalid_argument("Arrays must be of the same size for division");
        }
        Array result(size);
        for (int i = 0; i < size; ++i) {
            if (arr.data[i] == 0) {
                throw std::invalid_argument("Division by zero");
            }
            result.data[i] = data[i] / arr.data[i];
        }
        return result;
    }

    Array multiplyByScalar(double scalar) {
        Array result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    bool isEqual(const Array& arr) {
        if (size != arr.size) {
            throw std::invalid_argument("Arrays must be of the same size for equality check");
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] != arr.data[i]) {
                return false;
            }
        }
        return true;
    }

    void printArray(const std::string& name) {
        std::cout << name << "= ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int size;
   // std::cout << "Введите размерность массивов: ";
    std::cin >> size;

    Array array1(size);
    Array array2(size);

  //  std::cout << "Заполните первый массив:" << std::endl;
    array1.fillArray();

   // std::cout << "Заполните второй массив:" << std::endl;
    array2.fillArray();

    double scalar;
    //std::cout << "Введите скалярное значение: ";
    std::cin >> scalar;

    std::string massiv1 = "massiv1";
    std::string massiv2 = "massiv2";
    std::string summa = "summa";
    std::string raznost = "raznost";
    std::string proizv = "proizv";
    std::string delenie = "delenie";

    array1.printArray(massiv1);
    array2.printArray(massiv2);
    array1.addArrays(array2).printArray(summa);
    array1.subtractArrays(array2).printArray(raznost);
    array1.multiplyArrays(array2).printArray(proizv);
    array1.divideArrays(array2).printArray(delenie);
    array1.multiplyByScalar(scalar).printArray("mult chislo massiv1");
    array2.multiplyByScalar(scalar).printArray("mult chislo massiv2");

    if (array1.isEqual(array2)) {
        std::cout << "massivy ravny" << std::endl;
    }
    else {
        std::cout << "massivy ne ravny" << std::endl;
    }

    return 0;
}
