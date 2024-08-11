! bisect2.f90
module h_struct
    implicit none
    type :: model_struct
        ! Example structure
    end type model_struct
end module h_struct

module h_params
    implicit none
    real, parameter :: X_TOL = 1e-5
end module h_params

module bisect_module
    use h_struct
    use h_params
    implicit none
contains
    function bisect2(func, current_model, extra_params, x1, x2) result(root)
        interface
            function func(current_model, x, extra_params)
                use h_struct
                type(model_struct), intent(in) :: current_model
                real, dimension(:), intent(in) :: extra_params
                real, intent(in) :: x
                real :: func
            end function func
        end interface
        type(model_struct), intent(in) :: current_model
        real, dimension(:), intent(in) :: extra_params
        real, intent(in) :: x1, x2
        real :: root

        integer, parameter :: MAXIT = 40
        integer :: j
        real :: dx, f, fmid, xmid

        fmid = func(current_model, x2, extra_params)
        f = func(current_model, x1, extra_params)

        if (f * fmid >= 0.0) then
            print *, 'Root must be bracketed for bisection method.'
            stop
        end if

        if (f < 0.0) then
            root = x1
            dx = x2 - x1
        else
            root = x2
            dx = x1 - x2
        end if

        do j = 1, MAXIT
            dx = dx * 0.5
            xmid = root + dx
            fmid = func(current_model, xmid, extra_params)
            if (fmid <= 0.0) then
                root = xmid
            end if
            if (abs(dx) < X_TOL .or. fmid == 0.0) exit
        end do
    end function bisect2
end module bisect_module

program test_bisect
    use h_struct
    use bisect_module
    implicit none
    type(model_struct) :: model
    real, dimension(1) :: extra_params = [2.0]  ! Known root for test function
    real :: root

    root = bisect2(test_func, model, extra_params, 1.0, 3.0)
    print *, "Found root: ", root

contains
    function test_func(current_model, x, extra_params) result(fx)
        use h_struct
        type(model_struct), intent(in) :: current_model
        real, dimension(:), intent(in) :: extra_params
        real, intent(in) :: x
        real :: fx

        fx = x - extra_params(1)  ! Simple linear function: f(x) = x - root
    end function test_func
end program test_bisect