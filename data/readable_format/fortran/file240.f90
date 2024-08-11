module m1
  integer :: i = 0
contains
  function ma_create_fun() result(this)
    integer :: this
    i = 1
    this = 2
  end function ma_create_fun

  function ma_create_new_fun() result(this)
    integer :: this
    i = 2
    this = 1
    print *, "Hello from ma_create_new_fun"
  end function ma_create_new_fun
end module m1

module m2
  integer :: i = 0
contains
  subroutine mb_create_sub()
    i = 1
    print *, "mb_create_sub called with i =", i
  end subroutine mb_create_sub

  subroutine mb_create_new_sub()
    i = 2
    print *, "mb_create_new_sub called with i =", i
  end subroutine mb_create_new_sub
end module m2

! Test program
program testFortran
  use m1
  use m2
  implicit none

  integer :: result

  result = ma_create_fun()
  print *, "Result of ma_create_fun:", result
  result = ma_create_new_fun()
  print *, "Result of ma_create_new_fun:", result

  call mb_create_sub()
  call mb_create_new_sub()
end program testFortran