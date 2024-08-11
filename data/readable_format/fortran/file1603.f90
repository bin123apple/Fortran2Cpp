program char_pointer_dummy_test
  implicit none
  character(len=4)                :: c0
  character(len=4), pointer       :: c1
  character(len=4), pointer       :: c2(:)

  allocate(c1, c2(1))
  c0 = "wxyz"
  call foo(c0)
  c1 = "wxyz"
  call sfoo(c1)
  c2 = "wxyz"
  call afoo(c2)
  deallocate(c1, c2)

  print *, "All tests passed."

contains

  subroutine foo(cc1)
    character(len=4), intent(in) :: cc1
    if (cc1 /= "wxyz") call abort()
  end subroutine foo

  subroutine sfoo(sc1)
    character(len=4), pointer, intent(in) :: sc1
    if (sc1 /= "wxyz") call abort()
  end subroutine sfoo

  subroutine afoo(ac1)
    character(len=4), pointer, intent(in) :: ac1(:)
    if (ac1(1) /= "wxyz") call abort()
  end subroutine afoo

end program char_pointer_dummy_test