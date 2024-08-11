program Concat_Arrays
  implicit none
  real, dimension(10,10) :: a 
  real, dimension(10) :: b = [ 4, 5, 6, 4, 5, 2, 7, 4, 9, 1]
  real, dimension(:,:), allocatable :: c
  
  call perform_test()
  
contains

  subroutine perform_test()
    implicit none
    integer :: i, j
    a = 1.0d0
  
    allocate(c(size(a,1)+1, size(a,2)+1))
    c = 0.0d0 
    c(1:size(a,1),1:size(a,2)) = a
    c(size(a,1)+1, 1:size(a,2)) = b
    c(1:size(a,1), size(a,2)+1) = b
  
    ! Test the size of a
    if (size(a,1) /= 10) then
      write(*,*) "Test Failed: Size of a is not 10."
      stop
    endif
  
    ! Test the contents of a
    do i = 1, size(a,1)
      do j = 1, size(a,2)
        if (a(i,j) /= 1.0d0) then
          write(*,*) "Test Failed: Element of a is not 1.0."
          stop
        endif
      enddo
    enddo
  
    write(*,*) "All Tests Passed."
  end subroutine perform_test

end program Concat_Arrays