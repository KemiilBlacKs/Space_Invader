//
// Created by Mouhammad DAHALANI on 2019-07-22.
//

#ifndef SPACE_INVADERS_INVADER_HH
#define SPACE_INVADERS_INVADER_HH
#pragma once

#include <SFML/Graphics.hpp>

#include "Collidable.hh"

namespace SpaceInvaders {
/*
    Classe pour représenter un envahisseur unique
*/
    class Invader : public Collidable {
    public:
        enum class Type {
            Octopus,
            Crab,
            Squid,
        };

        Invader(const sf::Vector2f &initialLocation, Type type);

        void move(float x, float y);

        const sf::Vector2f &getPosition() const;

        bool isAlive() const;

        Type getType() const;

        void onCollide(Collidable &other);

        void makeAlive() {
            m_isAlive = true;
            m_location = m_initialPosition;
        }

    private:
        const sf::Vector2f m_initialPosition;
        sf::Vector2f m_location;
        bool m_isAlive = false;
        Type m_type;

    public:
        constexpr static float WIDTH = 48;
        constexpr static float HEIGHT = 32;
    };
}
#endif //SPACE_INVADERS_INVADER_HH
