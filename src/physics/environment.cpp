#include "environment.h"

Projectile Environment::Tick(const Projectile &projectile) const
{
    return Projectile(
        projectile.Position() + projectile.Velocity(),
        projectile.Velocity() + _gravity + _wind);
}