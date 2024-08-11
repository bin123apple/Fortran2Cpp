program test_fsub3
  implicit none
  integer :: arg, res

  ! Test case 1
  arg = 5
  call fsub3(arg, res)
  if (res == 20) then
    print *, 'Test case 1 passed.'
  else
    print *, 'Test case 1 failed.'
  end if

  ! Add more test cases as needed

end program test_fsub3

subroutine fsub3(arg,res)
  implicit none
  integer :: arg, res

  write(*,*) 'fsub3 called'
  res = arg * 4
end subroutine fsub3