//
// Created by Mouhammad DAHALANI on 2019-07-15.
//

#ifndef SPACE_INVADERS_PLAYER_HH
#define SPACE_INVADERS_PLAYER_HH
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Utils/Animation.hh"
#include "Collidable.hh"

namespace SpaceInvaders {
/**
    Représente le joueur
*/
    class Player : public Collidable {
    public:
        constexpr static int WIDTH = 44;
        constexpr static int HEIGHT = 32;

        Player();

        void input();

        void update(float dt);

        void draw(sf::RenderTarget &target);

        // Obtenir les coordonnées de l'arme
        sf::Vector2f getGunPosition() const;

        const sf::Vector2f &getPosition() const;

        void onCollide(Collidable &other);

        int getLives() const;

        bool isAlive() const;

        void tryRevive();

    private:
        void restart();

        sf::RectangleShape m_sprite;
        Animation m_deathAnimation;
        sf::Vector2f m_velocity;
        sf::Clock m_deathTimer;

        bool m_isAlive = true;
        int m_livesLeft = 5;

        sf::Sound m_deathSound;
    };
}
#endif //SPACE_INVADERS_PLAYER_HH
