program test_main
  implicit none
  integer :: i
  integer :: exit_status
  logical :: wait
  character(len=100) :: command

  command = './main'  ! Assuming 'main' is the compiled Fortran program
  wait = .true.

  do i = 1, 100  ! Run the test 100 times
     call execute_command_line(command, wait, exit_status)
     if (exit_status /= 0) then
        print *, 'Test failed on iteration ', i
        stop
     end if
  end do

  print *, 'All tests passed!'
end program test_main