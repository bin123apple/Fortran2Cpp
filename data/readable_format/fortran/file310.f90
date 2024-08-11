module findMaxMod
    implicit none
contains
    function findMax(A, N) result(BIGA)
        double precision, intent(in) :: A(:)
        integer, intent(in) :: N
        double precision :: BIGA
        integer :: i

        ! Assume the first element is the max by default
        BIGA = A(1)
        
        ! If the array is empty, return a special value
        if (N <= 0) then
            BIGA = -1.0e30  ! Assuming this is an acceptable stand-in for NaN
            return
        end if

        do i = 2, N
            if (BIGA < A(i)) then
                BIGA = A(i)
            end if
        end do
    end function findMax
end module findMaxMod

program testFindMax
    use findMaxMod
    implicit none
    double precision, allocatable :: A(:)
    double precision :: result

    ! Test empty array
    allocate(A(0))
    result = findMax(A, size(A))
    print *, "Empty Array Test: ", result

    ! Test identical elements
    allocate(A(4))
    A = 1
    result = findMax(A, size(A))
    print *, "Identical Elements Test: ", result

    ! Test distinct elements
    A = [-2, -1, 0, 1, 2]
    result = findMax(A, size(A))
    print *, "Distinct Elements Test: ", result

    ! Test all negative numbers
    A = [-10, -20, -30, -40]
    result = findMax(A, size(A))
    print *, "All Negative Numbers Test: ", result

end program testFindMax