[INST] Translate this Fortran code to C++: 
program nested_brackets
  implicit none

  ! Main program body
  call run_tests()

contains

  logical function is_nested(str)
    character(len=*), intent(in) :: str
    integer :: count, maxcount, i

    count = 0
    maxcount = 0
    do i = 1, len(str)
      if (str(i:i) == '[') count = count + 1
      if (str(i:i) == ']') count = count - 1
      if (count < 0) count = 0
      if (count > maxcount) maxcount = count
      if (count <= maxcount - 2) then
        is_nested = .true.
        return
      end if
    end do
    is_nested = .false.
  end function is_nested

  subroutine assert(condition)
    logical, intent(in) :: condition
    if (.not. condition) then
      write(*,*) "Assertion failed"
      call exit(1)
    end if
  end subroutine assert

  subroutine run_tests()
    call assert(is_nested("[[]]") .eqv. .true.)
    call assert(is_nested("[]]]]]]][[[[[]") .eqv. .false.)
    call assert(is_nested("[][]") .eqv. .false.)
    call assert(is_nested("[]") .eqv. .false.)
    call assert(is_nested("[[[[]]]]") .eqv. .true.)
    call assert(is_nested("[]]]]]]]]]]") .eqv. .false.)
    call assert(is_nested("[][][[]]") .eqv. .true.)
    call assert(is_nested("[[]") .eqv. .false.)
    call assert(is_nested("[]]") .eqv. .false.)
    call assert(is_nested("[[]][[") .eqv. .true.)
    call assert(is_nested("[[][]]") .eqv. .true.)
    call assert(is_nested("") .eqv. .false.)
    call assert(is_nested("[[[[[[[[") .eqv. .false.)
    call assert(is_nested("]]]]]]]]") .eqv. .false.)
  end subroutine run_tests

end program nested_brackets [/INST]

[INST] Translate this Fortran code to C++: 
program nested_brackets
  implicit none

  ! Main program body
  call run_tests()

contains

  logical function is_nested(str)
    character(len=*), intent(in) :: str
    integer :: count, maxcount, i

    count = 0
    maxcount = 0
    do i = 1, len(str)
      if (str(i:i) == '[') count = count + 1
      if (str(i:i) == ']') count = count - 1
      if (count < 0) count = 0
      if (count > maxcount) maxcount = count
      if (count <= maxcount - 2) then
        is_nested = .true.
        return
      end if
    end do
    is_nested = .false.
  end function is_nested

  subroutine assert(condition)
    logical, intent(in) :: condition
    if (.not. condition) then
      write(*,*) "Assertion failed"
      call exit(1)
    end if
  end subroutine assert

  subroutine run_tests()
    call assert(is_nested("[[]]") .eqv. .true.)
    call assert(is_nested("[]]]]]]][[[[[]") .eqv. .false.)
    call assert(is_nested("[][]") .eqv. .false.)
    call assert(is_nested("[]") .eqv. .false.)
    call assert(is_nested("[[[[]]]]") .eqv. .true.)
    call assert(is_nested("[]]]]]]]]]]") .eqv. .false.)
    call assert(is_nested("[][][[]]") .eqv. .true.)
    call assert(is_nested("[[]") .eqv. .false.)
    call assert(is_nested("[]]") .eqv. .false.)
    call assert(is_nested("[[]][[") .eqv. .true.)
    call assert(is_nested("[[][]]") .eqv. .true.)
    call assert(is_nested("") .eqv. .false.)
    call assert(is_nested("[[[[[[[[") .eqv. .false.)
    call assert(is_nested("]]]]]]]]") .eqv. .false.)
  end subroutine run_tests

end program nested_brackets [/INST]

[INST] Translate this Fortran code to C++: 
program nested_brackets
  implicit none

  ! Main program body
  call run_tests()

contains

  logical function is_nested(str)
    character(len=*), intent(in) :: str
    integer :: count, maxcount, i

    count = 0
    maxcount = 0
    do i = 1, len(str)
      if (str(i:i) == '[') count = count + 1
      if (str(i:i) == ']') count = count - 1
      if (count < 0) count = 0
      if (count > maxcount) maxcount = count
      if (count <= maxcount - 2) then
        is_nested = .true.
        return
      end if
    end do
    is_nested = .false.
  end function is_nested

  subroutine assert(condition)
    logical, intent(in) :: condition
    if (.not. condition) then
      write(*,*) "Assertion failed"
      call exit(1)
    end if
  end subroutine assert

  subroutine run_tests()
    call assert(is_nested("[[]]") .eqv. .true.)
    call assert(is_nested("[]]]]]]][[[[[]") .eqv. .false.)
    call assert(is_nested("[][]") .eqv. .false.)
    call assert(is_nested("[]") .eqv. .false.)
    call assert(is_nested("[[[[]]]]") .eqv. .true.)
    call assert(is_nested("[]]]]]]]]]]") .eqv. .false.)
    call assert(is_nested("[][][[]]") .eqv. .true.)
    call assert(is_nested("[[]") .eqv. .false.)
    call assert(is_nested("[]]") .eqv. .false.)
    call assert(is_nested("[[]][[") .eqv. .true.)
    call assert(is_nested("[[][]]") .eqv. .true.)
    call assert(is_nested("") .eqv. .false.)
    call assert(is_nested("[[[[[[[[") .eqv. .false.)
    call assert(is_nested("]]]]]]]]") .eqv. .false.)
  end subroutine run_tests

end program nested_brackets [/INST]

[INST] Translate this Fortran code to C++: 
program nested_brackets
  implicit none

  ! Main program body
  call run_tests()

contains

  logical function is_nested(str)
    character(len=*), intent(in) :: str
    integer :: count, maxcount, i

    count = 0
    maxcount = 0
    do i = 1, len(str)
      if (str(i:i) == '[') count = count + 1
      if (str(i:i) == ']') count = count - 1
      if (count < 0) count = 0
      if (count > maxcount) maxcount = count
      if (count <= maxcount - 2) then
        is_nested = .true.
        return
      end if
    end do
    is_nested = .false.
  end function is_nested

  subroutine assert(condition)
    logical, intent(in) :: condition
    if (.not. condition) then
      write(*,*) "Assertion failed"
