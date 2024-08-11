program test
    implicit none

    ! Test variables
    integer :: n
    character(len=10) :: a

    ! Test subroutine call
    n = 5
    call foo(a, n)

contains

    subroutine foo(a, n)
        integer, intent(in) :: n
        character(len=*), intent(out) :: a
        integer :: len_id

        len_id = id(n)
        print *, 'Array length as per id:', len_id

        ! Just for demonstration since the subroutine doesn't modify 'a'
        a = 'test'
        print *, 'Subroutine foo called with n =', n
    end subroutine foo

    ! Moved id function outside of foo for compatibility
    integer function id(a)
        integer, intent(in) :: a
        print *, 'ID function called with:', a
        id = a
    end function id

end program test