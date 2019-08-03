/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  ManagerInvader.cpp                                         #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/22/19 09:54:55 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 07/29/19 11:31:53 by Dahalani Mouhammad           #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include <iostream>

#include "ManagerInvader.hh"
#include "../Utils/ResourceHolder.hh"
#include "World.hh"

namespace SpaceInvaders {
    namespace {
        const int MAX_INVADERS = 55;
    }

    ManagerInvader::ManagerInvader(World &world)
            : m_stepGap(sf::seconds(0.5f)), m_world(world),
              m_invaderRenderer(124, 145, Invader::WIDTH, Invader::HEIGHT,
                                ResourceHolder::get().textures.get("si/invaders")) {
        // Disposition des envahisseurs
        Invader::Type types[] = {Invader::Type::Squid, Invader::Type::Crab,
                                 Invader::Type::Crab, Invader::Type::Octopus,
                                 Invader::Type::Octopus};
        // Ajout d'envahisseurs dans le std::vector
        const int GAP = 10;
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 11; x++) {
                // Calculer la position de l'envahisseur
                float invaderX =
                        x * Invader::WIDTH + (GAP * x * 3) + Invader::WIDTH;
                float invaderY =
                        y * Invader::HEIGHT + (GAP * y) + Invader::HEIGHT * 4;
                m_invaders.emplace_back(sf::Vector2f{invaderX, invaderY}, types[y]);
            }
        }

        // Chargement des sons
        for (int i = 0; i < 4; i++) {
            m_stepSounds[i].setBuffer(ResourceHolder::get().soundBuffers.get(
                    "si/fastinvader" + std::to_string(i + 1)));
        }
        m_invaderKilledSound.setBuffer(
                ResourceHolder::get().soundBuffers.get("si/invaderkilled"));
    }

    void ManagerInvader::tryStepInvaders() {
        // Etape uniquement si le temps est terminée.
        if (m_stepTimer.getElapsedTime() > m_stepGap) {
            m_invaderRenderer.nextFrame();
            // Calculer le montant à l'étape
            bool moveDown = false;
            float step = m_isMovingLeft ? -10.0f : 10.0f;
            if (m_moveDown) {
                step *= -1;
            }
            m_stepSounds[m_ticks++ % 4].play();

            // Déplacez les envahisseurs
            for (auto &invader : m_invaders) {
                if (!invader.isAlive())
                    continue;
                invader.move(step, 0.0f);
                if (m_moveDown) {
                    invader.move(0, Invader::HEIGHT / 2.0f);
                } else if (!moveDown) {
                    // Vérifier la position de l'envahisseur pour voir si tous les envahisseurs doivent se déplacer vers le bas.
                    moveDown = testInvaderPosition(invader);
                }
            }

            if (m_moveDown)
                m_isMovingLeft = !m_isMovingLeft;
            m_moveDown = moveDown;
            m_stepTimer.restart();
        }
    }

    void ManagerInvader::drawInvaders(sf::RenderTarget &target) {
        for (auto &invader : m_invaders) {
            if (!invader.isAlive())
                continue;
            m_invaderRenderer.renderEntity(target, (int) invader.getType(),
                                           invader.getPosition());
        }
    }

    CollisionResult ManagerInvader::tryCollideWithProjectiles(
            std::vector<Projectile> &projectiles) {
        CollisionResult result;
        std::vector<sf::Vector2f> collisionPoints;
        for (auto &projectile : projectiles) {
            for (auto &invader : m_invaders) {
                if (!invader.isAlive() || !projectile.isActive())
                    continue;
                if (projectile.tryCollideWith(invader)) {
                    m_aliveInvaders--;
                    m_invaderKilledSound.play();
                    if (m_aliveInvaders == 0) {
                        m_hasAllInvadersBeenAdded = false;
                    }
                    result.second.emplace_back(invader.getPosition());
                    result.first += ((int) invader.getType() + 1) * 100;
                    updateStepDelay();
                }
            }
        }
        return result;
    }

    sf::Vector2f ManagerInvader::getRandomLowestInvaderPoint(Random<> &random) {
        if (m_aliveInvaders == 0)
            return {-1, -1};
        // Continuez à faire des boucles jusqu'à ce qu'un envahisseur soit trouvé.
        while (true) {
            auto invaderColumn = random.getIntInRange(0, 10);
            for (int y = 4; y >= 0; y--) {
                int index = y * 11 + invaderColumn;
                auto &invader = m_invaders.at(index);
                if (invader.isAlive()) {
                    return {// se transformer en dessous du centre de l'envahisseur
                            invader.getPosition().x + Invader::WIDTH / 2,
                            invader.getPosition().y + Invader::HEIGHT + 5};
                }
            }
        }
    }

    int ManagerInvader::getAliveInvadersCount() const { return m_aliveInvaders; }

// Ajoute des envahisseurs à la scène : 1 à la fois
    void ManagerInvader::initAddInvader() {
        static sf::Clock delay;
        if (delay.getElapsedTime().asSeconds() > 0.02) {
            m_invaders.at(m_initY * 11 + m_initX).makeAlive();
            m_aliveInvaders++;
            m_initX++;
            if (m_initX == 11) {
                m_initX = 0;
                m_initY--;
            }
            delay.restart();
        }

        if (m_aliveInvaders == MAX_INVADERS) {
            m_hasAllInvadersBeenAdded = true;
            m_initX = 0;
            m_initY = 4;
            updateStepDelay();
        }
    }

    bool ManagerInvader::areInvadersAlive() const {
        return m_hasAllInvadersBeenAdded;
    }

    void ManagerInvader::updateStepDelay() {
        m_stepGap = sf::seconds((float) m_aliveInvaders / 90.0f);
    }

    bool ManagerInvader::testInvaderPosition(const Invader &invader) const {
        if (invader.getPosition().y > Display::HEIGHT - 150) {
            m_world.setGameIsOver();
        }
        return (invader.getPosition().x < 15 &&
                m_isMovingLeft) || // Vérifier l'envahisseur à gauche
               (invader.getPosition().x + Invader::WIDTH > Display::WIDTH - 15 &&
                !m_isMovingLeft); // Vérifier l'envahisseur à droite
    }
}