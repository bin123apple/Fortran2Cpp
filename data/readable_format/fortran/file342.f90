! ExampleModule.f90
module ExampleModule
    implicit none
    contains

    subroutine calc_curvature_gradient()
        print *, "Calculating curvature and gradient..."
        ! This is where the logic of your original subroutine would be.
    end subroutine calc_curvature_gradient
end module ExampleModule

! TestExampleModule.f90
program TestExampleModule
    use ExampleModule
    implicit none

    call TestCalcCurvatureGradient()

contains

    subroutine TestCalcCurvatureGradient()
        call calc_curvature_gradient()
        print *, "TestCalcCurvatureGradient: Test completed."
    end subroutine TestCalcCurvatureGradient

end program TestExampleModule