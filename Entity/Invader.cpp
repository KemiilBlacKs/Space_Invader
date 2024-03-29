/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  Invader.cpp                                                #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/22/19 10:18:54 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 07/22/19 10:27:04 by Dahalani Mouhamad            #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include "Invader.hh"

namespace SpaceInvaders {
    Invader::Invader(const sf::Vector2f &initialLocation, Type type)
            : Collidable(WIDTH, HEIGHT), m_location(initialLocation), m_type(type),
              m_initialPosition(initialLocation) {}

    void Invader::move(float x, float y) { m_location += {x, y}; }

    const sf::Vector2f &Invader::getPosition() const { return m_location; }

    bool Invader::isAlive() const { return m_isAlive; }

    Invader::Type Invader::getType() const { return m_type; }

    void Invader::onCollide(Collidable &other) { m_isAlive = false; }
}