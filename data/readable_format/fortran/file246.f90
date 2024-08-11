program test
  call test2()
  call test_unit()
contains
  subroutine test2()
    type t
      integer :: x
    end type t
  
    type t2
      class(t), allocatable :: a
    end type t2
  
    type(t2) :: one, two
  
    allocate(two%a)
    one = two
  end subroutine test2
  
  subroutine test_unit()
    type t
      integer :: x
    end type t

    type t2
      class(t), allocatable :: a
    end type t2

    type(t2) :: test_obj

    allocate(test_obj%a)
    test_obj%a%x = 5

    if (test_obj%a%x == 5) then
      print *, "Fortran Test Passed"
    else
      print *, "Fortran Test Failed"
    endif
  end subroutine test_unit
end program test