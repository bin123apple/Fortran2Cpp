module test_module
  use iso_c_binding
  implicit none
contains
  subroutine sub(xxx, yyy)
    integer, target, contiguous :: xxx(:)
    integer, target             :: yyy(:)
    type(c_ptr) :: ptr1, ptr2, ptr3, ptr4

    ptr1 = c_loc (xxx)
    ptr2 = c_loc (xxx(5))
    ptr3 = c_loc (yyy)
    ptr4 = c_loc (yyy(5))

    print *, 'Testing pointers...'
    print *, 'ptr1 should equal ptr3:', c_associated(ptr1, ptr3)
    print *, 'ptr2 should be 4 integers ahead of ptr1:', c_associated(ptr2, c_loc(xxx(5)))
    print *, 'ptr4 should be 4 integers ahead of ptr3:', c_associated(ptr4, c_loc(yyy(5)))
  end subroutine sub
end module test_module

program test
  use test_module
  implicit none
  integer, target :: arr1(10), arr2(10)

  call sub(arr1, arr2)
end program test