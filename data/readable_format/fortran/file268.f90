program test_ft
    implicit none
    double precision :: t_m

    ! Test 1: t_m > 0
    t_m = 2.0d0
    call check_t_m(t_m)

    ! Test 2: t_m = 0
    t_m = 0.0d0
    call check_t_m(t_m)

    ! Test 3: t_m < 0
    t_m = -1.0d0
    call check_t_m(t_m)
contains
    subroutine check_t_m(t_m)
        double precision, intent(inout) :: t_m
        if (t_m <= 0.0d0) t_m = 1.0d0
        print *, "t_m:", t_m
    end subroutine check_t_m
end program test_ft