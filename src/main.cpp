#include <iostream>

#include "physics/ray.h"
#include "physics/objects/sphere.h"

#include "graphics/canvas.h"
#include "math/matrix.h"

int main()
{
    Canvas canvas(500, 500);

    Sphere sphere;
    sphere.SetTransformation(Matrix::Scaling(200, 200, 1));

    for (int x = -canvas.Width() / 2; x < canvas.Width() / 2; x++)
    {
        for (int y = -canvas.Height() / 2; y < canvas.Height() / 2; y++)
        {
            Ray ray(Tuple::Point(x, y, -10), Tuple::Vector(0, 0, 100));

            Intersections xs(sphere);

            xs.Join(ray.Intersect(sphere));

            if (xs.Hit() != std::numeric_limits<float>::max())
            {
                canvas.WritePixel(x + canvas.Width() / 2,
                                  y + canvas.Height() / 2,
                                  Color(0xFF, 0, 0));
            }
        }
    }

    canvas.Save("output.ppm");

    return 0;
}