program main
    implicit none
    character(len=10), dimension(10) :: string
    character(len=5), dimension(10) :: substring
    integer :: i

    ! Initialize strings for testing
    string(1) = "abcdefghij"
    string(2) = "klmnopqrst"

    ! Perform the operation
    substring(1:2) = string(1:2)(2:6)

    ! Unit test to verify the operation
    do i = 1, 2
        if (substring(i) == string(i)(2:6)) then
            print *, "Test", i, "passed."
        else
            print *, "Test", i, "failed."
        end if
    end do
end program main