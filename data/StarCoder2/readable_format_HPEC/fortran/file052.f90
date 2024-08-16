module DRB127
integer :: tp, var
!$omp threadprivate(tp)
contains
subroutine foo
!$omp task
!$omp task
tp = 1
!$omp task
!$omp end task
var = tp                ! value of var can be 1 or 2
!$omp end task
tp = 2
!$omp end task
end subroutine
end module program DRB127_tasking_threadprivate1_orig_no
    use omp_lib
    use DRB127
    implicit none

    call foo()

end program
