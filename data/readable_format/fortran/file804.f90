program test_r1f2kb
  implicit none

  integer, parameter :: ido = 2, l1 = 2, in1 = 2, in2 = 2
  real(8), dimension(in1,ido,2,l1) :: cc
  real(8), dimension(in2,ido,l1,2) :: ch
  real(8), dimension(ido) :: wa1
  integer :: i, j, k, l

  ! Initialize test data
  cc = reshape( &
     [1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0, 6.0d0, 7.0d0, 8.0d0, &
      9.0d0, 10.0d0, 11.0d0, 12.0d0, 13.0d0, 14.0d0, 15.0d0, 16.0d0], &
      shape(cc))
  wa1 = [1.0d0, 2.0d0]

  ! Call the subroutine
  call r1f2kb(ido, l1, cc, in1, ch, in2, wa1)

  ! Print results
  do l = 1, 2
     do k = 1, l1
        do j = 1, ido
           print *, 'ch(', in2, ',', j, ',', k, ',', l, ') = ', ch(in2,j,k,l)
        end do
     end do
  end do

end program test_r1f2kb

subroutine r1f2kb(ido, l1, cc, in1, ch, in2, wa1)
  implicit none

  integer(kind=4) :: ido, l1, in1, in2
  real(kind=8), dimension(in1,ido,2,l1) :: cc
  real(kind=8), dimension(in2,ido,l1,2) :: ch
  real(kind=8), dimension(ido) :: wa1
  integer(kind=4) :: i, ic, idp2, k

  do k = 1, l1
     ch(1,1,k,1) = cc(1,1,1,k) + cc(1,ido,2,k)
     ch(1,1,k,2) = cc(1,1,1,k) - cc(1,ido,2,k)
  end do

  if (ido > 2) then
     idp2 = ido + 2
     do k = 1, l1
        do i = 3, ido, 2
           ic = idp2 - i

           ch(1, i-1, k, 1) = cc(1, i-1, 1, k) + cc(1, ic-1, 2, k)
           ch(1, i, k, 1) = cc(1, i, 1, k) - cc(1, ic, 2, k)

           ch(1, i-1, k, 2) = wa1(i-2) * (cc(1, i-1, 1, k) - cc(1, ic-1, 2, k)) - &
                wa1(i-1) * (cc(1, i, 1, k) + cc(1, ic, 2, k))
           ch(1, i, k, 2) = wa1(i-2) * (cc(1, i, 1, k) + cc(1, ic, 2, k)) + &
                wa1(i-1) * (cc(1, i-1, 1, k) - cc(1, ic-1, 2, k))
        end do
     end do
  end if

  if (mod(ido, 2) == 0) then
     do k = 1, l1
        ch(1, ido, k, 1) = 2 * cc(1, ido, 1, k)
        ch(1, ido, k, 2) = -2 * cc(1, 1, 2, k)
     end do
  end if

end subroutine r1f2kb