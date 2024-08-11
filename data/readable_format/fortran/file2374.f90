program test_foo0
  call foo0()
end program

subroutine foo0()
  integer :: j
  do j = 1, 2
    if (.true.) then
      print *, "Loop iteration: ", j
    end if
  end do
end subroutine