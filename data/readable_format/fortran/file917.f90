module ModExample2

  implicit none
  private
  public :: example_iroutine
  character(len=*), parameter :: NameMod = 'ModExample2'

contains

  subroutine example_iroutine(InputVar, OutputVar, InputOutputVar)

    ! Assuming ExampleParameter is a real number for demonstration purposes
    real, parameter :: ExampleParameter = 1.0

    real, intent(in) :: InputVar
    real, intent(out) :: OutputVar
    real, intent(inout) :: InputOutputVar

    real :: AnImportantLocalVariable

    character(len=*), parameter :: NameSub = NameMod//'::example_iroutine'

    write(*,*) NameSub,': documented executable statements come here'
    write(*,*) NameSub,': this part should not appear in the documentation'

    ! Example computation to demonstrate functionality
    AnImportantLocalVariable = InputVar * ExampleParameter
    OutputVar = AnImportantLocalVariable * 2.0
    InputOutputVar = InputOutputVar * 3.0

  end subroutine example_iroutine

end module ModExample2

! Test program or another subroutine that uses the module
program testModExample2
  use ModExample2
  implicit none

  real :: InputVar = 10.0
  real :: OutputVar
  real :: InputOutputVar = 5.0

  call example_iroutine(InputVar, OutputVar, InputOutputVar)

  write(*,*) 'OutputVar after subroutine call:', OutputVar
  write(*,*) 'InputOutputVar after subroutine call:', InputOutputVar

end program testModExample2