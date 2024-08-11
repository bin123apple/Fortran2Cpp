module my_subroutines
  implicit none
contains

  subroutine foo(array1, array2)
    integer, intent(inout) :: array1(:, :)
    real, intent(inout) :: array2(:, :, :)

    array1 = 5
    array1(1, 1) = 30

    array2 = 3.0
    array2(1, 1, 1) = 30.0
    array2(3, 3, 3) = 90.0
  end subroutine foo

end module my_subroutines

program test_vla_sub
  use my_subroutines
  implicit none

  real, allocatable :: test_array2(:,:,:)
  integer, allocatable :: test_array1(:,:)
  integer :: i, j, k
  logical :: test_passed

  allocate(test_array1(3,3), test_array2(3,3,3))

  test_array1 = 0
  test_array2 = 0.0

  call foo(test_array1, test_array2)

  test_passed = .true.
  if (test_array1(1,1) /= 30) test_passed = .false.
  if (test_array1(2,2) /= 5) test_passed = .false.
  if (test_array2(1,1,1) /= 30.0) test_passed = .false.
  if (test_array2(3,3,3) /= 90.0) test_passed = .false.
  do i = 1, 3
     do j = 1, 3
        if (i /= 1 .or. j /= 1) then
           if (test_array1(i,j) /= 5) test_passed = .false.
        end if
        do k = 1, 3
           if ((i /= 1 .or. j /= 1 .or. k /= 1) .and. &
               (i /= 3 .or. j /= 3 .or. k /= 3)) then
              if (test_array2(i,j,k) /= 3.0) test_passed = .false.
           end if
        end do
     end do
  end do

  if (test_passed) then
     print *, "Test passed."
  else
     print *, "Test failed."
  endif

end program test_vla_sub