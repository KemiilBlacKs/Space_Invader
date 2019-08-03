//
// Created by Mouhammad DAHALANI on 2019-07-15.
//

#ifndef SPACE_INVADERS_WORLD_HH
#define SPACE_INVADERS_WORLD_HH
#pragma once

#include <SFML/Graphics.hpp>

#include "AnimationRenderer.hh"
#include "../Entity/Explosion.hh"
#include "../Entity/Player.hh"
#include "../Entity/Projectile.hh"
#include "../Entity/Shield.hh"
#include "../Entity/UFO.hh"
#include "ManagerInvader.hh"
#include "StarsBackground.hh"
#include "../Utils/Random.hh"

namespace SpaceInvaders {
/**
    Classe qui gère le monde et les interactions entre les différentes classes.
   entites
*/
    class World {
    public:
        World();

        void input();

        int update(float dt);

        void draw(sf::RenderTarget &target);

        const Player &getPlayer() const;

        bool isGameOver() const;

        void setGameIsOver() { m_isGameOver = true; }

    private:
        void playerProjectileInput();

        void enemyProjectileFire();

        CollisionResult getCollisionResult(float dtt);

        void updateProjectiles(float dt,
                               std::vector<sf::Vector2f> &collisionPoints);

        AnimationRenderer m_projectileRenderer;
        ManagerInvader m_invaders;
        Player m_player;
        UFO m_ufo;
        StarsBackground m_background;

        std::vector<Projectile> m_projectiles;
        std::vector<Explosion> m_explosions;
        std::vector<Shield> m_shields;

        sf::RectangleShape m_explodeShape;
        sf::Clock m_invaderShotClock;
        sf::Clock m_playerShotClock;
        sf::Clock m_animTimer;

        sf::Sound m_playerShoot;
        sf::Music m_music;

        Random<> m_rng;

        bool m_isGameOver = false;
    };
}
#endif //SPACE_INVADERS_WORLD_HH
