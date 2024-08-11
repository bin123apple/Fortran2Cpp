program test_prog
    implicit none
    integer :: num
    character(len=10) :: buffer
    integer :: ios

    common /com/ num
    data num /3/
    
    open(unit=10, file='output.txt', status='replace')
    write(10, '(I10)') num
    close(10)

    open(unit=10, file='output.txt', status='old', action='read')
    read(10, '(I10)', iostat=ios) num
    close(10)

    if (ios /= 0) then
        print *, 'Test Failed: Error reading output file.'
    elseif (num /= 3) then
        print *, 'Test Failed: Expected 3, but got ', num
    else
        print *, 'Test Passed: Output is correct.'
    end if
end program test_prog