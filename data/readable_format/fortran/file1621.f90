program testFortranCode
implicit none
integer, target :: x(0:12)
integer, pointer :: z(:)
integer i
logical :: testPassed

! Initialize and test the array and pointer semantics as in the original code
do i = 0,12
  x(i) = i
enddo
z => x

! Test
testPassed = .TRUE.
do i = 0,12
  if (x(i) /= i .or. z(i) /= i) then
    testPassed = .FALSE.
    exit
  endif
enddo

! Check test result
if (testPassed) then
  print *, "Fortran Test Passed"
else
  print *, "Fortran Test Failed"
endif

end program testFortranCode