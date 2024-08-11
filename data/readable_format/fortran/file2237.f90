program test_bug
  implicit none

  call run_bug_test

contains

  subroutine run_bug_test
    type :: block
      real, allocatable :: fields
    end type

    type :: list
      class(block),allocatable :: B
    end type

    type :: domain
      type(list),dimension(2) :: L
    end type

    type(domain) :: d
    type(block) :: b1

    allocate(b1%fields,source=5.)
    allocate(d%L(2)%B,source=b1)

    if (d%L(2)%B%fields /= 5.) then
      print *, "Test Failed: Expected 5.0 but got ", d%L(2)%B%fields
      stop 1
    else
      print *, "Test Passed"
    end if

  end subroutine run_bug_test

end program test_bug