module bad
   implicit none
   type default_initialization
      integer :: x = 42
   end type default_initialization
   type (default_initialization) t
end module bad

program test_bad
    use bad
    implicit none

    ! Test for default initialization
    if (t%x == 42) then
        print *, "Test passed: t%x is correctly initialized to 42."
    else
        print *, "Test failed: t%x is not initialized to 42."
    end if
end program test_bad