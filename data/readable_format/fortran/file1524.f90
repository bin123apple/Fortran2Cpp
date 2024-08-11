program p_014
  use, intrinsic :: iso_fortran_env
  implicit none
  integer(int64) :: n, m, b
  integer :: i, p, a(1000000)
  a(:) = 0
  p = 0

  ! Main loop to calculate Collatz lengths
  do n = 1, 1000000
     m = n
     i = 1
     do while (m /= 1)
        if (mod(m, 2) == 0) then
           m = m / 2
           if (m <= 1000000) then
              if (a(m) /= 0) then
                 i = i + a(m)
                 exit
              end if
           end if
        else
           m = m * 3 + 1
        end if
        i = i + 1
     end do
     a(n) = i
     if (i > p) then
        b = n
        p = i
     end if
  end do
  write(output_unit, '("solution: ",g0,", count=",g0)') b, p

  ! Call test subroutine
  call testCollatz()
end program p_014

! Subroutine to calculate the Collatz sequence length for a single number
subroutine calculateCollatzLength(n, length)
  use, intrinsic :: iso_fortran_env
  implicit none
  integer(int64), intent(in) :: n
  integer(int64) :: m
  integer, intent(out) :: length
  m = n
  length = 1
  do while (m /= 1)
     if (mod(m, 2) == 0) then
        m = m / 2
     else
        m = m * 3 + 1
     end if
     length = length + 1
  end do
end subroutine calculateCollatzLength

! Subroutine for testing
subroutine testCollatz()
  use, intrinsic :: iso_fortran_env
  implicit none
  integer :: length

  ! Test case: The length of the Collatz sequence for n=13 should be 10
  call calculateCollatzLength(13, length)
  if (length == 10) then
     write(*,*) 'Test Passed: Length for n=13 is correct.'
  else
     write(*,*) 'Test Failed: Length for n=13 is incorrect. Got', length
  end if
end subroutine testCollatz