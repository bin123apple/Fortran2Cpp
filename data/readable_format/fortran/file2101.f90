program testExample
    implicit none
    integer :: i, sum
    sum = 0
    do i = 1, 10
        sum = sum + i
    end do
    if (sum == 55) then
        print *, 'Test passed. Sum is', sum
    else
        print *, 'Test failed. Sum is', sum
    end if
end program testExample