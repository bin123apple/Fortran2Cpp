program test_translation
    implicit none

    type t0
        integer :: j = 42
    end type t0

    type t
        integer :: i
        class(t0), allocatable :: foo
    end type t

    type(t) :: m

    ! Define the test scenario
    allocate(t0 :: m%foo)
    m%i = 5

    select type(bar => m%foo)
    type is(t0)
        print *, "Fortran test: bar%j =", bar%j
        call assert(bar%j == 42)
    end select

    contains

        subroutine assert(condition)
            logical, intent(in) :: condition

            if (.not. condition) then
                print *, "Assertion failed"
                stop
            end if
        end subroutine assert

end program test_translation