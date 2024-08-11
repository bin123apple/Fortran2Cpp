module backusmod
  implicit none
  integer, private :: navg, nz

contains

  subroutine dobackus_init(navg_in, nz_in)
    integer :: navg_in, nz_in
    navg = navg_in
    nz = nz_in
  end subroutine dobackus_init

  subroutine handlEnds(p)
    integer :: ii, mm
    real :: gt, gb
    real, dimension(:), intent(inout) :: p
    mm = (navg-1)/2 + 1
    gt = p(mm)
    gb = p(nz-mm+1)
    do ii = 1, mm
      p(ii) = gt
    end do
    do ii = nz-mm+1, nz
      p(ii) = gb
    end do
  end subroutine handlEnds

  subroutine dobackus(p, avg)
    integer :: ii, jj, mm
    real, dimension(:), intent(in) :: p
    real, dimension(:), intent(out) :: avg
    real :: val
    mm = (navg-1)/2
    do ii = 1, nz
      val = 0.0
      if (ii-mm >= 1 .and. ii+mm <= nz) then
        do jj = ii-mm, ii+mm
          val = val + p(jj)
        end do
        avg(ii) = val/navg
      else
        avg(ii) = p(ii)
      end if
    end do
  end subroutine dobackus

end module backusmod

program test_backusmod
  use backusmod
  implicit none
  real, allocatable :: p(:), avg(:)
  integer :: i, navg, nz

  navg = 5
  nz = 10
  allocate(p(nz), avg(nz))

  ! Initialize p with linearly increasing values
  do i = 1, nz
    p(i) = real(i)
  end do

  ! Initialize the module
  call dobackus_init(navg, nz)

  ! Test handling ends
  call handlEnds(p)
  print *, "After handling ends:"
  print *, p

  ! Test main data processing routine
  call dobackus(p, avg)
  print *, "After dobackus:"
  print *, avg

end program test_backusmod