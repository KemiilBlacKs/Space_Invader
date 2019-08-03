/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  Explosion.cpp                                              #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/19/19 11:51:20 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 07/19/19 11:52:32 by Dahalani Mouhamad            #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include "Explosion.hh"

namespace SpaceInvaders {
    Explosion::Explosion(const sf::Vector2f &position) : m_position(position) {}

    bool Explosion::isLifeOver() const {
        return m_lifetimeCounter.getElapsedTime().asSeconds() >= 0.2f;
    }

    const sf::Vector2f &Explosion::getPosition() const { return m_position; }
}