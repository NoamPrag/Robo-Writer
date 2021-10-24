#include <Vector.h>

struct Bezier
{
    const Vector start, startControl, endControl, end;

    Bezier(const Vector &start,
           const Vector &startControl,
           const Vector &endControl,
           const Vector &end)
        : start(start),
          startControl(startControl),
          endControl(endControl),
          end(end){};

    const Vector evaluate(const float &t)
    {
        const float oneMinusT = 1 - t;

        float oneMinusTFactor = powf(1 - t, 3);
        float tFactor = 1;

        Vector result = Vector::zero();

        static Vector points[4] = {start, end, startControl, endControl};

        for (int i = 0; i < 4; i++)
        {
            const float pointFactor = tFactor *
                                      oneMinusTFactor * (i == 1 || i == 2 ? 3 : 1);

            result += points[i] * pointFactor;

            oneMinusTFactor /= oneMinusT;
            tFactor *= t;
        }

        return result;
    }
};