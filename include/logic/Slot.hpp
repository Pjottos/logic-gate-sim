#ifndef SLOT_HPP
#define SLOT_HPP

#include <forward_list>
#include <functional>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace logic {
    class Slot : public sf::Transformable {
    public:
        Slot();
        ~Slot();

        bool value() const;

    protected:
        std::forward_list<std::reference_wrapper<Slot>> outputs;
        std::forward_list<std::reference_wrapper<Slot>> inputs;
        
        void setValue(bool value);
        void send();
        void reset();

    private:
        bool _value;
        bool updated;

    friend class Component;
    friend class Gate;
    };
    
    inline bool operator ==(const Slot& left, const Slot& right) {
        return &left == &right;
    }
    inline bool operator !=(const Slot& left, const Slot& right) {
        return &left == &right;
    }
}

#endif