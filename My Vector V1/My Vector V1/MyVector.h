#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

const int DEFAULT_CAPACITY = 10;

template<class T>
class MyVector {
private:
    T* the_array;
    int capacity;
    int items_used;

public:
    MyVector() {
        items_used = 0;
        this->capacity = DEFAULT_CAPACITY;
        the_array = new T[capacity];
    }
    MyVector(int capacity) {
        items_used = 0;
        this->capacity = capacity;
        the_array = new T[capacity];
    }
    //copy constructor
    MyVector(MyVector& original) {
        for (int i = 0; i < capacity; i++) {
            this->insert(original.read(i));
        }
    }
    void insert(T value) {
        if (items_used >= capacity) {
            T* the_array2 = new T[capacity * 2];
            for (int i = 0; i < items_used; i++) {
                the_array2[i] = the_array[i];
            }
            delete[] the_array;
            the_array = the_array2;
        }
        the_array[items_used] = value;
        items_used++;
    }
    void insert(T value, int index) {
        if ((index < 0) || (index > capacity)) {
            throw std::exception("Index out of range");
        }
        if (items_used != capacity) {
            for (int i = items_used - 1; i >= index; i--) {
                the_array[i + 1] = the_array[i];
            }
            the_array[index] = value;
            items_used++;
        }
        else {
            capacity = capacity * 2;
            T* the_array2 = new T[capacity];
            for (int i = 0; i < items_used; i++) {
                the_array2[i] = the_array[i];
            }
            delete[] the_array;
            the_array = the_array2;
            insert(value, index);
        }
    }

    T read(int index) {
        return the_array[index];
    }
    T change(T newValue, int index) {
        T temp = the_array[index];
        the_array[index] = newValue;
        return temp;
    }
    T remove(int index) {
        T temp = the_array[index];
        if (index > capacity) {
            std::cout << "index out of range of current vector" << std::endl;
        }
        else {
            T* the_array2 = new T[capacity];
            int temp_index = 0;
            for (int i = 0; i < capacity; i++) {
                if (i != index) {
                    the_array2[temp_index] = the_array[i];
                    temp_index++;
                }
            }
            delete[] the_array;
            the_array = the_array2;
            items_used--;
        }
        return 0;
    }
    int return_items_used() {
        return items_used;
    }
    ~MyVector() {
        delete[] the_array;

    }
    friend MyVector<T> operator+(MyVector<T>& original, const T new_value) {
        MyVector<T> temp(original);
        temp.insert(new_value);
        return temp;
    }
    friend MyVector<T> operator-(MyVector<T>& original, const T deleted_value) {
        int items_used = original.return_items_used();
        /*MyVector<T> temp(items_used);
        for (int i = 0; i < items_used; i++) {
            if (original[i] != deleted_value) {
                temp[i] = original[i];
            }
        }*/
        MyVector<T> temp(original);
        for (int i = 0; i < items_used; i++) {
            if (original[i] == deleted_value) {
                temp.remove(i);
            }
        }
        return temp;
    }
    T& operator[](int index);
};


template<class T>
std::ostream& operator<<(std::ostream& output, MyVector<T>& original) {
    int items_used = original.return_items_used();
    std::cout << '[';
    for (int i = 0; i < items_used; i++) {
        std::cout << original[i];
        if (i < items_used - 1) {
            std::cout << ',' << ' ';;
        }
    }
    std::cout << ']';
    return output;
}
template <class T>
T& MyVector<T>::operator[](int index) {
    return the_array[index];
}
#endif