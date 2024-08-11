module aqq_m
  type :: aqq_t
     logical :: initialized = .false.
  contains
    procedure :: aqq_init
  end type 
 contains
  subroutine aqq_init(this)
    class(aqq_t), intent(inout) :: this
    this%initialized = .true.
    print *, "aqq_t initialized."
  end subroutine
end module

program test_aqq
  use aqq_m
  type(aqq_t) :: aqq

  ! Simulate unit test
  call aqq%aqq_init
  if (aqq%initialized) then
     print *, "Test passed: aqq_t is initialized."
  else
     print *, "Test failed: aqq_t is not initialized."
  endif
end program