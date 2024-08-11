program main
    implicit none
    double precision :: result, error
    double precision, parameter :: a = 0.0d0, b = 1.0d0, epsabs = 0.0d-10, epsrel = 0.0d-10
    
    interface
        double precision function f(x)
            double precision, intent(in) :: x
        end function f
    end interface
    
    call qag(f, a, b, epsabs, epsrel, result, error)
    print *, 'Integration result: ', result
    print *, 'Estimated error: ', error

contains

    subroutine qag(f, a, b, epsabs, epsrel, result, error)
        implicit none
        interface
            double precision function f(x)
                double precision, intent(in) :: x
            end function f
        end interface
        double precision, intent(in) :: a, b, epsabs, epsrel
        double precision, intent(out) :: result, error
        double precision :: h, fa, fb, m, fm, i1, i2

        h = b - a
        fa = f(a)
        fb = f(b)
        m = (a + b) / 2.0d0
        fm = f(m)
        
        i1 = h * (fa + 4.0d0*fm + fb) / 6.0d0
        i2 = h * (fa + fb) / 2.0d0
        
        result = i1
        error = abs(i1 - i2)
        
        ! This is a very simplified integration method for demonstration.
        ! Real QUADPACK routines like qag use adaptive techniques.
    end subroutine qag

end program main

! Place the function outside the main program after the "end program" statement.
double precision function f(x)
    double precision, intent(in) :: x
    f = x**2  ! Example function: f(x) = x^2
end function f