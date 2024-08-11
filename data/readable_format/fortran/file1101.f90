module convolve_mod
    implicit none
contains
    subroutine printHello()
        print *, "Hello from convolve_mod!"
    end subroutine printHello
end module convolve_mod

program testConvolveMod
    use convolve_mod
    implicit none

    call printHello()

end program testConvolveMod