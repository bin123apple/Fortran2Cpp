module mymod
  implicit none
  interface tt
    module procedure tt_i, tt_r, tt_l, tt_c4, tt_c8
  end interface tt
contains
  function tt_l(x) result(y)
    integer :: y
    logical, pointer :: x
    y = 0
  end function tt_l

  function tt_i(x) result(y)
    integer :: y
    integer, pointer :: x
    y = 1
  end function tt_i

  function tt_r(x) result(y)
    integer :: y
    real, pointer :: x
    y = 2
  end function tt_r

  function tt_c4(x) result(y)
    integer :: y
    complex(kind=4), pointer :: x
    y = 3
  end function tt_c4

  function tt_c8(x) result(y)
    integer :: y
    complex(kind=8), pointer :: x
    y = 4
  end function tt_c8
end module mymod

program test
  use mymod
  implicit none

  logical, pointer :: l
  integer, pointer :: i
  real, pointer :: r
  complex(kind=4), pointer :: c4
  complex(kind=8), pointer :: c8
  
  nullify(l)
  nullify(i)
  nullify(r)
  nullify(c4)
  nullify(c8)

  if (tt(l) /= 0) stop "Test l Failed"
  if (tt(i) /= 1) stop "Test i Failed"
  if (tt(r) /= 2) stop "Test r Failed"
  if (tt(c4) /= 3) stop "Test c4 Failed"
  if (tt(c8) /= 4) stop "Test c8 Failed"
  if (tt(null(l)) /= 0) stop "Test null l Failed"
  if (tt(null(i)) /= 1) stop "Test null i Failed"
  if (tt(null(r)) /= 2) stop "Test null r Failed"
  if (tt(null(c4)) /= 3) stop "Test null c4 Failed"
  if (tt(null(c8)) /= 4) stop "Test null c8 Failed"

  print *, "All tests passed."
end program test