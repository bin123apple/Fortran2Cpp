module mod
    implicit none

    type :: t
    end type t

contains

    subroutine s1(x)
        type(t), intent(in) :: x
        print *, "s1 called"
    end subroutine s1

    subroutine s2(x)
        class(*), intent(in) :: x
        print *, "s2 called with integer"
    end subroutine s2

end module mod

program test_mod
    use mod
    implicit none

    type(t) :: xt
    integer :: yi = 5

    call s1(xt)
    ! For s2, Fortran does not directly support passing integers to class(*), this was a simplification for the example.
    call s2(yi)

    print *, "Tests completed successfully."
end program test_mod