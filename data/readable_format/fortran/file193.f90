module matrixGen
  implicit none
contains
  function gen(order) result(res)
    integer, intent(in) :: order
    real, dimension(:,:), allocatable :: res
    integer :: i, j

    allocate(res(order, order + 1))
    do i = 1, order
      do j = 1, order + 1
        res(i, j) = i * i + j
      end do
    end do
  end function gen
end module matrixGen

program main
  use matrixGen
  implicit none

  call unitTest()

contains

  subroutine unitTest()
    implicit none
    real, dimension(:,:), allocatable :: result
    integer :: i, j, order

    ! Test 1: Check square of first index plus second index
    order = 3
    result = gen(order)  ! This is now valid because gen is in a module
    do i = 1, order
      do j = 1, order + 1
        if (result(i, j) /= i * i + j) then
          print *, "Test 1 Failed at: (", i, ",", j, ")"
          return
        endif
      end do
    end do
    print *, "All Tests Passed"
  end subroutine unitTest

end program main