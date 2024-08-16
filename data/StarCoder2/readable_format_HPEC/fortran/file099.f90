program DRB045_doall1_orig_no
    use omp_lib
    implicit none

    integer :: i
    integer :: a(100)

    !$omp parallel do
    do i = 1, 100
        a(i) = a(i)+1
    end do
    !$omp end parallel do

end program
