[INST] Translate this Fortran code to C++: 
program remove_duplicates_program
    implicit none
    integer, dimension(:), allocatable :: numbers, result
    integer :: i
    integer, dimension(0) :: empty_array

    ! Test cases
    call assert(issame(remove_duplicates([1, 2, 3, 4]), [1, 2, 3, 4]))
    call assert(issame(remove_duplicates([1, 2, 3, 2, 4, 3, 5]), [1, 4, 5]))
    call assert(issame(remove_duplicates(empty_array), empty_array))

contains

    function remove_duplicates(numbers) result(out)
        integer, dimension(:), intent(in) :: numbers
        integer, dimension(:), allocatable :: out
        integer, dimension(:), allocatable :: has1, has2
        integer :: i, j, num
        logical :: found

        allocate(has1(0))
        allocate(has2(0))
        allocate(out(0))

        if (size(numbers) == 0) return

        do i = 1, size(numbers)
            num = numbers(i)
            found = .false.
            do j = 1, size(has2)
                if (has2(j) == num) then
                    found = .true.
                    exit
                end if
            end do
            if (found) cycle

            found = .false.
            do j = 1, size(has1)
                if (has1(j) == num) then
                    found = .true.
                    exit
                end if
            end do
            if (found) then
                call append(has2, num)
            else
                call append(has1, num)
            end if
        end do

        do i = 1, size(numbers)
            num = numbers(i)
            found = .false.
            do j = 1, size(has2)
                if (has2(j) == num) then
                    found = .true.
                    exit
                end if
            end do
            if (.not. found) then
                call append(out, num)
            end if
        end do
    end function remove_duplicates

    subroutine append(array, value)
        integer, dimension(:), allocatable, intent(inout) :: array
        integer, intent(in) :: value
        integer, dimension(:), allocatable :: temp

        allocate(temp(size(array) + 1))
        temp(1:size(array)) = array
        temp(size(array) + 1) = value
        deallocate(array)
        allocate(array(size(temp)))
        array = temp
    end subroutine append

    function issame(a, b) result(is_equal)
        integer, dimension(:), intent(in) :: a, b
        logical :: is_equal
        integer :: i

        if (size(a) /= size(b)) then
            is_equal = .false.
            return
        end if

        is_equal = .true.
        do i = 1, size(a)
            if (a(i) /= b(i)) then
                is_equal = .false.
                exit
            end if
        end do
    end function issame

    subroutine assert(condition)
        logical, intent(in) :: condition
        if (.not. condition) then
            write(*,*) "Assertion failed"
            call exit(1)
        end if
    end subroutine assert

end program remove_duplicates_program [/INST]

[INST] Translate this Fortran code to C++: 
program remove_duplicates_program
    implicit none
    integer, dimension(:), allocatable :: numbers, result
    integer :: i
    integer, dimension(0) :: empty_array

    ! Test cases
    call assert(issame(remove_duplicates([1, 2, 3, 4]), [1, 2, 3, 4]))
    call assert(issame(remove_duplicates([1, 2, 3, 2, 4, 3, 5]), [1, 4, 5]))
    call assert(issame(remove_duplicates(empty_array), empty_array))

contains

    function remove_duplicates(numbers) result(out)
        integer, dimension(:), intent(in) :: numbers
        integer, dimension(:), allocatable :: out
        integer, dimension(:), allocatable :: has1, has2
        integer :: i, j, num
        logical :: found

        allocate(has1(0))
        allocate(has2(0))
        allocate(out(0))

        if (size(numbers) == 0) return

        do i = 1, size(numbers)
            num = numbers(i)
            found = .false.
            do j = 1, size(has2)
                if (has2(j) == num) then
                    found = .true.
                    exit
                end if
            end do
            if (found) cycle

            found = .false.
            do j = 1, size(has1)
                if (has1(j) == num) then
                    found = .true.
                    exit
                end if
            end do
            if (found) then
                call append(has2, num)
            else
                call append(has1, num)
            end if
        end do

        do i = 1, size(numbers)
            num = numbers(i)
            found = .false.
            do j = 1, size(has2)
                if (has2(j) == num) then
                    found = .true.
                    exit
                end if
            end do
            if (.not. found) then
                call append(out, num)
            end if
        end do
    end function remove_duplicates

    subroutine append(array, value)
        integer, dimension(:), allocatable, intent(inout) :: array
        integer, intent(in) :: value
        integer, dimension(:), allocatable :: temp

        allocate(temp(size(array) + 1))
        temp(1:size(array)) = array
        temp(size(array) + 1) = value
        deallocate(array)
        allocate(array(size(temp)))
        array = temp
    end subroutine append

    function issame(a, b) result(is_equal)
        integer, dimension(:), intent(in) :: a, b
        logical :: is_equal
        integer :: i

        if (size(a) /= size(b)) then
            is_equal = .false.
            return
        end if

        is_equal = .true.
        do i = 1, size(a)
            if (a(i) /= b(i)) then
                is_equal = .false.
                exit
            end if
        end do
    end function issame

    subroutine assert(condition)
        logical, intent(in) :: condition
        if (.not. condition) then
            write(*,*) "Assertion failed"
            call exit(1)
        end if
    end subroutine assert

end program remove_duplicates_program [/INST]

[INST] Translate this Fortran code to C++: 
program remove_duplicates_program
    implicit none
    integer, dimension(:), allocatable :: numbers, result
    integer :: i
    integer, dimension(0) :: empty_array

    ! Test cases
    call assert(issame(remove_duplicates([1, 2, 3, 4]), [1, 2, 3, 4]))
    call assert(issame(remove_duplicates([1, 2, 3, 2, 4, 3, 5]), [1, 4, 5]))
    call assert(issame(remove_duplicates(empty_array), empty_array))

contains

    function remove_duplicates(numbers) result(out)
        integer, dimension(:), intent(in) :: numbers
        integer, dimension(:), allocatable :: out
        integer, dimension(:), allocatable :: has1, has2
        integer :: i, j, num
        logical :: found

        allocate(has1(0))
        allocate(has2(0))
        allocate(out(0))

        if (size(numbers) ==
