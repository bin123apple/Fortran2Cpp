program test_s_to_c
  implicit none
  CHARACTER(LEN=:), ALLOCATABLE :: str
  
  ! Test 1
  str = s_to_c("ABCdef")
  if (str /= "ABCdef" .or. len(str) /= 6) then
     print *, "Test 1 FAILED."
  else
     print *, "Test 1 PASSED."
  end if

  ! Test 2
  str = s_to_c("ABCdef")
  if (str /= "ABCdef" .or. len(str) /= 6) then
     print *, "Test 2 FAILED."
  else
     print *, "Test 2 PASSED."
  end if

  ! Test 3
  str = "ABCdef"
  str(1:3) = s_to_c("123")
  if (str /= "123def" .or. len(str) /= 6) then
     print *, "Test 3 FAILED."
  else
     print *, "Test 3 PASSED."
  end if

contains

  PURE FUNCTION s_to_c(string) 
    CHARACTER(LEN=*), INTENT(IN)   :: string 
    CHARACTER(LEN=:), ALLOCATABLE :: s_to_c 
    s_to_c = string
  END FUNCTION s_to_c

end program test_s_to_c