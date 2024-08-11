program test
    character*25 l
    integer(kind=8) i
    data i /1/
    do j = 1,63
       i = i * 2
    end do
    write(l,*)i
    if (l.eq.' -9223372036854775808') then
       print *, 'Test Passed'
    else
       print *, 'Test Failed'
    endif 
end program test