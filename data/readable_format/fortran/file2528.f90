program test_program
  implicit none
  call bar()
contains
  subroutine foo()
    integer :: a(3)
    a = 1
    print *, matmul(1*reshape(a,(/3,1/)), reshape((/1,1,1/),(/1,3/)))
  end subroutine foo

  subroutine bar()
    call foo()
  end subroutine bar
end program test_program