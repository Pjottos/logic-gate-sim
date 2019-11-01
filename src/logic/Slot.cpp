#include <logic/Slot.hpp>
#include <algorithm>

using namespace logic;

Slot::Slot() {
}

Slot::~Slot() {
    for (auto input : inputs) {
        input.get().outputs.remove(*this);
    }
}

bool Slot::value() const {
    return this->_value;
}

void Slot::setValue(bool value) {
    if (updated)
        this->_value |= value;
    else {
        this->_value = value;
        this->updated = true;
    }
}

void Slot::send() {
    for (auto slot : outputs) {
        slot.get().setValue(this->_value);
    }
}

void Slot::reset() {
    this->updated = false;
}
