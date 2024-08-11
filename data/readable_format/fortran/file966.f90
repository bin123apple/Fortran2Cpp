! Define the flood subroutine first
subroutine flood(zslice, wet, dry, x, y, dmax, flooded_zslice, im, jm, nbwet, nbdry)
  implicit none
  integer, dimension(nbwet, 2), intent(in) :: wet
  integer, dimension(nbdry, 2), intent(in) :: dry
  real*8, dimension(im, jm), intent(in) :: zslice, x, y
  real*8, dimension(im, jm), intent(out) :: flooded_zslice
  integer :: im, jm, nbwet, nbdry, n, m, dmax
  integer :: idry, jdry, iwet, jwet, dmin_idx, iclose, jclose
  real*8, dimension(nbwet) :: d

  flooded_zslice = zslice

  do n=1,nbdry
    idry = dry(n,1)
    jdry = dry(n,2)
    do m=1,nbwet
      iwet = wet(m,1)
      jwet = wet(m,2)
      d(m) = sqrt( (x(idry,jdry) - x(iwet,jwet))**2 + (y(idry,jdry) - y(iwet,jwet))**2 )
    end do
    dmin_idx = minloc(d,1)
    iclose = wet(dmin_idx,1)
    jclose = wet(dmin_idx,2)
    if (dmax == 0 .or. d(dmin_idx) < dmax) then
      flooded_zslice(idry,jdry) = zslice(iclose,jclose)
    end if
  end do
end subroutine flood

! Main program to test the flood subroutine
program test_flood
  implicit none
  real*8, allocatable :: zslice(:,:), x(:,:), y(:,:), flooded_zslice(:,:)
  integer, allocatable :: wet(:,:), dry(:,:)
  integer :: im, jm, nbwet, nbdry, dmax, i, j

  ! Example parameters for the test
  im = 2; jm = 2; nbwet = 1; nbdry = 1; dmax = 0
  allocate(zslice(im,jm), x(im,jm), y(im,jm), flooded_zslice(im,jm), wet(nbwet,2), dry(nbdry,2))
  
  ! Initialize arrays
  zslice = reshape([1.0d0, 2.0d0, 3.0d0, 4.0d0], shape(zslice))
  x = reshape([0d0, 1d0, 0d0, 1d0], shape(x))
  y = reshape([0d0, 0d0, 1d0, 1d0], shape(y))
  wet = reshape([1, 1], shape(wet))
  dry = reshape([2, 2], shape(dry))
  
  ! Call the flood subroutine
  call flood(zslice, wet, dry, x, y, dmax, flooded_zslice, im, jm, nbwet, nbdry)
  
  ! Output results for verification
  print *, "Flooded ZSlice:"
  do i = 1, im
    print *, (flooded_zslice(i,j), j=1,jm)
  end do
end program test_flood