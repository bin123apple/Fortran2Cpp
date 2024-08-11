program pr93463
    use omp_lib
    integer :: i, sum
    sum = 0
    !$omp parallel do reduction(+:sum)
    do i = 1, 4
        sum = sum + i
    end do
    print *, "Sum:", sum
end program pr93463