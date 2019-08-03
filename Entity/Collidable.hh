//
// Created by Mouhammad DAHALANI on 2019-07-19.
//

#ifndef SPACE_INVADERS_COLLIDABLE_HH
#define SPACE_INVADERS_COLLIDABLE_HH
#pragma once

#include <SFML/Graphics.hpp>

namespace SpaceInvaders {
    class Collidable {
    public:
        Collidable(float width, float height);

        bool tryCollideWith(Collidable &other);

        sf::FloatRect getBox() const;

        virtual const sf::Vector2f &getPosition() const = 0;

        virtual void onCollide(Collidable &other) = 0;

    private:
        sf::Vector2f m_size;
    };
}
#endif //SPACE_INVADERS_COLLIDABLE_HH
