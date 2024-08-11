program testSwitches
  implicit none

  real*4 rf1, rf2
  real*8 rd1, rd2
  integer i1, i2

  ! Initialize variables for test
  rf1 = 1.2
  rf2 = 3.4
  rd1 = 1.234
  rd2 = 5.678
  i1 = 1
  i2 = 2

  ! Test rswitch
  call rswitch(rf1, rf2)
  print *, 'After rswitch: ', rf1, rf2

  ! Test dswitch
  call dswitch(rd1, rd2)
  print *, 'After dswitch: ', rd1, rd2

  ! Test iswitch
  call iswitch(i1, i2)
  print *, 'After iswitch: ', i1, i2

contains

  subroutine rswitch (x, y)
    real*4 x, y, z
    z = x
    x = y
    y = z
  end subroutine rswitch

  subroutine dswitch (x, y)
    real*8 x, y, z
    z = x
    x = y
    y = z
  end subroutine dswitch

  subroutine iswitch (i, j)
    integer i, j, k
    k = j
    j = i
    i = k
  end subroutine iswitch

end program testSwitches