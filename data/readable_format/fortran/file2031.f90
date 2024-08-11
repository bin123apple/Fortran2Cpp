module pole_utils
  implicit none
  integer, parameter :: npole = 1, maxAtoms = 3
  character(len=8) :: polaxe(npole) = 'Z-then-X'
  integer :: yaxis(npole) = 1
  integer :: ipole(npole) = 1, zaxis(npole) = 2, xaxis(npole) = 3
  double precision :: x(maxAtoms) = [0.0, 1.0, -1.0], y(maxAtoms) = [0.0, 0.0, 0.0], z(maxAtoms) = [0.0, 0.0, 0.0]
contains
  subroutine chkpole
    integer :: i, k
    integer :: ia, ib, ic, id
    double precision :: xad, yad, zad
    double precision :: xbd, ybd, zbd
    double precision :: xcd, ycd, zcd
    double precision :: c1, c2, c3, vol
    logical :: check

    do i = 1, npole
       check = .true.
       if (polaxe(i) /= 'Z-then-X') check = .false.
       if (yaxis(i) == 0) check = .false.
       if (check) then
          k = yaxis(i)
          ia = ipole(i)
          ib = zaxis(i)
          ic = xaxis(i)
          id = abs(k)

          xad = x(ia) - x(id)
          yad = y(ia) - y(id)
          zad = z(ia) - z(id)
          xbd = x(ib) - x(id)
          ybd = y(ib) - y(id)
          zbd = z(ib) - z(id)
          xcd = x(ic) - x(id)
          ycd = y(ic) - y(id)
          zcd = z(ic) - z(id)
          c1 = ybd*zcd - zbd*ycd
          c2 = zbd*xcd - xbd*zcd
          c3 = xbd*ycd - ybd*xcd
          vol = xad*c1 + yad*c2 + zad*c3

          if ((k < 0 .and. vol > 0.0d0) .or. (k > 0 .and. vol < 0.0d0)) then
             yaxis(i) = -k
          end if
       end if
    end do
  end subroutine chkpole
end module pole_utils

program testChkPole
  use pole_utils
  implicit none

  call chkpole

  ! Test the result
  if (yaxis(1) == -1) then
    print *, 'Fortran Test passed.'
  else
    print *, 'Fortran Test failed.'
  end if
end program testChkPole