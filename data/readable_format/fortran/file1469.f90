program labelsInSpecifications
    implicit none
    integer :: ioStat
    open(1, file='file.txt', status='replace', iostat=ioStat)
    if (ioStat /= 0) then
        print *, "Failed to open file.txt"
        stop
    end if
    write(1, '(6x, e15.7, 3x, e15.7)', iostat=ioStat) 3.1415927, 3.1415927
    if (ioStat /= 0) then
        print *, "oops"
    else
        print *, "Write successful"
    end if
    close(1)
end program labelsInSpecifications