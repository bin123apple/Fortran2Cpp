program DRB165_taskdep4_orig_yes_omp_50
    use omp_lib
    implicit none

    !$omp parallel
    !$omp single
    call foo()
    !$omp end single
    !$omp end parallel
contains
    subroutine foo()
        implicit none
        integer :: x, y
        x = 0
        y = 2

        !$omp task depend(inout: x) shared(x)
        x = x+1                                 !!1st Child Task
        !$omp end task

        !$omp task shared(y)
        y = y-1                                 !!2nd child task
        !$omp end task

        !$omp taskwait depend(in: x)            !!1st taskwait

        print*, "x=", x
        print*, "y=", y

        !$omp taskwait                          !!2nd taskwait
    end subroutine foo
end program
