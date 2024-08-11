program test_fortran_code
  implicit none
  
  call test_foo()
  
contains

  subroutine test_foo()
    character(4), dimension(4) :: c1, c2
    integer :: i
    ! Test 1: Direct assignment
    call foo((/"abcd", "efgh", "ijkl", "mnop"/), c1)
    call foo(c1, c2)
    do i = 1, 4
      if (c2(i) /= c1(i)) then
        print *, "Test 1 Failed at index", i
        stop
      endif
    enddo
    print *, "Test 1 Passed"
  end subroutine test_foo

  subroutine foo (chr1, chr2)
    character(*), dimension(:) :: chr1, chr2
    chr2 = chr1
  end subroutine foo

end program test_fortran_code