! arrayio_2.f90
program arrayio_2
    implicit none
    integer :: i=2
    character(len=12), dimension(4,2)  :: r
    character(len=80)                  :: f

    r = "0123456789ab" ! Initialize all elements with "0123456789ab"

    f = '("hello"/"world")'
    write(r(1:4,i-1), f) ! Only modifies the first column

    f = '("hello",t1,"HELLO",1x,"!"/"world",tl12,"WORLD")'
    write(r((i-1):(i+1),i), f) ! Modifies rows 1-3 of the second column

    ! Unit test to verify the array content
    if ( r(1,1).ne.'hello       ' .or. &
         r(2,1).ne.'world       ' .or. &
         r(3,1).ne.'0123456789ab' .or. &
         r(4,1).ne.'0123456789ab' .or. &
         r(1,2).ne.'HELLO !     ' .or. &
         r(2,2).ne.'WORLD       ' .or. &
         r(3,2).ne.'0123456789ab' .or. &
         r(4,2).ne.'0123456789ab') then
        print *, "Test failed"
    else
        print *, "Test passed"
    end if
end program arrayio_2