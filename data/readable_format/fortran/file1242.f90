module foo_mod
contains
    subroutine foo(a, i)
        integer, dimension(4,4) :: a
        integer :: i

        where (a(i,1:3) .ne. 0)
            a(i+1,2:4) = 1
        end where
    end subroutine foo
end module foo_mod

program testFoo
    use foo_mod
    implicit none
    integer :: a(4,4), i

    ! Initialize the array 'a' with specific values
    a = reshape((/ 0, 2, 0, 0, &
                    0, 0, 0, 0, &
                    3, 0, 0, 0, &
                    0, 0, 0, 0 /), shape(a))

    ! Test the subroutine with i = 3
    i = 3
    call foo(a, i)

    ! Print the modified array
    print *, 'Modified array:'
    do i = 1, 4
       print *, a(i, :)
    end do
end program testFoo