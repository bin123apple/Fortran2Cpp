module elemental_operations
  implicit none
contains
  elemental integer function e_fn(p, q)
    integer, intent(in) :: p, q
    e_fn = p - q
  end function e_fn
end module elemental_operations

program test_elemental
  use elemental_operations
  implicit none
  integer(kind = 4), dimension(2, 4) :: a, b
  integer(kind = 8), dimension(2) :: c

  a = reshape((/2, 3, 4, 5, 6, 7, 8, 9/), (/2, 4/))
  b = 0
  b(2, :) = e_fn(a(1, :), 1)
  if (any(b .ne. reshape((/0, 1, 0, 3, 0, 5, 0, 7/), (/2, 4/)))) call abort
  ! Continue with the rest of your program operations and checks

  ! Call test routines
  call test_e_fn()
end program test_elemental

subroutine test_e_fn()
  use elemental_operations
  implicit none
  integer :: result

  result = e_fn(5, 3)
  if (result /= 2) then
    print *, "Test failed for e_fn with inputs 5, 3. Expected 2, got ", result
    call abort
  end if

  ! Add more tests as needed
  print *, "All tests passed for e_fn."
end subroutine test_e_fn