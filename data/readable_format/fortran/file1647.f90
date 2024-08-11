program test_stop_pp
  implicit none

  ! Mock subroutine to simulate stop_pp's file handling
  call mock_stop_pp('dummy.txt')

  ! Test subroutine
  call test_file_deleted()

contains

  subroutine mock_stop_pp(filename)
    character(len=*), intent(in) :: filename
    logical :: op

    ! Pretend to open and immediately delete a file named 'dummy.txt'
    open(unit=10, file=filename, status='replace', action='write')
    write(10,*) 'Test content'
    close(unit=10, status='delete')

  end subroutine mock_stop_pp

  subroutine test_file_deleted
    logical :: op

    ! Check if 'dummy.txt' exists after mock_stop_pp is called
    inquire(file='dummy.txt', exist=op)
    if (.not. op) then
      print *, 'Test passed: File successfully deleted.'
    else
      print *, 'Test failed: File still exists.'
    endif
  end subroutine test_file_deleted

end program test_stop_pp