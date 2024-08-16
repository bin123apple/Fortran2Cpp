program DRB011_minusminus_orig_yes
    use omp_lib
    implicit none

    integer :: i, len, numNodes, numNodes2
    integer :: x(100)
    len = 100
    numNodes=len
    numNodes2=0

    do i = 1, len
        if (MOD(i,2) == 0) then
            x(i) = 5
        else
            x(i) = -5
        end if
    end do

    !$omp parallel do
    do i = numNodes, 1, -1
        if (x(i) <= 0) then
            numNodes2 = numNodes2-1
        end if
    end do
    !$omp end parallel do

    print*,"numNodes2 =", numNodes2
end program
