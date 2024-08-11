program test_wrsoln
    implicit none

    ! Declaration of variables
    integer :: nnod, ntri, i
    double precision :: t
    double precision, allocatable :: y(:,:)
    integer :: stats(8)
    double precision :: hlast
    real :: cpusec

    ! Initialize variables for common blocks
    common /mfe010/ nnod, ntri
    common /mfe070/ hlast, cpusec, stats

    ! Specify values for the test
    nnod = 3
    ntri = 1
    hlast = 0.5
    cpusec = 1.2
    stats = (/1, 2, 3, 4, 5, 6, 7, 8/)

    ! Initialize t and y
    t = 2.0
    allocate(y(3, nnod))
    do i = 1, nnod
        y(:, i) = (/i, i+1, i+2/)
    end do

    ! Call the subroutine
    call wrsoln(t, y)

    ! Clean up
    deallocate(y)

end program test_wrsoln

subroutine wrsoln(t,y)
  integer nnod,ntri
  common /mfe010/ nnod,ntri

  integer stats(8)
  double precision hlast
  real cpusec
  common /mfe070/ hlast,cpusec,stats

  double precision t,y(3,*)
  integer j

  ! Assuming the output is directed to a file named output.txt. Adjust as necessary.
  open(unit=7, file='output.txt', status='unknown')

  write(7,*) t
  do j=1,nnod
    write(7,'(3F10.5)') y(2,j),y(3,j),y(1,j)
  end do
  write(7,'(F10.5, F10.5, 8I5)') hlast, cpusec, stats

  close(7)

end subroutine wrsoln