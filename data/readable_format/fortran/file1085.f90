program test_convert2slapcol
  implicit none

  integer, parameter :: nelem = 5
  integer :: jq(nelem+1)
  real*8 :: au(nelem), ad(nelem), aua(2*nelem)
  integer :: i

  ! Initialize test data
  au = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
  ad = (/10.0d0, 20.0d0, 30.0d0, 40.0d0, 50.0d0/)
  jq = (/1, 2, 3, 4, 5, 6/)

  call convert2slapcol(au, ad, jq, 5, 5, aua)

  print *, 'aua:'
  do i = 1, 10
     print *, aua(i)
  end do

contains

  subroutine convert2slapcol(au, ad, jq, nzs, nef, aua)
    implicit none

    integer jq(*), nzs, nef, i, j, k
    real*8 au(*), ad(*), aua(*)

    k = nzs + nef

    do i = nef, 1, -1
       do j = jq(i+1) - 1, jq(i), -1
          aua(k) = au(j)
          k = k - 1
       end do
       aua(k) = ad(i)
       k = k - 1
    end do

    return
  end subroutine convert2slapcol

end program test_convert2slapcol