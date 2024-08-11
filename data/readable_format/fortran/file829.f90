! Define the function in a MODULE
module intcnt_module
    implicit none
contains
    ! Function to count occurrences of an integer in a list
    integer function intCnt(int, list, llist)
        integer, intent(in) :: int
        integer, intent(in) :: list(*)
        integer, intent(in) :: llist
        integer :: i
        
        intCnt = 0
        do i = 1, llist
            if (list(i) == int) then
                intCnt = intCnt + 1
            end if
        end do
    end function intCnt
end module intcnt_module

! The main PROGRAM that uses the MODULE
program testIntCnt
    use intcnt_module  ! Use the module where intCnt function is defined
    implicit none
    integer :: testList(5) = [1, 2, 3, 2, 4]
    integer :: result

    ! Test 1: List with multiple occurrences
    result = intCnt(2, testList, 5)
    write(*,*) 'Test 1: Expecting 2, Got ', result

    ! Test 2: List with no occurrence
    result = intCnt(5, testList, 5)
    write(*,*) 'Test 2: Expecting 0, Got ', result

    ! Test 3: Empty list
    result = intCnt(1, [integer ::], 0)  ! Pass an empty array and size 0
    write(*,*) 'Test 3: Expecting 0, Got ', result
end program testIntCnt