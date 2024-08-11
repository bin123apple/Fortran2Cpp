program test_program
  use, intrinsic :: iso_fortran_env
  implicit none
  integer(int64) :: result, expected
  character(len=20) :: fileName
  fileName = 'output.txt'

  ! Assuming the main program has been modified to write the result into 'output.txt'
  open(unit=10, file=fileName, status='old', action='read')
  read(10, *) result
  close(10)
  
  expected = 142913828922_int64
  if (result == expected) then
      print *, "Test passed. Result is correct."
  else
      print *, "Test failed. Expected:", expected, "Got:", result
  end if
end program test_program