module DRB128
integer :: tp, var
!$omp threadprivate(tp)
contains
subroutine foo
!$omp task
!$omp task
tp = 1
!$omp task
!$omp end task
var = tp
!$omp end task
!$omp end task
end subroutine
end module program DRB128_tasking_threadprivate2_orig_no
    use omp_lib
    use DRB128
    implicit none

    call foo()
    print*,var
end program
