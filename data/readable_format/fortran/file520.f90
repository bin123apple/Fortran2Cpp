module modphonon
    implicit none
    integer :: nbph = 0
    real(8), allocatable :: vqlwrt(:,:)

    contains
    
    subroutine increase_nbph()
        nbph = nbph + 1
    end subroutine increase_nbph

end module modphonon

program test_modphonon
    use modphonon
    implicit none

    ! Initialize module variables
    nbph = 5
    allocate(vqlwrt(2,2))
    vqlwrt = reshape([1.0d0, 2.0d0, 3.0d0, 4.0d0], shape(vqlwrt))

    print *, 'Initial nbph:', nbph
    call increase_nbph()
    print *, 'After subroutine call, nbph:', nbph

    ! Assertions / Checks for vqlwrt
    if (all(vqlwrt == reshape([1.0d0, 2.0d0, 3.0d0, 4.0d0], shape(vqlwrt)))) then
        print *, "vqlwrt test passed."
    else
        print *, "vqlwrt test failed."
    endif

    ! Clean up
    deallocate(vqlwrt)
end program test_modphonon