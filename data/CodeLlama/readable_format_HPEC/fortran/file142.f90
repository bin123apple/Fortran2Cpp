module DRB106
    implicit none
    integer (kind=4) input

contains
    recursive function fib(n) result(r)
        use omp_lib
        implicit none
        integer (kind=4) :: n, i, j, r

        if (n<2) then
            r = n
        else
            !$omp task shared(i)
            i = fib(n-1)
            !$omp end task
            !$omp task shared(j)
            j = fib(n-2)
            !$omp end task
            r = i+j
        end if
        !$omp taskwait
    end function
end module

program DRB106_taskwaitmissing_orig_yes
    use omp_lib
    use DRB106
    implicit none

    integer :: result
    input = 30

    !$omp parallel
    !$omp single
    result = fib(input)
    !$omp end single
    !$omp end parallel

    print*,'Fib for ',input,' =',result

end program
