#ifndef COMPONENTMENU_HPP
#define COMPONENTMENU_HPP

#include <SFML/Graphics/Drawable.hpp>

namespace ui {
    class ComponentMenu : public sf::Drawable {
    public:
        ComponentMenu();
        ~ComponentMenu();
    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    };
}

#endif