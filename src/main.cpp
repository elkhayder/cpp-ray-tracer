#include <thread>
#include <iostream>

#include "physics/ray.h"
#include "physics/objects/sphere.h"

#include "io/canvas.h"
#include "math/matrix.h"

typedef struct
{
    int x, x_size;
    int y, y_size;
} ImageChunk;

void SimulateChunk(const ImageChunk &chunk,
                   Canvas *canvas,
                   const Sphere &sphere,
                   const Tuple &rayDirection,
                   const Tuple &eye,
                   const Light &light)
{
    for (int x = chunk.x; x < chunk.x + chunk.x_size; x++)
        for (int y = chunk.y; y < chunk.y + chunk.y_size; y++)
        {
            Ray ray(Tuple::Point(x, y, -100), rayDirection);
            Intersections xs(sphere);

            xs.Join(ray.Intersect(sphere));

            if (xs.Hit() != std::numeric_limits<float>::max())
            {
                Tuple point = ray.Position(xs.Hit());

                Tuple normal = sphere.NormalAt(point);

                Color color = sphere.material.Lighting(light, point, eye, normal);

                canvas->WritePixel(x + canvas->Width() / 2,
                                   y + canvas->Height() / 2,
                                   color);
            }
        }
}

int main()
{
    Canvas canvas(5000, 5000);

    Sphere sphere;
    sphere.material.color = Color(1, 0.2, 1);
    sphere.SetTransformation(Matrix::Scaling(canvas.Width() * 0.4, canvas.Width() * 0.4, 1));

    Tuple RayDirection = Tuple::Vector(0, 0, 1).Normalize();
    Tuple eye = -RayDirection;

    Light light(Tuple::Point(-canvas.Width() * 0.2,
                             canvas.Width() * 0.2,
                             -canvas.Width() * 0.15),
                Color(1, 1, 1));

    int nThreads = std::thread::hardware_concurrency() * 4;
    std::cout << "Running " << nThreads << " threads" << std::endl;

    std::vector<std::thread> threads;

    int x_size = canvas.Width() / nThreads;
    int x_rem = canvas.Width() % nThreads;

    int y_size = canvas.Height() / nThreads;
    int y_rem = canvas.Height() % nThreads;

    for (int i = 0; i < nThreads; i++)
    {
        ImageChunk chunk = {
            .x = i * x_size - canvas.Width() / 2,
            .x_size = (i == nThreads - 1) ? x_size + 1 : x_size,
            .y = i * y_size - canvas.Height() / 2,
            .y_size = (i == nThreads - 1) ? y_size + 1 : y_size,
        };

        threads.push_back(std::thread(SimulateChunk, chunk, &canvas, sphere, RayDirection, eye, light));
    }

    for (auto &t : threads)
    {
        if (t.joinable())
            t.join();
        std::cout << "Chunk finished" << std::endl;
    }

    std::cout << "Writing to image file" << std::endl;

    canvas.Save("output.ppm");

    return 0;
}