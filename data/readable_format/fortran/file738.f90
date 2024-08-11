module test_module
  implicit none
contains
  subroutine test_formatting()
    character*10 c1, c2
    real(kind=8) r
    r = 1.0
    write(c1,"(e9.2)") r
    write(c2,"(d9.2)") r

    if (trim(adjustl(c1)) .ne. "0.10E+01") then
      print *, "Test failed for c1"
      stop
    endif
    if (trim(adjustl(c2)) .ne. "0.10D+01") then
      print *, "Test failed for c2"
      stop
    endif
    print *, "All Fortran tests passed."
  end subroutine test_formatting
end module test_module

program main
  use test_module
  call test_formatting()
end program main