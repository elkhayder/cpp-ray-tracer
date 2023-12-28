#include <iostream>

#include "physics/projectile.h"
#include "physics/environment.h"

#include "graphics/canvas.h"

int main()
{
    Tuple start = Tuple::Point(0, 1, 0);
    Tuple velocity = Tuple::Vector(1, 1.8, 0).Normalize() * 11.25;
    Projectile projectile(start, velocity);

    Tuple gravity = Tuple::Vector(0, -0.1, 0);
    Tuple wind = Tuple::Vector(-0.01, 0, 0);
    Environment environment(gravity, wind);

    Canvas canvas(900, 550);

    do
    {
        canvas.WritePixel(projectile.Position().X(), projectile.Position().Y(), Color(1, 0, 0));
        projectile = environment.Tick(projectile);
    } while (projectile.Position().Y() > 0);

    canvas.Save("output.ppm");

    return 0;
}