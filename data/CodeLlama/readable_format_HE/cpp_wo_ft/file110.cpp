[INST] Translate this Fortran code to C++: 
program special_factorial_program
  implicit none
  integer, parameter :: int64 = selected_int_kind(18)
  integer(int64) :: result

  ! Test cases
  result = special_factorial(4)
  if (result /= 288_int64) then
    write(*,*) "special_factorial(4) == 288: assertion failed"
    call exit(1)
  end if

  result = special_factorial(5)
  if (result /= 34560_int64) then
    write(*,*) "special_factorial(5) == 34560: assertion failed"
    call exit(1)
  end if

  result = special_factorial(7)
  if (result /= 125411328000_int64) then
    write(*,*) "special_factorial(7) == 125411328000: assertion failed"
    call exit(1)
  end if

  result = special_factorial(1)
  if (result /= 1_int64) then
    write(*,*) "special_factorial(1) == 1: assertion failed"
    call exit(1)
  end if

contains

  function special_factorial(n) result(bfact)
    implicit none
    integer, intent(in) :: n
    integer(int64) :: bfact
    integer(int64) :: fact
    integer :: i

    fact = 1
    bfact = 1
    do i = 1, n
      fact = fact * i
      bfact = bfact * fact
    end do
  end function special_factorial

end program special_factorial_program [/INST]

[INST] Translate this Fortran code to C++: 
program special_factorial_program
  implicit none
  integer, parameter :: int64 = selected_int_kind(18)
  integer(int64) :: result

  ! Test cases
  result = special_factorial(4)
  if (result /= 288_int64) then
    write(*,*) "special_factorial(4) == 288: assertion failed"
    call exit(1)
  end if

  result = special_factorial(5)
  if (result /= 34560_int64) then
    write(*,*) "special_factorial(5) == 34560: assertion failed"
    call exit(1)
  end if

  result = special_factorial(7)
  if (result /= 125411328000_int64) then
    write(*,*) "special_factorial(7) == 125411328000: assertion failed"
    call exit(1)
  end if

  result = special_factorial(1)
  if (result /= 1_int64) then
    write(*,*) "special_factorial(1) == 1: assertion failed"
    call exit(1)
  end if

contains

  function special_factorial(n) result(bfact)
    implicit none
    integer, intent(in) :: n
    integer(int64) :: bfact
    integer(int64) :: fact
    integer :: i

    fact = 1
    bfact = 1
    do i = 1, n
      fact = fact * i
      bfact = bfact * fact
    end do
  end function special_factorial

end program special_factorial_program [/INST]

[INST] Translate this Fortran code to C++: 
program special_factorial_program
  implicit none
  integer, parameter :: int64 = selected_int_kind(18)
  integer(int64) :: result

  ! Test cases
  result = special_factorial(4)
  if (result /= 288_int64) then
    write(*,*) "special_factorial(4) == 288: assertion failed"
    call exit(1)
  end if

  result = special_factorial(5)
  if (result /= 34560_int64) then
    write(*,*) "special_factorial(5) == 34560: assertion failed"
    call exit(1)
  end if

  result = special_factorial(7)
  if (result /= 125411328000_int64) then
    write(*,*) "special_factorial(7) == 125411328000: assertion failed"
    call exit(1)
  end if

  result = special_factorial(1)
  if (result /= 1_int64) then
    write(*,*) "special_factorial(1) == 1: assertion failed"
    call exit(1)
  end if

contains

  function special_factorial(n) result(bfact)
    implicit none
    integer, intent(in) :: n
    integer(int64) :: bfact
    integer(int64) :: fact
    integer :: i

    fact = 1
    bfact = 1
    do i = 1, n
      fact = fact * i
      bfact = bfact * fact
    end do
  end function special_factorial

end program special_factorial_program [/INST]

[INST] Translate this Fortran code to C++: 
program special_factorial_program
  implicit none
  integer, parameter :: int64 = selected_int_kind(18)
  integer(int64) :: result

  ! Test cases
  result = special_factorial(4)
  if (result /= 288_int64) then
    write(*,*) "special_factorial(4) == 288: assertion failed"
    call exit(1)
  end if

  result = special_factorial(5)
  if (result /= 34560_int64) then
    write(*,*) "special_factorial(5) == 34560: assertion failed"
    call exit(1)
  end if

  result = special_factorial(7)
  if (result /= 125411328000_int64) then
    write(*,*) "special_factorial(7) == 125411328000: assertion failed"
    call exit(1)
  end if

  result = special_factorial(1)
  if (result /= 1_int64) then
    write(*,*) "special_factorial(1) == 1: assertion failed"
    call exit(1)
  end if

contains

  function special_factorial(n) result(bfact)
    implicit none
    integer, intent(in) :: n
    integer(int64) :: bfact
    integer(int64) :: fact
    integer :: i

    fact = 1
    bfact = 1
    do i = 1, n
      fact = fact * i
      bfact = bfact * fact
    end do
  end function special_factorial

end program special_factorial_program [/INST]

[INST] Translate this Fortran code to C++: 
program special_factorial_program
  implicit none
  integer, parameter :: int64 = selected_int_kind(18)
  integer(int64) :: result

  ! Test cases
  result = special_factorial(4)
  if (result /= 288_int64) then
    write(*,*) "special_factorial(4) == 288: assertion failed"
    call exit(1)
  end if

  result = special_factorial(5)
  if (result /= 34560_int64) then
    write(*,*) "special_factorial(5) == 34560: assertion failed"
    call exit(1)
  end if

  result = special_factorial(7)
  if (result /= 125411328000
