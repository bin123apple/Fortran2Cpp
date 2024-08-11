module sorting_module
  implicit none
contains
  pure subroutine interchange_sort_dec_real(vec)
    real, intent(inout) :: vec(:)
    integer :: i, j
    real :: swap_value

    do i = 1, size(vec) - 1
       do j = i + 1, size(vec)
          if (vec(i) < vec(j)) then
             swap_value = vec(i)
             vec(i) = vec(j)
             vec(j) = swap_value
          end if
       end do
    end do
  end subroutine interchange_sort_dec_real
end module sorting_module

program testInterchangeSort
  use sorting_module
  implicit none
  real, allocatable :: testVec(:)

  ! Test with positive numbers
  allocate(testVec(5))
  testVec = [5.0, 3.0, 4.0, 1.0, 2.0]
  call interchange_sort_dec_real(testVec)
  print *, "Test with positive numbers: ", testVec

  ! Test with negative numbers
  testVec = [-1.0, -3.0, -2.0, -5.0, -4.0]
  call interchange_sort_dec_real(testVec)
  print *, "Test with negative numbers: ", testVec
  
  ! Test with mixed numbers
  testVec = [3.0, -2.0, 1.0, -4.0, 0.0]
  call interchange_sort_dec_real(testVec)
  print *, "Test with mixed numbers: ", testVec
  
  ! Test with repeating elements
  testVec = [2.0, 2.0, 1.0, 3.0, 3.0]
  call interchange_sort_dec_real(testVec)
  print *, "Test with repeating elements: ", testVec

  deallocate(testVec)
end program testInterchangeSort