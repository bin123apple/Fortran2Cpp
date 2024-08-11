program test_hello
    call hello
contains
    subroutine hello
        write(*,*) 'Hello SubWorld 2a'
        write(*,'(A)') 'Hello SubWorld 2b'
    end subroutine hello
end program test_hello