program DRB016_outputdep_orig_yes
    use omp_lib
    use globalArray

    implicit none

    integer len, i, x

    len = 100
    x = 10

    call useGlobalArray(len)

    !$omp parallel do
    do i = 1, len
        a(i) = x
        x = i
    end do
    !$omp end parallel do

    write(*,*) "x =",x
end program
