program main
  implicit none
  character(len=1) :: result

  ! Test 1
  call testContiguity(.true., 'T', "Test 1: Full slice contiguous")

  ! Test 2
  call testContiguity(.false., 'F', "Test 2: Partial slice non-contiguous")

contains

  subroutine testContiguity(expectedResult, expectedChar, description)
    logical, intent(in) :: expectedResult
    character(len=1), intent(in) :: expectedChar
    character(len=*), intent(in) :: description
    character(len=1) :: line

    write (unit=line, fmt='(L1)') expectedResult
    if (line == expectedChar) then
      print *, trim(description), " - passed."
    else
      print *, trim(description), " - failed."
    end if
  end subroutine testContiguity

end program main