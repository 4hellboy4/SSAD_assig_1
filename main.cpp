#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DataStructure {
public:
    virtual void insert(int x) = 0;
    virtual void remove() = 0;
    virtual bool search(int x) = 0;
};

class SequentialDataStructure : public DataStructure {
public:
    virtual void pushBack(int x) = 0;
    virtual void pushFront(int x) = 0;
    virtual void popBack() = 0;
    virtual void popFront() = 0;
};

class DynamicDataStructure : public DataStructure {
public:
    virtual void resize(int new_size) = 0;
    virtual void clear() = 0;
};

class List : public SequentialDataStructure, public DynamicDataStructure {
private:
    vector<int> array;
    int size;
    int index;
public:

    List() {
        vector<int> temp(50);
        array = temp;
        index = -1;
        this->size = 50;
    }

    List(int capacity) : size(capacity) {
        vector<int> temp(capacity);
        array = temp;
    }

    void insert(int x) override {
        if (index + 1 >= size) {
            this->resize((size)*2);
        }
        this->index++;
        this->array.insert(this->array.begin()+index, x);
    }

    void remove() override {
        if (this->index > 0) {
            this->array.pop_back();
            this->index--;
        }
    }

    bool search(int x) override {
//        any_of(this->array.begin(), this->array.end(), );
        for (int i = 0; i < index + 1; i++) {
            if (this->array.at(i) == x)
                return true;
        }
        return false;
    }

    void pushFront(int x) override {
        if (index + 1 >= size) {
            this->resize(size*2);
        }
        this->index++;
        this->array.insert(this->array.begin(), x);
    }

    void pushBack(int x) override {
        if (index + 1 >= size) {
            this->resize(size*2);
        }
        this->index++;
        this->array.insert(this->array.begin()+index, x);
    }

    void popBack() override {
        this->array.pop_back();
        this->index--;
    }

    void popFront() override {
        if (!this->array.empty()) {
            this->array.erase(this->array.begin());
            this->index--;
        }
    }

    void resize(int new_size) override {
        this->size = new_size;
        vector<int> new_vector(size);
        for (int element : this->array) {
            new_vector.emplace_back(element);
        }
        this->array = new_vector;
    }

    void clear() override {
        this->array.clear();
    }

    void printNumbers() {
        for (int i = 0; i < this->index; ++i) {
            cout << this->array.at(i) << " ";
        }
    }
};


int main() {
    int n;
    cin >> n;

    List list = List();

    for (int i = 0; i < n; ++i) {
        string op;
        int num;
        cin >> op >> num;
        if (op == "insert") {
            list.insert(num);
        } else if (op == "remove") {
            list.remove();
        } else {
            cout << (list.search(num) ? "YES" : "NO") << endl;
        }
    }

    list.printNumbers();
}