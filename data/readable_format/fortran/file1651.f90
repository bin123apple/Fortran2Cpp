module type_decl
  implicit none
  type fcnparms
    integer :: i
  end type fcnparms
end module type_decl

module test
  use type_decl
  implicit none
contains
  subroutine sim_1(func1, params)
    interface
      function func1(fparams)
        use type_decl
        type(fcnparms) :: fparams
        real :: func1
      end function func1
    end interface
    type(fcnparms) :: params
    ! The subroutine body can be defined here.
  end subroutine sim_1

  subroutine sim_2(func2, params)
    interface
      function func2(fparams)
        use type_decl
        type(fcnparms) :: fparams
        real :: func2
      end function func2
    end interface
    type(fcnparms) :: params
    ! The subroutine body can be defined here.
  end subroutine sim_2
end module test

subroutine sim_3(func3, params)
  use type_decl
  interface
    function func3(fparams)
      use type_decl
      type(fcnparms) :: fparams
      real :: func3
    end function func3
  end interface
  type(fcnparms) :: params
  ! The subroutine body can be defined here.
end subroutine sim_3

program main
  use test
  use type_decl
  implicit none

  type(fcnparms) :: params
  params%i = 10

  ! Define test functions that can be passed to sim_1, sim_2, and sim_3.
  ! You might need to adapt this part based on how you intend to use the functions.

contains

  function test_func(fparams) result(res)
    use type_decl
    type(fcnparms), intent(in) :: fparams
    real :: res

    ! Implement your test function logic here.
    ! For example:
    res = fparams%i * 2.0
  end function test_func

end program main