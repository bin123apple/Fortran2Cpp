module foo_module
  implicit none

  type :: foo
    integer :: bar = 99
  end type foo

contains

  subroutine test_foo_behavior()
    type(foo), allocatable :: foobar(:)
    type(foo), allocatable :: some_local_object(:)
    integer :: i
    logical :: test_passed

    ! Allocate arrays
    allocate(foobar(10))
    allocate(some_local_object(10))

    ! Initialize foobar
    do i = 1, 10
      foobar(i) = foo()
    end do

    ! Copy foobar to some_local_object
    some_local_object = foobar

    ! Test conditions
    test_passed = .true.
    do i = 1, 10
      if (foobar(i)%bar /= 99) then
        test_passed = .false.
        exit
      endif
    end do

    if (.not. test_passed) call abort()

    do i = 1, 10
      if (some_local_object(i)%bar /= 99) then
        test_passed = .false.
        exit
      endif
    end do

    if (.not. test_passed) call abort()

    ! If we reach here, all tests passed
    print *, "Fortran test passed."

    ! Cleanup
    deallocate(foobar)
    deallocate(some_local_object)

  end subroutine test_foo_behavior

end module foo_module

program test
  use foo_module
  call test_foo_behavior()
end program test