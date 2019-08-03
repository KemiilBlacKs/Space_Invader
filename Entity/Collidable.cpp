/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  Collidable.cpp                                             #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/19/19 11:58:22 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 07/19/19 12:00:35 by Dahalani Mouhamad            #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/
#include "Collidable.hh"

namespace SpaceInvaders {
    Collidable::Collidable(float width, float height) : m_size(width, height) {}

    bool Collidable::tryCollideWith(Collidable &other) {
        if (getBox().intersects(other.getBox())) {
            onCollide(other);
            other.onCollide(*this);
            return true;
        }
        return false;
    }

    sf::FloatRect Collidable::getBox() const {
        return {getPosition().x, getPosition().y, m_size.x, m_size.y};
    }
}