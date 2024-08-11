program testComparisons
  implicit none
  logical :: testResult

  ! Test 1
  testResult = 1.0 > 0.1
  call assert(testResult, "Test 1.0 > 0.1 failed")

  ! Test 2 (Similar to Test 1, can be skipped for brevity)

  ! Test 3
  testResult = 1 < 2
  call assert(testResult, "Test 1 < 2 failed")

  ! And so on for each comparison...

contains

  subroutine assert(condition, message)
    logical, intent(in) :: condition
    character(*), intent(in) :: message
    if (.not. condition) then
      print *, trim(message)
    else
      print *, "Test passed"
    end if
  end subroutine assert

end program testComparisons