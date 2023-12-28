#include "environment.h"

Projectile Environment::Tick(const Projectile &projectile) const
{
    return Projectile(
        projectile._position + projectile._velocity,
        projectile._velocity + _gravity + _wind);
}