/**
 *
 * @file    IntegrTrapezes.cpp
 *
 * @authors D. Mathieu
 *
 * @date    06/11/2007
 *
 * @version V1.0
 *
 * @brief   Integration par la methodes des trapezes au moyen de
 *             pointeurs de fonctions

 *
 **/
#include <iostream>
#include <cmath>      // cos(), sin()

#define M_PI_2 3.14159265358979323846 // pi

using namespace std;

namespace
{
   template <typename T, typename TRes>
   class IUnaryFunction
   {
     public :
       virtual ~IUnaryFunction (void) {}
       virtual TRes operator () (const T &) const noexcept = 0;

   }; // IUnaryFunction

    double integrTrapezes (const IUnaryFunction<double, double>& f, double a, double b, unsigned n)
    {
        double s     = (f (a) + f (b)) / 2.0;
        double delta = (b - a) / double (n);

        for ( ; --n; ) s += f (a += delta);

        return s * delta;

    } // integrTrapezes

    class FctorSin : public IUnaryFunction<double, double>
    {
    public :
      virtual ~FctorSin (void) {}
      virtual double operator () (const double & val) const noexcept
        {
            return sin(val);
        }
    };

    class FctorCos : public IUnaryFunction<double, double>
    {
    public :
      virtual ~FctorCos (void) {}
      virtual double operator () (const double & val) const noexcept
        {
            return cos(val);
        }
    };

    void testIntegrTrapezes (void)
    {
        cout << "IntegrTrapezes : \n\n";

        cout << "Methode des trapezes : \n";

        cout << "S (cos (x)) entre 0 et +Pi/2  avec   5 intervalles = "
             << integrTrapezes (FctorCos(), 0, M_PI_2,   5) << '\n';

        cout << "S (cos (x)) entre 0 et +Pi/2  avec  10 intervalles = "
             << integrTrapezes (FctorCos(), 0, M_PI_2,  10) << '\n';

        cout << "S (cos (x)) entre 0 et +Pi/2  avec  50 intervalles = "
             << integrTrapezes (FctorCos(), 0, M_PI_2,  50) << '\n';

        cout << "S (cos (x)) entre 0 et +Pi/2  avec 100 intervalles = "
             << integrTrapezes (FctorCos(), 0, M_PI_2, 100) << '\n';

        cout << '\n';

        cout << "S (sin (x)) entre -Pi/2 et 0  avec   5 intervalles = "
             << integrTrapezes (FctorSin(), -M_PI_2, 0,   5) << '\n';

        cout << "S (sin (x)) entre -Pi/2 et 0  avec  10 intervalles = "
             << integrTrapezes (FctorSin(), -M_PI_2, 0,  10) << '\n';

        cout << "S (sin (x)) entre -Pi/2 et 0  avec  50 intervalles = "
             << integrTrapezes (FctorSin(), -M_PI_2, 0,  50) << '\n';

        cout << "S (sin (x)) entre -Pi/2 et 0  avec 100 intervalles = "
             << integrTrapezes (FctorSin(), -M_PI_2, 0, 100) << '\n';

    } // TestIntegrTrapezes()

} // namespace anonyme

int main (void)
{
    testIntegrTrapezes ();

    return 0;

} // main()
