#pragma once

class Counter {
public:
    Counter(int init_value = 1) : value(init_value) {}
    Counter& operator++() { this->value++; return *this; }
    Counter& operator--() { this->value--; return *this; }
    inline int get() const { return value; }

private:
    int value;
};
