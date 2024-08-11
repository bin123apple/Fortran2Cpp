program testMapev
  implicit none
  integer, parameter :: nold = 2, nnew = 3, nvar = 2
  integer, dimension(3) :: map = (/1, 2, 3/)
  real, dimension(6) :: vars = (/1.0, 2.0, 3.0, 4.0, 5.0, 6.0/)
  real, dimension(3) :: scr
  integer :: i

  call mapev(nold, nnew, nvar, map, vars, scr)

  print *, 'Vars:'
  do i = 1, 6
    print *, 'vars(', i, ') = ', vars(i)
  end do
end program testMapev

subroutine mapev(nold, nnew, nvar, map, vars, scr)
  integer, intent(in) :: nold, nnew, nvar, map(*)
  real, intent(inout) :: vars(*)
  real, intent(out) :: scr(*)
  integer :: ivar, i

  do ivar = 1, nvar
    do i = 1, nnew
      scr(i) = vars(map(i) + nold * (ivar-1))
    end do

    do i = 1, nnew
      vars(i + nnew * (ivar-1)) = scr(i)
    end do
  end do
end subroutine mapev