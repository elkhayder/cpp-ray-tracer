#include "environment.h"

Projectile Environment::Tick(const Projectile &projectile) const
{
    return Projectile(
        projectile.Position() + projectile.Velocity(),
        projectile.Position() + _gravity + _wind);
}