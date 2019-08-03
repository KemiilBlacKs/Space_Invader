//
// Created by Mouhammad DAHALANI on 2019-07-22.
//

#ifndef SPACE_INVADERS_MANAGERINVADER_HH
#define SPACE_INVADERS_MANAGERINVADER_HH
#pragma once

#include <SFML/Audio.hpp>
#include <vector>

#include "AnimationRenderer.hh"
#include "../Entity/Invader.hh"
#include "../Entity/Projectile.hh"
#include "../Utils/DisplayInfo.hh"
#include "../Utils/Random.hh"

namespace SpaceInvaders {
    class World;

    using CollisionResult = std::pair<int, std::vector<sf::Vector2f>>;

/**
    Classe pour gérer l'image et la mise à jour des envahisseurs
*/
    class ManagerInvader {
    public:
        ManagerInvader(World &world);

        // Déplace tous les envahisseurs vers la gauche ou vers la droite, si l'horloge a atteint
        // un certain temps
        void tryStepInvaders();

        // Draws all of the alive invaders
        void drawInvaders(sf::RenderTarget &target);

        // Essaie d'entrer en collision avec les envahisseurs et les projectiles
        // Retourne les points de collision
        CollisionResult
        tryCollideWithProjectiles(std::vector<Projectile> &projectiles);

        // C'est pour tirer des projectiles de l'ennemi
        sf::Vector2f getRandomLowestInvaderPoint(Random<> &random);

        int getAliveInvadersCount() const;

        /*
            Ces deux fonctions sont destinées à l'initialisation des envahisseurs.
            Il ajoutera un envahisseur à la fois, tous les envahisseurs ont été ajoutés.
        */
        void initAddInvader();

        bool areInvadersAlive() const;

    private:
        // Changement de temps entre les pas de l'étranger en fonction du nombre de personnes vivantes.
        void updateStepDelay();

        // Vérifie la position des envahisseurs pour voir si tous les extraterrestres doivent se déplacer vers le bas.
        // Ou si le jeu est terminé
        bool testInvaderPosition(const Invader &invader) const;

        std::vector<Invader> m_invaders{};
        sf::Clock m_stepTimer;
        sf::Time m_stepGap;

        World &m_world;

        AnimationRenderer m_invaderRenderer;
        unsigned m_aliveInvaders{};

        bool m_hasAllInvadersBeenAdded = false;

        bool m_isMovingLeft = false;
        bool m_moveDown = false;

        int m_initX = 0;
        int m_initY = 4;
        int m_ticks = 0;

        sf::Sound m_stepSounds[4];
        sf::Sound m_invaderKilledSound;
    };
}
#endif //SPACE_INVADERS_MANAGERINVADER_HH
