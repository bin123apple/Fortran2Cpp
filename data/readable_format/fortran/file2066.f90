! File: getcount.f90

subroutine getcount(num, linechars)
    implicit none
    character(len=*), intent(in) :: linechars
    integer, intent(inout) :: num
    integer :: i

    do i = num, 1, -1
        if (linechars(i:i) .ne. ' ') exit
    end do

    if (i == 0) then
        num = -1
    else
        num = i
    endif
end subroutine getcount

program test_getcount
    implicit none
    character(len=60) :: linechars
    integer :: num

    ! Test 1: End of line spaces
    linechars = "Hello, World!            "
    num = len(trim(linechars))
    call getcount(num, linechars)
    print *, "Test 1: Expected 13, Got ", num

    ! Test 2: No trailing spaces
    linechars = "Fortran77Programming"
    num = len(trim(linechars))
    call getcount(num, linechars)
    print *, "Test 2: Expected 20, Got ", num

    ! Test 3: All spaces
    linechars = "                                                            "
    num = len(trim(linechars))
    call getcount(num, linechars)
    print *, "Test 3: Expected -1, Got ", num

    ! Test 4: Empty string
    linechars = ""
    num = len(trim(linechars))
    call getcount(num, linechars)
    print *, "Test 4: Expected -1, Got ", num
end program test_getcount