#ifndef GATE_HPP
#define GATE_HPP

#include <functional>
#include <string>
#include <logic/Component.hpp>

namespace logic {
    class Gate : public Component {
    public:
        Gate(std::function<bool(bool,bool)> logic, std::string& name, sf::VertexArray& shape);

        void onTick() override;
    private:
        std::function<bool(bool,bool)> logic;
    };
}

#endif