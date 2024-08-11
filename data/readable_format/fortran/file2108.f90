module evaluation_module
  implicit none

contains

  subroutine initializeEvaluationModule()
    print *, "Evaluation Module Initialized."
  end subroutine initializeEvaluationModule

  function evaluate() result(score)
    integer :: score
    score = 42  ! Hypothetical evaluation result
  end function evaluate

end module evaluation_module

program test_evaluation
  use evaluation_module
  implicit none
  integer :: result

  call initializeEvaluationModule()
  result = evaluate()
  print *, "Evaluation result: ", result

end program test_evaluation