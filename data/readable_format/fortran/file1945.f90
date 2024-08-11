program test_btn
  implicit none
  integer :: result
  logical, dimension(3) :: test_case1
  logical, dimension(4) :: test_case2

  ! Test case 1: All true
  test_case1 = .true.
  call btn(result, test_case1)
  if (result == 7) then
    write(*,*) "Test case 1 passed."
  else
    write(*,*) "Test case 1 failed."
  endif

  ! Test case 2: Mixed values
  test_case2 = (/ .true., .false., .true., .true. /)
  call btn(result, test_case2)
  if (result == 13) then
    write(*,*) "Test case 2 passed."
  else
    write(*,*) "Test case 2 failed."
  endif

contains

  subroutine btn(n,b)
    integer, intent(out)::n
    logical, intent(in)::b(:)
    integer :: i

    n = 0
    do i=size(b),1,-1
       n = n * 2
       if (b(i)) n = n + 1
    enddo
  end subroutine btn

end program test_btn