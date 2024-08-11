program test_emptyarray5
  implicit none
  call testEmptyArray()

contains

  subroutine testEmptyArray()
    implicit none
    real, allocatable :: a(:)
    allocate(a(0)) ! Explicitly allocate an empty array for clarity
    if (size(a) == 0) then
      print *, "Test passed: Array is empty."
    else
      print *, "Test failed: Array is not empty."
    endif
  end subroutine testEmptyArray

end program test_emptyarray5