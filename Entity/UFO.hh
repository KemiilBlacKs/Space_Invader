//
// Created by Mouhammad DAHALANI on 2019-07-19.
//

#ifndef SPACE_INVADERS_UFO_HH
#define SPACE_INVADERS_UFO_HH
#pragma once

#include "../Utils/Animation.hh"
#include "../Utils/Random.hh"
#include "Collidable.hh"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace SpaceInvaders {
    class UFO : public Collidable {
    public:
        enum class State {
            Waiting, Flying, Destroyed
        };

        UFO(Random<> &rand);

        State getState() const;

        void update(float dt);

        void draw(sf::RenderTarget &window);

        const sf::Vector2f &getPosition() const;

        void onCollide(Collidable &other);

    private:
        Random<> &m_rng;

        sf::RectangleShape m_sprite;
        float m_vx;
        State m_state;
        Animation m_animation;

        sf::Sound m_flyingSound;
    };
}
#endif //SPACE_INVADERS_UFO_HH
