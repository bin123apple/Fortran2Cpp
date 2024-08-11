module typeA
    Type A
        integer :: X
        integer, allocatable :: y
        character(len=:), allocatable :: c
    end type A
end module

program test_allocatable_components
    use typeA
    implicit none
    Type(A) :: Me
    Type(A) :: Ea

    Me = A(X=1, Y=2, C="correctly allocated")

    call assert(Me%X == 1)
    call assert(allocated(Me%y) .and. Me%y == 2)
    call assert(allocated(Me%c))
    call assert(len(Me%c) == 19)
    call assert(Me%c == "correctly allocated")

    Ea%X = 9
    allocate(Ea%y)
    Ea%y = 42
    Ea%c = "13 characters"

    call assert(Ea%X == 9)
    call assert(allocated(Ea%y) .and. Ea%y == 42)
    call assert(allocated(Ea%c))
    call assert(len(Ea%c) == 13)
    call assert(Ea%c == "13 characters")

    deallocate(Ea%y)
    deallocate(Ea%c)
    call assert(.not. allocated(Ea%y))
    call assert(.not. allocated(Ea%c))

    print *, 'All tests passed successfully.'

contains
    subroutine assert(condition)
        logical, intent(in) :: condition
        if (.not. condition) then
            print *, 'Assertion failed'
            stop 1
        end if
    end subroutine assert
end program