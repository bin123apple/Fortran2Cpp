program test
  implicit none

contains

  subroutine exampleFunctionC()
    print *, "Function from modC"
  end subroutine exampleFunctionC

  subroutine exampleFunctionD()
    print *, "Function from modD"
  end subroutine exampleFunctionD

  subroutine test_exampleFunctionC()
    call exampleFunctionC()
    print *, "Test for exampleFunctionC passed."
  end subroutine test_exampleFunctionC

  subroutine test_exampleFunctionD()
    call exampleFunctionD()
    print *, "Test for exampleFunctionD passed."
  end subroutine test_exampleFunctionD

end program test