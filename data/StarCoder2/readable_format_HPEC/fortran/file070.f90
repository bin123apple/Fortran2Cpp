program DRB018_plusplus_orig_yes
    use omp_lib
    implicit none

    integer :: i, inLen, outLen
    integer :: input(1000)
    integer :: output(1000)

    inLen = 1000
    outLen = 1

    do i = 1, inLen
        input(i) = i
    end do

    !$omp parallel do
    do i = 1, inLen
        output(outLen) = input(i)
        outLen = outLen + 1
    end do
    !$omp end parallel do

    print 100, output(500)
    100 format ("output(500)=",i3)
end program
