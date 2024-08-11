program test_peak
  implicit none
  real :: peaki = 0.00002
  real, dimension(3) :: peaksu
  integer :: iel = 2
  integer, dimension(3) :: ieltmp
  integer :: icnt = 0
  integer :: i

  ! Initialize arrays to zero
  peaksu = 0.0
  ieltmp = 0

  call peak(peaksu, peaki, iel, ieltmp, icnt)

  print *, "icnt:", icnt
  print *, "peaksu:"
  do i = 1, icnt
    print *, peaksu(i)
  end do
  print *, "ieltmp:"
  do i = 1, icnt
    print *, ieltmp(i)
  end do
end program test_peak

subroutine peak(peaksu,peaki,iel,ieltmp,icnt)
  implicit none
  real, intent(in) :: peaki
  real, dimension(3), intent(inout) :: peaksu
  integer, intent(in) :: iel
  integer, dimension(3), intent(inout) :: ieltmp
  integer, intent(inout) :: icnt

  if (peaki.gt.1.0e-05) then
    icnt = icnt + 1
    peaksu(icnt) = peaki
    ieltmp(icnt) = iel
  end if

  return
end subroutine peak