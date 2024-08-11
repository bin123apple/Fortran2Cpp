module constants_m

  integer, parameter :: wp = 8
  real(wp), parameter :: zero = 0._wp
  real(wp), parameter :: one = 1._wp
  real(wp), parameter :: ten = 10._wp
  real(wp), parameter :: small = ten**(-5)
  real(wp), parameter :: large = one / small

  real(wp), parameter :: pi = 4._wp * atan(one)
  real(wp), parameter :: rad = pi / 180._wp

  integer, parameter :: nmax = 9
  integer, parameter :: nlen = 5000
  integer, parameter :: endpatch = 18
  integer, parameter :: nindex = 10
  integer, parameter :: res_u = 50
  integer, parameter :: res_v = 50
  integer, parameter :: res_box = 11
  integer, parameter :: big_int = 100000
  integer, parameter :: max_iter = 1000000
  real(wp), parameter :: eps_1 = 1.d-1
  real(wp), parameter :: eps_2 = 1.d-6
  integer, parameter :: nullkey = -1

end module constants_m

! Your main program or other functionalities here
program testConstants
    use constants_m
    implicit none
    
    ! Example of using constants
    print *, "pi =", pi
    print *, "small =", small
    print *, "nmax =", nmax

    ! Add your calculation or test functions here
    ! ...

end program testConstants