program test_slice
  implicit none
  
  real (kind = 8), dimension(2, 2, 2) :: x
  real (kind = 8) :: min, max

  x = 1.0
  call test_initialization(x)
  call test_slice_min_max(x)
  call test_slice_shape(x)
  print *, "All Fortran tests passed successfully."

contains

  subroutine test_initialization(x)
    real(kind=8), dimension(2,2,2), intent(in) :: x
    integer :: i, j, k
    do i = 1, 2
      do j = 1, 2
        do k = 1, 2
          if (x(i, j, k) /= 1.0) then
            print *, "Initialization test failed."
            stop
          endif
        enddo
      enddo
    enddo
  end subroutine test_initialization

  subroutine test_slice_min_max(x)
    real(kind=8), dimension(2,2,2), intent(in) :: x
    if (minval(x(1, 1:2, 1:1)) /= 1.0) then
      print *, "Min test failed."
      stop
    endif
    if (maxval(x(1, 1:2, 1:1)) /= 1.0) then
      print *, "Max test failed."
      stop
    endif
  end subroutine test_slice_min_max

  subroutine test_slice_shape(x)
    real(kind=8), dimension(2,2,2), intent(in) :: x
    integer, dimension(2) :: expected_shape_2_1
    integer, dimension(1) :: expected_shape_2
    integer, dimension(3) :: expected_shape_1_2_1
    
    expected_shape_2_1 = (/2, 1/)
    expected_shape_2 = (/2/)
    expected_shape_1_2_1 = (/1, 2, 1/)
    
    if (any(shape(x(1, 1:2, 1:1)) /= expected_shape_2_1)) then
      print *, "Slice shape test (2,1) failed."
      stop
    endif
    if (any(shape(x(1, 1:2, 1)) /= expected_shape_2)) then
      print *, "Slice shape test (2) failed."
      stop
    endif
    if (any(shape(x(1:1, 1:2, 1:1)) /= expected_shape_1_2_1)) then
      print *, "Slice shape test (1,2,1) failed."
      stop
    endif
  end subroutine test_slice_shape

end program test_slice