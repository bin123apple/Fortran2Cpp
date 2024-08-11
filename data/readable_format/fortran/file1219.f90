program main
  implicit none
  ! Main program code
  call test_main()
  call test()
  print *, "All tests passed successfully."
end program main

subroutine test_main()
  implicit none
  character(len=:), allocatable :: s
  integer :: j = 2
  s = repeat('x', j)
  if (len(repeat(' ', j)) /= 2) then
    call abort()
  endif
  if (repeat('y', j) /= "yy") then
    call abort()
  endif
  if (len(s) /= 2) then
    call abort()
  endif
  if (s /= "xx") then
    call abort()
  endif
end subroutine test_main

subroutine test()
  implicit none
  integer :: i = 5
  character(len=:), allocatable :: s1
  call sub(s1, i)
  if (len(s1) /= 5) then
    call abort()
  endif
  if (s1 /= "ZZZZZ") then
    call abort()
  endif
contains
  subroutine sub(str, j)
    character(len=:), allocatable :: str
    integer :: j
    str = REPEAT("Z", j)
    if (len(str) /= 5) then
      call abort()
    endif
    if (str /= "ZZZZZ") then
      call abort()
    endif
  end subroutine sub
end subroutine test