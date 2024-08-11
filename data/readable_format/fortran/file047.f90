! Define the module and the main program in the same file
module xparams
  implicit none
  integer, parameter :: exprbeg = 100, exprend = 154
  character(len=8), dimension(exprbeg:exprend), parameter :: &
       exprs = (/ 'nint()  ', 'log10() ', 'sqrt()  ', 'acos()  ', 'asin()  ', &
                  'atan()  ', 'cosh()  ', 'sinh()  ', 'tanh()  ', 'int()   ', &
                  'cos()   ', 'sin()   ', 'tan()   ', 'exp()   ', 'log()   ', &
                  'abs()   ', 'delta() ', 'step()  ', 'rect()  ', 'max(,)  ', &
                  'min(,)  ', 'bj0()   ', 'bj1()   ', 'bjn(,)  ', 'by0()   ', &
                  'by1()   ', 'byn(,)  ', 'logb(,) ', 'erf()   ', 'erfc()  ', &
                  'lgamma()', 'gamma() ', 'csch()  ', 'sech()  ', 'coth()  ', &
                  'lif(,,) ', 'gaus()  ', 'sinc()  ', 'atan2(,)', 'mod(,)  ', &
                  'nthrt(,)', 'ramp()  ', 'fbi()   ', 'fbiq()  ', 'uran(,) ', &
                  'aif(,,) ', 'sgn()   ', 'cbrt()  ', 'fact()  ', 'somb()  ', &
                  'bk0()   ', 'bk1()   ', 'bkn(,)  ', 'bbi(,,) ', 'bbiq(,,)' /)
  logical :: tmp(55,26)
  character(len=26) :: al = 'abcdefghijklmnopqrstuvwxyz'
end module

program pack_bug
  use xparams
  implicit none
  integer :: i, j
  logical :: any_mismatch

  ! Initialize tmp array based on the comparison with 'a'
  do i = 1, 26
    do j = 1, 55
      tmp(j, i) = (exprs(j)(1:1) == al(i:i))
    end do
  end do

  ! Example test: Check if any expressions start with 'a'
  any_mismatch = .false.
  do j = 1, 55
    if (exprs(j)(1:1) == 'a' .and. .not. tmp(j, 1)) then
      any_mismatch = .true.
    end if
  end do

  if (any_mismatch) then
    print *, "Mismatch found."
  else
    print *, "No mismatches found."
  end if

end program pack_bug