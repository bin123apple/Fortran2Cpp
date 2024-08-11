program test_descramble
  implicit none
  integer, parameter :: na = 4
  integer, parameter :: nshells = 2
  integer :: nfps(nshells) = (/2, 2/)
  integer :: ixshells(nshells) = (/1, 2/)
  double precision :: mat(na, na) = reshape((/ &
       1.0d0, 5.0d0, 9.0d0, 13.0d0, &
       2.0d0, 6.0d0, 10.0d0, 14.0d0, &
       3.0d0, 7.0d0, 11.0d0, 15.0d0, &
       4.0d0, 8.0d0, 12.0d0, 16.0d0 /), (/na, na/))
  integer :: i, j

  call descramble_matrix(mat, na, nfps, ixshells, nshells)

  do i = 1, na
     write(*, '(4F6.2)') (mat(i, j), j = 1, na)
  end do

contains

  subroutine descramble_matrix(mat, na, nfps, ixshells, nshells)
    implicit none
    integer na, nshells
    integer nfps(nshells)
    integer ixshells(nshells)
    double precision mat(na,na)
    double precision xa(na)
    integer ixa(na)
    integer nfps_orig(nshells)

    integer i, j, istart, ishell, n

    if (na .gt. 0) then

       do i = 1, nshells
          nfps_orig(ixshells(i)) = nfps(i)
       end do

       istart = 1
       do i = 1, nshells
          ishell = ixshells(i)

          n = 0
          do j = 1, ishell-1
             n = n + nfps_orig(j)
          end do

          do j = 1, nfps_orig(ishell)
             ixa(istart) = n + j
             istart = istart + 1
          end do
       end do

       do j = 1, na
          do i = 1, na
             xa(i) = mat(i,j)
          end do

          do i = 1, na
             mat(ixa(i),j) = xa(i)
          end do
       end do

       do i = 1, na
          do j = 1, na
             xa(j) = mat(i,j)
          end do

          do j = 1, na
             mat(i,ixa(j)) = xa(j)
          end do
       end do

    endif
  end subroutine descramble_matrix

end program test_descramble