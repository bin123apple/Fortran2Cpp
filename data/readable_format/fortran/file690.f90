module type_decl
  implicit none
  type :: fcnparms
    integer :: i
  end type fcnparms
end module type_decl

module test
  use type_decl
  implicit none
contains
  subroutine sim_1(func1, params)
    interface
      function func1(fparams) result(res)
        use type_decl
        type(fcnparms), intent(in) :: fparams
        real :: res
      end function func1
    end interface
    type(fcnparms), intent(in) :: params
    print *, 'Calling sim_1 with i =', params%i
    print *, 'Result from func1:', func1(params)
  end subroutine sim_1

  subroutine sim_2(func2, params)
    interface
      function func2(fparams) result(res)
        use type_decl
        type(fcnparms), intent(in) :: fparams
        real :: res
      end function func2
    end interface
    type(fcnparms), intent(in) :: params
    print *, 'Calling sim_2 with i =', params%i
    print *, 'Result from func2:', func2(params)
  end subroutine sim_2
end module test

module func_module
  use type_decl
  implicit none
contains
  function exampleFunc(fparams) result(res)
    type(fcnparms), intent(in) :: fparams
    real :: res
    res = fparams%i * 2.0  ! Simple example function
  end function exampleFunc
end module func_module

subroutine sim_3(func3, params)
  use type_decl
  interface
    function func3(fparams) result(res)
      use type_decl
      type(fcnparms), intent(in) :: fparams
      real :: res
    end function func3
  end interface
  type(fcnparms), intent(in) :: params
  print *, 'Calling sim_3 with i =', params%i
  print *, 'Result from func3:', func3(params)
end subroutine sim_3

program testProgram
  use test
  use type_decl
  use func_module
  implicit none
  
  type(fcnparms) :: params
  params%i = 10

  call sim_1(exampleFunc, params)
  call sim_2(exampleFunc, params)
  call sim_3(exampleFunc, params)
end program testProgram