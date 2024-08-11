module mo_column
  contains
    subroutine compute_column(result)
      integer, intent(out) :: result
      result = 5  ! Example operation
    end subroutine compute_column
end module mo_column

program test_mo_column
  use mo_column
  implicit none
  integer :: output

  call compute_column(output)

  if (output == 5) then
    print *, 'Test passed: output = ', output
  else
    print *, 'Test failed: output = ', output
  end if
end program test_mo_column