module memcf6_module
    implicit none
    contains

    subroutine memcf6(backfl, mask, back, pixsol, ierr)
        real, dimension(:), intent(in) :: mask, back
        real, intent(out) :: backfl
        real, intent(in) :: pixsol
        integer, intent(inout) :: ierr
        integer :: pixel
        real :: sum

        if(ierr.ne.0) return
        sum=0.0
        do pixel=1,size(mask)
            sum=sum+mask(pixel)*back(pixel)
        enddo
        backfl=sum*pixsol
    end subroutine memcf6
end module memcf6_module

program testMemcf6
    use memcf6_module
    implicit none
    real, dimension(5) :: mask = [1.0, 2.0, 3.0, 4.0, 5.0]
    real, dimension(5) :: back = [2.0, 2.0, 2.0, 2.0, 2.0]
    real :: backfl, pixsol
    integer :: ierr

    ! Test 1: Normal operation
    ierr = 0
    pixsol = 2.0
    call memcf6(backfl, mask, back, pixsol, ierr)
    print *, 'Test 1: backfl should be 60.0. Result:', backfl

    ! Reset backfl for next test
    backfl = 0.0

    ! Test 2: Error handling
    ierr = 1
    call memcf6(backfl, mask, back, pixsol, ierr)
    print *, 'Test 2: With ierr=1, backfl should remain 0.0. Result:', backfl

end program testMemcf6