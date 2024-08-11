module my_subroutines
    implicit none
contains
    subroutine foo(arr)
        double precision, intent(inout) :: arr(:,:)
        arr(3, 4) = 24
    end subroutine foo

    subroutine bar(arr)
        double precision, intent(inout) :: arr(:,:)
        call foo(arr)
        ! Assuming the intent here is to affect the original array,
        ! there's no need to slice it as it's already passed by reference.
        call foo(arr)
    end subroutine bar
end module my_subroutines

program test
    use my_subroutines
    implicit none
    double precision :: arr(5, 8)
    call bar(arr)
    if (arr(3, 4) == 24) then
        print *, "Test passed."
    else
        print *, "Test failed."
    endif
end program test