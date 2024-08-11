program MainProgram
    implicit none

    ! Declaration of variables for testing purposes
    real :: testValue

    ! Example usage of the internal modules
    call setExecutionData(1, 0)
    call setAtomData('He', 2.0)
    testValue = 3.14
    call setGaussianBasisData(testValue)

    ! Add more function calls or tests as needed

contains

    ! Internal modules converted to procedures for demonstration

    subroutine setExecutionData(doCharge, doVis)
        integer, intent(in) :: doCharge, doVis
        print *, "Execution Data: Charge: ", doCharge, " Visibility: ", doVis
    end subroutine setExecutionData

    subroutine setAtomData(elementName, atomicNumber)
        character(len=*), intent(in) :: elementName
        real, intent(in) :: atomicNumber
        print *, "Atom Data: Element Name: ", elementName, " Atomic Number: ", atomicNumber
    end subroutine setAtomData

    subroutine setGaussianBasisData(value)
        real, intent(in) :: value
        print *, "Gaussian Basis Data: Value: ", value
    end subroutine setGaussianBasisData

    ! Define additional subroutines for other data manipulation here,
    ! based on the modules provided in the original question.

end program MainProgram