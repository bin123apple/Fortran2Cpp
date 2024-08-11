program testWritematrix
  implicit none
  integer, parameter :: neq = 3
  integer :: irow(neq) = [1, 2, 3]
  integer :: jq(neq+1) = [1, 2, 3, 4]
  real*8 :: au(neq) = [0.5, 0.3, 0.6]
  real*8 :: ad(neq) = [0.1, 0.2, 0.3]
  integer :: number = 1

  call writematrix(au, ad, irow, jq, neq, number)

contains

  subroutine writematrix(au, ad, irow, jq, neq, number)
    implicit none
    character(len=12) :: name
    character(len=14) :: name2
    integer, intent(in) :: irow(*), jq(*), neq, number
    real(kind=8), intent(in) :: au(*), ad(*)
    integer :: i, j, k
    real(kind=8) :: diff, maxdiff

    name = 'matrix_' // char(ichar('a') + number - 1) // '.out'
    name2 = 'matrix_' // char(ichar('a') + number - 1) // '_t.out'

    open(unit=10, file=name, status='unknown')
    write(10, *) 'matrix number ', number
    do i = 1, neq
      if (ad(i) > 1.e-20 .or. ad(i) < -1.e-20) then
        write(10, *) 'row ', i, ' value ', ad(i)
      endif
    enddo

    maxdiff = 0.0
    do i = 1, neq
      k = jq(i+1) - jq(i)
      if (k > 0) then
        write(10, *) 'column ', i
      endif
      do j = jq(i), jq(i+1)-1
        write(10, 100) i, irow(j), au(j)
      enddo
    enddo
    write(10, *) 'maxdiff_impuls', maxdiff
    close(10)

  100 format('column ', i10, 1x, 'row ', i10, 1x, 'value ', e15.8)
  end subroutine writematrix

end program testWritematrix