//
// Created by Mouhammad DAHALANI on 2019-07-16.
//

#ifndef SPACE_INVADERS_NONCOPYABLE_HH
#define SPACE_INVADERS_NONCOPYABLE_HH
#pragma once

struct NonCopyable {
    NonCopyable() = default;
    NonCopyable &operator=(const NonCopyable &) = delete;
    NonCopyable(const NonCopyable &) = delete;
};
#endif //SPACE_INVADERS_NONCOPYABLE_HH
