//
// Created by Mouhammad DAHALANI on 2019-07-19.
//

#ifndef SPACE_INVADERS_EXPLOSION_HH
#define SPACE_INVADERS_EXPLOSION_HH
#pragma once

#include <SFML/Graphics.hpp>

namespace SpaceInvaders {
/*
    Représente une seule entité d'explosion
*/
    class Explosion {
    public:
        Explosion(const sf::Vector2f &position);

        bool isLifeOver() const;

        const sf::Vector2f &getPosition() const;

    private:
        sf::Vector2f m_position; // La position de l'explosion
        sf::Clock
                m_lifetimeCounter; // Horloge pour vérifier si l'explosion a survécu
    };
}
#endif //SPACE_INVADERS_EXPLOSION_HH
