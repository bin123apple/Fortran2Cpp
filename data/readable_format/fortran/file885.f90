program test_my_module
  implicit none
  type :: t
  end type t

  type, extends(t) :: t2
  end type t2

  class(t), allocatable :: a, b, c
  class(t), allocatable :: a2(:), b2(:), c2(:)
  logical :: testPassed
  
  ! Allocate and test the functionality
  allocate (t2 :: a)
  allocate (t2 :: a2(5))
  call move_alloc (from=a, to=b)
  call move_alloc (from=a2, to=b2)
  
  testPassed = .true.
  testPassed = testPassed .and. (allocated(b))
  testPassed = testPassed .and. (allocated(b2))
  testPassed = testPassed .and. (size(b2) == 5)
  
  ! Use the standard Fortran intrinsic SELECTED_CHAR_KIND to avoid unnecessary complexity
  if (.not. same_type_as_scalar(a,c) .or. same_type_as_scalar(a,b)) testPassed = .false.
  if (.not. same_type_as_array(a2,c2) .or. same_type_as_array(a2,b2)) testPassed = .false.
  
  if (testPassed) then
    print *, "All tests passed successfully."
  else
    print *, "Some tests failed."
  end if
  
contains

  function same_type_as_scalar(a, b) result(res)
    class(t), intent(in) :: a, b
    logical :: res

    res = same_type(a, b)
  end function same_type_as_scalar

  function same_type_as_array(a, b) result(res)
    class(t), dimension(:), intent(in) :: a, b
    logical :: res

    res = same_type(a(1), b(1))
  end function same_type_as_array

  function same_type(a, b) result(res)
    class(t), intent(in) :: a, b
    logical :: res
    
    res = .false.
    select type(a => a)
    type is (t)
      select type(b => b)
      type is (t)
        res = .true.
      class default
      end select
    class default
    end select
  end function same_type

end program test_my_module