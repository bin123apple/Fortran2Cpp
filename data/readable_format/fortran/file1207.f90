program test_x_dot
    implicit none
    real :: kon_1, koff_1, kon_2, koff_2
    real :: f_plus, g_minus, g_plus, Ca
    real, dimension(4) :: x, f

    ! Initialize test variables
    kon_1 = 1.0
    koff_1 = 2.0
    kon_2 = 1.5
    koff_2 = 2.5
    f_plus = 0.5
    g_minus = 0.2
    g_plus = 0.3
    Ca = 1.0
    x = [0.1, 0.2, 0.3, 0.4]

    ! Call the x_dot function
    f = x_dot(kon_1, koff_1, kon_2, koff_2, f_plus, g_minus, g_plus, Ca, x)

    ! Output the results for verification
    print *, 'Results: ', f

contains

    function x_dot(kon_1, koff_1, kon_2, koff_2, f_plus, g_minus, g_plus, Ca, x) result(f)
        real, intent(in) :: kon_1, koff_1, kon_2, koff_2, f_plus, g_minus, g_plus, Ca
        real, dimension(4), intent(in) :: x
        real, dimension(4) :: f

        f(1) = -kon_1 * Ca * x(1) + koff_1 * x(2) + g_minus * x(4)
        f(2) =  kon_1 * Ca * x(1) - (koff_1 + f_plus) * x(2) + g_plus * x(3)
        f(3) =  f_plus * x(2) - (g_plus + koff_2) * x(3) + kon_2 * Ca * x(4)
        f(4) =  koff_2 * x(3) - (g_minus + kon_2 * Ca) * x(4)
    end function x_dot

end program test_x_dot