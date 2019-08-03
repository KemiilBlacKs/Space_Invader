//
// Created by Mouhammad DAHALANI on 2019-07-17.
//

#ifndef SPACE_INVADERS_NONMOVEABLE_HH
#define SPACE_INVADERS_NONMOVEABLE_HH
#pragma once

struct NonMovable {
    NonMovable() = default;

    NonMovable &operator=(NonCopyable &&) = delete;

    NonMovable(NonCopyable &&) = delete;
};

#endif //SPACE_INVADERS_NONMOVEABLE_HH