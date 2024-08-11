module foo_mod
  implicit none
contains

  subroutine foo(x, result)
    character(len=*), intent(in), optional :: x
    character(len=80) :: result
    !$omp master
      if (present(x)) then
        result = adjustl(x)
      else
        result = ' '
      endif
    !$omp end master
  end subroutine foo

end module foo_mod

program test_foo
  use foo_mod
  implicit none
  character(len=80) :: result
  character(len=80) :: expected
  character(len=80) :: input

  input = '   example'
  expected = 'example'

  call foo(input, result)

  if (trim(result) == expected) then
    print *, "Fortran Test passed."
  else
    print *, "Fortran Test failed."
  end if
end program test_foo