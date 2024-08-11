program main
    implicit none
    integer(kind=8) :: i
    character(len=25) :: l
    integer :: j
    logical :: test_passed

    i = 1
    do j = 1, 63
        i = i * 2
    end do
    write(l, '(Z25)') i  ! Use Z format for hexadecimal conversion

    test_passed = (trim(adjustl(l)) == '8000000000000000')
    if (.not. test_passed) then
        print *, 'Test failed: Expected 8000000000000000 but got', trim(adjustl(l))
    else
        print *, 'Test passed.'
    endif
end program main