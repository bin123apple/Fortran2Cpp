subroutine example
    implicit none

    return
end subroutine example

program test_example
    implicit none

    call example()

    print *, 'The subroutine was called successfully.'

end program test_example