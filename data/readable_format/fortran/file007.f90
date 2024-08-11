module getbuf_mod
  implicit none
contains
  subroutine GETBUF(BUF1,BUF2,NPIX,NRAST)
    integer :: NPIX, NRAST, I
    real, dimension(NPIX*NRAST) :: BUF1, BUF2

    do I=1,NPIX*NRAST
      BUF2(I) = BUF1(I)
    end do
  end subroutine GETBUF
end module getbuf_mod

program test_getbuf
  use getbuf_mod
  implicit none
  
  integer :: npix, nrast, i
  real, allocatable :: buf1(:), buf2(:)
  logical :: test_passed
  
  ! Initialize test parameters
  npix = 10
  nrast = 5
  
  ! Allocate the buffers
  allocate(buf1(npix*nrast))
  allocate(buf2(npix*nrast))
  
  ! Fill buf1 with test data
  do i = 1, npix*nrast
    buf1(i) = real(i)
  end do
  
  ! Call the subroutine
  call GETBUF(buf1, buf2, npix, nrast)
  
  ! Verify buf2 contains the copied data
  test_passed = .true.
  do i = 1, npix*nrast
    if (buf2(i) /= buf1(i)) then
      test_passed = .false.
      exit
    endif
  end do
  
  ! Output the result
  if (test_passed) then
    print *, "Test Passed."
  else
    print *, "Test Failed."
  endif
  
  ! Clean up
  deallocate(buf1)
  deallocate(buf2)

end program test_getbuf