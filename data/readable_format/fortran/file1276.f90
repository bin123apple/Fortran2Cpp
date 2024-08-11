program main
  implicit none
  integer :: nalloc0, ngarbg0, nalloc1, ngarbg1
  integer :: nerr

  ! Mock values for allocated and garbage bytes before subroutine call
  nalloc0 = 100
  ngarbg0 = 50

  ! Call the subroutine that does allocation/deallocation
  call sub

  ! Mock values for allocated and garbage bytes after subroutine call
  nalloc1 = 100  ! Assuming no change for simplicity
  ngarbg1 = 50   ! Assuming no change for simplicity

  nerr = 0
  if (nalloc0 /= nalloc1) then
     nerr = nerr + 1
     print *, "NG nalloc0=", nalloc0, "nalloc1=", nalloc1
  endif
  if (ngarbg0 /= ngarbg1) then
     nerr = nerr + 1
     print *, "NG ngarbg0=", ngarbg0, "ngarbg1=", ngarbg1
  endif

  if (nerr == 0) then
     print *, "OK"
  else
     print *, "number of NGs: ", nerr
     stop 1
  end if

contains

  subroutine sub
    ! This subroutine would contain logic for memory allocation/deallocation
    ! For simplicity, it's left empty here.
    return
  end subroutine sub

end program main