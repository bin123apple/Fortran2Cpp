program testProgram
    implicit none
    character(len=80) :: s

    call test(s)
    if (s(1:11) == "Hello World") then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program testProgram

subroutine test(s)
    character(len=80) :: s
    s = "Hello World"
end subroutine test