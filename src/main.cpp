#include "physics/ray.h"
#include "physics/objects/sphere.h"

#include "io/canvas.h"
#include "math/matrix.h"

int main()
{
    Canvas canvas(5000, 5000);

    Sphere sphere;
    sphere.material.color = Color(1, 0.2, 1);
    sphere.SetTransformation(Matrix::Scaling(canvas.Width() * 0.4, canvas.Width() * 0.4, 1));

    Tuple RayDirection = Tuple::Vector(0, 0, 1).Normalize();
    Tuple eye = -RayDirection;

    Light light(Tuple::Point(-canvas.Width() * 0.2, canvas.Width() * 0.2, -canvas.Width() * 0.15), Color(1, 1, 1));

    for (int x = -canvas.Width() / 2; x < canvas.Width() / 2; x++)
        for (int y = -canvas.Height() / 2; y < canvas.Height() / 2; y++)
        {
            Ray ray(Tuple::Point(x, y, -100), RayDirection);
            Intersections xs(sphere);

            xs.Join(ray.Intersect(sphere));

            if (xs.Hit() != std::numeric_limits<float>::max())
            {
                Tuple point = ray.Position(xs.Hit());

                Tuple normal = sphere.NormalAt(point);

                Color color = sphere.material.Lighting(light, point, eye, normal);

                canvas.WritePixel(x + canvas.Width() / 2,
                                  y + canvas.Height() / 2,
                                  color);
            }
        }

    canvas.Save("output.ppm");

    return 0;
}