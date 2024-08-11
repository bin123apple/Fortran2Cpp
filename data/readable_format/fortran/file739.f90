program tester
  implicit none
  character(LEN=:), allocatable :: result

  ! Test for function 'test'
  result = test(2)
  if (len(result) /= 4) call abort()
  if (result /= "test") call abort()
  print *, "Test for 'test' passed."

  ! Test for function 'test2'
  result = test2(2)
  if (len(result) /= 4) call abort()
  if (result /= "test") call abort()
  print *, "Test for 'test2' passed."

contains

  function test(alen)
    integer :: alen
    character(LEN=:), allocatable :: test
    test = 'test'
    if (len(test) /= 4) call abort()
    if (test /= "test") call abort()
  end function test

  function test2(alen) result(test)
    integer :: alen
    character(LEN=:), allocatable :: test
    test = 'test'
    if (len(test) /= 4) call abort()
    if (test /= "test") call abort()
  end function test2

end program tester