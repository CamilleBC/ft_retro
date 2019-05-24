#include "KeyPress.hpp"

KeyPress::KeyPress(size_t size) : size(size) {
    keys = new int[size];
    clear();
}

KeyPress::~KeyPress() { delete[] keys; }

void KeyPress::add(int key) {
    for (size_t i = 0; i < size; ++i)
        if (keys[i] == key_empty) {
            keys[i] = key;
            return;
        }
}

void KeyPress::clear() {
    for (size_t i = 0; i < size; ++i) {
        keys[i] = key_empty;
    }
}

bool KeyPress::contains(int key) {
    for (size_t i = 0; i < size; ++i)
        if (keys[i] == key) {
            return true;
        }
    return false;
}

void KeyPress::display_content() {
    for (size_t i = 0; i < size; ++i)
        if (keys[i] != key_empty) {
            std::cout << "KEY: " << keys[i] << std::endl;
        }
}

/* PRIVATE */

KeyPress::KeyPress() : size(0) {}

int const KeyPress::key_empty = -1;
