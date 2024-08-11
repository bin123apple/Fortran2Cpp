module c_ptr_tests_9
  use, intrinsic :: iso_c_binding, only: c_ptr, c_null_ptr

  type myF90Derived
     type(c_ptr) :: my_c_ptr
  end type myF90Derived

contains
  subroutine sub0() bind(c)
    type(myF90Derived), target :: my_f90_type
    type(myF90Derived), pointer :: my_f90_type_ptr

    my_f90_type%my_c_ptr = c_null_ptr
    print *, 'my_f90_type is: ', my_f90_type%my_c_ptr
    my_f90_type_ptr => my_f90_type
    print *, 'my_f90_type_ptr is: ', my_f90_type_ptr%my_c_ptr
  end subroutine sub0
end module c_ptr_tests_9

program main
  use c_ptr_tests_9
  implicit none

  call sub0()

end program main