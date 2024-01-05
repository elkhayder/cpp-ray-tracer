#include <iostream>

#include "physics/projectile.h"
#include "physics/environment.h"

#include "graphics/canvas.h"
#include "math/matrix.h"

int main()
{
    Canvas canvas(100, 100);

    Tuple point = Tuple::Point(0, 0, 1);

    for (int i = 0; i < 12; i++)
    {
        Tuple r = Matrix::Translation(50, 0, 50) * Matrix::Scaling(30, 0, 30) * Matrix::RotationY(i * 0.523598776) * point; // 0.523598776 ~ pi/6

        std::cout << r << std::endl;

        canvas.WritePixel(r.X(), r.Z(), Color(255, 255, 255));
    }

    canvas.Save("output.ppm");

    return 0;
}