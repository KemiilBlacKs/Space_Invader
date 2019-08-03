//
// Created by Mouhammad DAHALANI on 2019-07-18.
//

#ifndef SPACE_INVADERS_WIDGET_HH
#define SPACE_INVADERS_WIDGET_HH

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Utils/ResourceHolder.hh"

namespace gui {
    class Widget {
    public:
        virtual void handleEvent(sf::Event e, const sf::RenderWindow &window) = 0;

        virtual void render(sf::RenderTarget &renderer) = 0;

        virtual void setPosition(const sf::Vector2f &pos) = 0;

        virtual sf::Vector2f getSize() const = 0;

        class Text : public sf::Text {
        public:
            Text();
        };

        class Rectangle : public sf::RectangleShape {
        public:
            bool isRolledOn(const sf::RenderWindow &window) const;
            bool isClicked(sf::Event, const sf::RenderWindow &window);
        };
    };
}

#endif //SPACE_INVADERS_WIDGET_HH
