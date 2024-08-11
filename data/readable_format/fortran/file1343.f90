module base_mod
  
  implicit none
  private

  type, public :: base_mat
    integer :: m = 0
    integer :: n = 0
  contains 
    procedure, pass :: transp1 => base_transp1
    generic, public :: transp => transp1
    procedure, pass :: transc1 => base_transc1
    generic, public :: transc => transc1
  end type base_mat

contains

  subroutine base_transp1(a)
    class(base_mat), intent(inout) :: a
    integer :: itmp
    itmp = a%m
    a%m = a%n
    a%n = itmp
  end subroutine base_transp1

  subroutine base_transc1(a)
    class(base_mat), intent(inout) :: a
    call a%transp() 
  end subroutine base_transc1

end module base_mod

program test_base_mod
  use base_mod
  implicit none

  type(base_mat) :: mat
  integer :: m, n

  ! Initialize dimensions
  mat%m = 3
  mat%n = 2

  ! Test for transp method
  call mat%transp()
  if (mat%m == 2 .and. mat%n == 3) then
      print *, "transp test passed."
  else
      print *, "transp test failed."
  end if

  ! Reset dimensions for next test
  mat%m = 3
  mat%n = 2

  ! Test for transc method
  call mat%transc()
  if (mat%m == 2 .and. mat%n == 3) then
      print *, "transc test passed."
  else
      print *, "transc test failed."
  end if

end program test_base_mod