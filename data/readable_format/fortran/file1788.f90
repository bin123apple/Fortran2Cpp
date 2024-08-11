! test.f90
module mod_test
  implicit none
  type :: t
    integer :: i
  end type t

  type, extends(t) :: t2
    integer :: j
  end type t2
contains
  subroutine run_test()
    class(t), allocatable :: a
    allocate(a, source=t2(1,2))

    ! Test for correct initialization and inheritance behavior
    if (a%i == 1) then
      print *, "Test i=1 passed"
    else
      print *, "Test i=1 failed"
      stop 1
    endif

    select type (a => a)
      type is (t2)
        if (a%j == 2) then
          print *, "Test j=2 passed"
        else
          print *, "Test j=2 failed"
          stop 2
        endif
    end select
  end subroutine run_test
end module mod_test

program test
  use mod_test
  call run_test()
end program test