program test_area
    implicit none
    real(kind=8) :: r, a
    real(kind=8), parameter :: pi = 3.14159265358979323846

    ! Test subroutine
    call test_area_subroutine()

contains

    subroutine area(r, a)
        real(kind=8), intent(in) :: r
        real(kind=8), intent(out) :: a

        a = pi * r**2
    end subroutine area

    subroutine test_area_subroutine()
        ! Test 1: Radius = 0.0
        r = 0.0
        call area(r, a)
        print *, "Test 1 (r=0.0): ", a, " Expected: ", 0.0

        ! Test 2: Radius = 1.0 (Area should be Pi)
        r = 1.0
        call area(r, a)
        print *, "Test 2 (r=1.0): ", a, " Expected: ", pi

        ! Test 3: Radius = 10.0
        r = 10.0
        call area(r, a)
        print *, "Test 3 (r=10.0): ", a, " Expected: ", pi * 100.0

        ! Test 4: Small radius
        r = 0.001
        call area(r, a)
        print *, "Test 4 (r=0.001): ", a, " Expected: ", pi * 0.001**2
    end subroutine test_area_subroutine

end program test_area